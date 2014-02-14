<?php

/**
 * Ofile
 * Administrative page callbacks for the canned_email module.
 */

/**
 * General configuration options for canned_email behavior.
 */
function canned_email_admin_settings() {
  $form['canned_email_header_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Mail Headers'),
  );
  $form['canned_email_header_settings']['canned_email_ccbcc'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose Header'),
    '#options' => array(
      'cc' => 'Cc',
      'bcc' => 'Bcc',
    ),
    '#default_value' => variable_get('canned_email_ccbcc', array()),
    '#ajax' => array(
      'event' => 'change',
      'wrapper' => 'canned-email-settings-wrapper',
      'callback' => 'canned_email_settings_ajax_callback',
      'method' => 'append',
    ),
    '#prefix' => '<div id="canned-email-settings-wrapper">',
    '#suffix' => '</div>',
  );
  $form['canned_email_header_settings']['ccheader'] = array(
    '#type' => 'fieldset',
    '#title' => 'Cc ' .t('Settings'),
    '#states' => array(
      'visible' => array(
        ':input[name="canned_email_ccbcc[cc]"]' => array('checked' => TRUE)
      ),
      'invisible' => array(
        ':input[name="canned_email_ccbcc[cc]"]' => array('checked' => FALSE)
      ),
    )
  );
  $form['canned_email_header_settings']['ccheader']['canned_email_cc_on_form'] = array(
    '#type' => 'radios',
    '#title' => t('Enable Cc field on forms'),
    '#options' => array(
      0 => t('Hidden'),
      1 => t('Show and allow editing'),
    ),
    '#default_value' => variable_get('canned_email_cc_on_form', 0),
    '#description' => t('Control how the Carbon Copy email address is handled on mailing forms.  If choosing the hide option, include a default address below.'),
  );
  $form['canned_email_header_settings']['ccheader']['canned_email_cc_default_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Cc Email'),
    '#default_value' => variable_get('canned_email_cc_default_email', ''),
    '#description' => t('The default email address to carbon copy the email to.'),
  );

  $form['canned_email_header_settings']['bccheader'] = array(
    '#type' => 'fieldset',
    '#title' => 'Bcc ' .t('Settings'),
    '#states' => array(
      'visible' => array(
        ':input[name="canned_email_ccbcc[bcc]"]' => array('checked' => TRUE)
      ),
      'invisible' => array(
        ':input[name="canned_email_ccbcc[bcc]"]' => array('checked' => FALSE)
      ),
    )
  );
  $form['canned_email_header_settings']['bccheader']['canned_email_bcc_on_form'] = array(
    '#type' => 'radios',
    '#title' => t('Enable Bcc field on forms'),
    '#options' => array(
      0 => t('Hidden'),
      1 => t('Show and allow editing'),
    ),
    '#default_value' => variable_get('canned_email_bcc_on_form', 0),
    '#description' => t('Control how the blind copy email address is handled on mailing forms.  If choosing the hide option, include a default address below.'),
  );
  $form['canned_email_header_settings']['bccheader']['canned_email_bcc_default_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Bcc Email'),
    '#default_value' => variable_get('canned_email_bcc_default_email', ''),
    '#description' => t('The default email address to blind copy the email to.'),
  );

  $form['canned_email_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose content types'),
  );
  $form['canned_email_types']['canned_email_content_types'] = array(
    '#type' => 'select',
    '#title' => t('Choose content with email links'),
    '#default_value' => variable_get('canned_email_content_types', array()),
    '#options' => canned_email_get_types(),
    '#multiple' => TRUE,
  );
  $form['canned_email_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on user page?'),
    '#default_value' => variable_get('canned_email_user', 0),
    '#description' => t('Choose whether or not to show the email tab on user profile pages.'),
  );
  $node_types = node_type_get_types();
  return system_settings_form($form);
}

function canned_email_get_types() {
  $node_types = node_type_get_types();
  $options = array();
  foreach($node_types as $type => $node) {
    $options[$type] = $node->name;
  }
  return $options;
}

function canned_email_settings_ajax_callback($form, &$form_state) {
//  return dsm($form['canned_email_header_settings']['canned_email_ccbcc']['#value']);
  /*  if($form['canned_email_header_settings']['canned_email_ccbcc']['#value']['bcc'] == 'bcc') { */
  /*    // return dsm($form['canned_email_header_settings']['canned_email_ccbcc']['#value']); */
  /*   $form['canned_email_header_settings']['header']['#access'] = TRUE; */
  /*   return $form['canned_email_header_settings']['header']['canned_email_bcc_on_form']; */
  /* } */

}
