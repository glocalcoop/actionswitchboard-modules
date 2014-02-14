<?php

/**
 * Menu callback: presents canned email form
 */
function canned_email_emails() {
  $node = node_load(arg(1));
  $user = user_load($node->uid);
  drupal_set_title('<em>Send Canned Email to '.$user->name.'</em>', PASS_THROUGH);
  return drupal_get_form('canned_email_form');
}

/**
 * Ofile
 * Page callbacks for the canned_email module.
 */

function canned_email_form($form, &$form_state) {
  global $user;
  if(arg(0) == 'node') {
    $form_state['nid'] = arg(1);
  }
  $form['available_canned_emails'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose from Canned Emails'),
    '#weight' => -1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#prefix' => '<div id="available-canned-emails-wrapper">',
    '#suffix' => '</div>',
  );
  $form['available_canned_emails']['canned_email_choices'] = array(
    '#type' => 'select',
    '#title' => t('Select a Mailing'),
    '#weight' => 0,
    '#options' => canned_email_get_mailings(),
    '#ajax' => array(
      'event' => 'change',
      'wrapper' => array('subject-ajax-wrapper','body-ajax-wrapper'),
      'callback' => 'canned_email_sort_ajax_callback',
      'method' => 'replace',
    ),
  );
  $form['available_canned_emails']['mailer_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email Content'),
    '#collabsible' => FALSE,
  );
  $form['available_canned_emails']['mailer_set']['canned_email_subjects'] = array( 
    '#type' => 'textfield',
    '#title' => t('Canned Email Subject'),
    '#prefix' => '<div id="subject-ajax-wrapper">',
    '#suffix' => '</div>',
  );
  $form['available_canned_emails']['mailer_set']['canned_email_bodies'] = array(  
    '#type' => 'textarea',
    '#title' => t('Canned Email Body'),
    '#rows' => 10,
    '#prefix' => '<div id="body-ajax-wrapper">',
    '#suffix' => '</div>',
  );
  $form['available_canned_emails']['canned_email_send_button'] = array(
    '#type' => 'button',
    '#value' => t('Insert this email text'),
    '#limit_validation_errors' => array(),
    '#ajax' => array(
      'event' => 'click',
      'wrapper' => 'canned-email-insert-wrapper',
      'callback' => 'canned_email_insert_ajax_callback',
      'method' => 'replace',
    ),
  );
  $form['email_to'] = array(
    '#type' => 'textfield',
    '#title' => t('To:'),
    '#default_value' => canned_email_get_author(),
    '#required' => TRUE,
    '#attributes' => array(
      'readonly' => TRUE,
    ),
  );
  $form['email_from'] = array(
    '#type' => 'textfield',
    '#title' => t('From:'),
    '#default_value' => $user->mail,
    '#required' => TRUE,
  );
  $form['email_cc'] = array(
    '#type' => 'textfield',
    '#title' => 'Cc:',
    '#access' => FALSE,
  );
  $form['email_bcc'] = array(
    '#type' => 'textfield',
    '#title' => 'Bcc:',
    '#access' => FALSE,
  );
  $form['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject:'),
    '#required' => TRUE,
    '#prefix' => '<div id="email-subject-ajax-wrapper">',
    '#suffix' => '</div>',
  );
  $form['email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body:'),
    '#rows' => 10,
    '#required' => TRUE,
    '#prefix' => '<div id="email-body-ajax-wrapper">',
    '#suffix' => '</div>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Send email',
  );
  return $form;
}

function canned_email_form_validate($form, &$form_state) {
  if(!valid_email_address($form_state['values']['email_to'])) {
    form_set_error('email_to',"Oops! The email address to the user failed validation! Check the address and try again.");
  }
  if(!valid_email_address($form_state['values']['email_from'])) {
    form_set_error('email_from',"Mmm... It seems that your email address failed validation. Please make sure it's correct and try again.");
  }
}

/**
 * Implements hook_form_alter().
 *
 * Here we run settings checks against the form.
 */
function canned_email_form_alter(&$form, &$form_state, $form_id) {
  // Run access checks against cc and bcc fields
  // to determine if they should be visible and/or populated
  if($form_id == 'canned_email_form') {
    $heads = variable_get('canned_email_ccbcc');
    foreach($heads as $key => $type) {
      if($type !== 0) {
        if(variable_get('canned_email_'.$type.'_on_form') == 1) {
          $form['email_'.$type]['#default_value'] = variable_get('canned_email_'.$type.'_default_email');
          $form['email_'.$type]['#access'] = TRUE;
        }else{
          $form['email_'.$type]['#value'] = variable_get('canned_email_'.$type.'_default_email');
        }
      }
    }
  }
}

/**
 * Implements hook_form_submit().
 */
function canned_email_form_submit($form, &$form_state) {
  $path = current_path();
  $dir = explode('/', $path);
  $form_state['redirect'] = $dir[0] .'/' .$dir[1];
  canned_email_node_mail_send($form_state['values']);
}

/**
 * Implements hook_mail()
 */
function canned_email_mail($key, &$message, $params) {
  $options = array(
    'langcode' => $message['language']->language,
  );
  switch ($key) {
    case 'node_message':
      $message['headers'] += $params['headers'];
      $message['subject'] = $params['subject'];
      // Create the body of the message and  strip html.
      $message['body'][] = check_plain($params['message']);
      break;
  }
}

/**
 * Sends email from node form
 * 
 * @param $form_values
 * An array of values from the node email form.
 */
function canned_email_node_mail_send($form_values) {
//  dsm($form_values);
  // Specify the module and the key
  $module = 'canned_email';
  $key = 'node_message';
  // Specify to, from, cc and bcc addresses
  $to = $form_values['email_to'];
  $from = $form_values['email_from'];
  if(variable_get('canned_email_bcc_on_form') == 1) {
    $bcc = variable_get('canned_email_bcc_default_email', '');
    // set the bcc value
    $params['headers']['Bcc'] = $bcc;
  }
  if(variable_get('canned_email_cc_on_form') == 0) {
    $cc = variable_get('canned_email_cc_default_email', '');
    $params['headers']['Cc'] = $cc;
  }
  // set $params based on form input
  $params['subject'] = $form_values['email_subject'];
  $params['message'] = $form_values['email_body'];
  // set the language
  $language = language_default();
  // ensure send is true
  $send = TRUE;
  // Now we send the email
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  // dsm($params);
  // Make sure the email successfully sent
  if($result['result'] = TRUE) {
    drupal_set_message(t('The email was sent.'));
  }else{
    drupal_set_message(t('There was a problem sending the email and it was not sent.'), 'error');
  }
}

/**
 * Return a list of canned email entities.
 */
function canned_email_get_mailings() {
  // Get all canned email entities and
  // add them to the list of options
  $query = new EntityFieldQuery;
  $results = $query
    ->entityCondition('entity_type', 'canned_email')
    ->entityCondition( 'ceid', '>', 0)
    ->execute();
  foreach($results['canned_email'] as $key => $value) {
    $ceids[] = $value->ceid;
  }
  $entities = canned_email_load_multiple($ceids);
  $options = array();
  $options[0] = "- Select Canned Email -";
  foreach($entities as $id => $ce) {
    $options[$ce->ceid] = $ce->name;
  }
  return $options;
}

/**
 * Replace the body text with the correct
 * text based on the canned email selection.
 *
 * This function uses ajax_command_replace to
 * act on two fields on the same callback.
 */
function canned_email_sort_ajax_callback(&$form, &$form_state) {
  global $user;
  $node = node_load($form_state['nid']);
  // Load the canned email from the selected value.
  $cemail = canned_email_load($form['available_canned_emails']['canned_email_choices']['#value']);
  // Set subject and body based on retrieved entity values
  $form['available_canned_emails']['mailer_set']['canned_email_subjects']['#value'] = $cemail->email_subject;
  // We add token replacements for the canned emails
  $form['available_canned_emails']['mailer_set']['canned_email_bodies']['#value'] = token_replace($cemail->email_body, array('node' => $node, 'user' => $user));
  $commands = array(
  '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace("#subject-ajax-wrapper", render($form['available_canned_emails']['mailer_set']['canned_email_subjects'])),
      ajax_command_replace("#body-ajax-wrapper", render($form['available_canned_emails']['mailer_set']['canned_email_bodies']))
    ),
  );
  return $commands;
  // return $form['available_canned_emails']['canned_email_subjects'];
}

/**
 * Insert current canned email text into real email body
 */
function canned_email_insert_ajax_callback(&$form, &$form_state) {
  $form['available_canned_emails']['#collapsed'] = TRUE;
  $form['email_subject']['#value'] = $form['available_canned_emails']['mailer_set']['canned_email_subjects']['#value'];
  $form['email_body']['#value'] = $form['available_canned_emails']['mailer_set']['canned_email_bodies']['#value'];
  $commands = array(
  '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace("#email-subject-ajax-wrapper", render($form['email_subject'])),
      ajax_command_replace("#email-body-ajax-wrapper", render($form['email_body'])),
      ajax_command_replace("#available-canned-emails-wrapper", render($form['available_canned_emails'])),
    ),
  );

  return $commands;
}

/**
 * Add the author email as the default email.
 */
function canned_email_get_author() {
  $node = node_load(arg(1));
  $user = user_load($node->uid);
  return $user->mail;
}
