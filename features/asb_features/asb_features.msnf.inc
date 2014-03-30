<?php
/**
 * @file
 * asb_features.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function asb_features_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_2_private_description|node|scheme';
  $msnf->step_name = 'step_2_private_description';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Step 2 - Private Description',
    'weight' => '1',
    'children' => array(
      0 => 'field_private_description',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 2 - Private Description',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => 'step-2 scheme-private-description',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_2_private_description|node|scheme'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_3_public_desc_and_sum|node|scheme';
  $msnf->step_name = 'step_3_public_desc_and_sum';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Step 3 - Summary',
    'weight' => '2',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 3 - Summary',
      'instance_settings' => array(
        'skip_non_required' => 0,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => 'Replace this text with a brief (status update/tweet length) public summary',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_3_public_desc_and_sum|node|scheme'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_4_media|node|scheme';
  $msnf->step_name = 'step_4_media';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Step 4 - Media',
    'weight' => '3',
    'children' => array(
      0 => 'field_video',
      1 => 'field_image',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 4 - Media',
      'instance_settings' => array(
        'skip_non_required' => 0,
        'hide_if_empty' => 0,
        'classes' => 'step-4 scheme-media',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_4_media|node|scheme'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_5_needs|node|scheme';
  $msnf->step_name = 'step_5_needs';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Step 5 - Needs',
    'weight' => '4',
    'children' => array(
      0 => 'field_material_needs',
      1 => 'field_people_skills',
      2 => 'field_funding_needs',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 5 - Needs',
      'instance_settings' => array(
        'skip_non_required' => 0,
        'hide_if_empty' => 0,
        'classes' => 'step-5 scheme-needs',
        'description' => 'What do you need to make your project happen? A graphic designer? A video camera? $500? Forty trench coats? List those needs here so schemers can volunteer to help out.',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_5_needs|node|scheme'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_6_assign_issues_goals|node|scheme';
  $msnf->step_name = 'step_6_assign_issues_goals';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Step 6 - Choose Issue and Goals',
    'weight' => '5',
    'children' => array(
      0 => 'field_issues_goals',
      1 => 'field_location',
      2 => 'field_scheme_goals_taxonomy',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 6 - Choose Issue and Goals',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => 'step-6 assign-issues',
        'description' => 'Connecting your scheme to a specific goal will help like-minded activists find you. Goals are organized under larger issue areas. Please choose the most specific Goal you can find for your scheme. If you don’t see a Goal that makes sense, leave it blank and recommend a goal to your facilitator later.',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_6_assign_issues_goals|node|scheme'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_add_title_and_description|node|scheme';
  $msnf->step_name = 'step_add_title_and_description';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'scheme';
  $msnf->data = array(
    'label' => 'Create a Scheme',
    'weight' => '0',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Create a Scheme',
      'instance_settings' => array(
        'skip_non_required' => 0,
        'hide_if_empty' => 0,
        'classes' => 'title-description',
        'description' => '<p><strong>Step 1 Title </strong></p>
<p><strong>So you want to create a scheme…</strong></p>
<p>In this process, you\'ll be asked for the following things: </p>

<ul>
<li>A detailed explanation of what it is you are scheming, for trusted eyes only.</li>
<li>A general description that you’d like to share publicly to entice people to join your scheme. </li>
<li>Any photos and/or a video you’d like to use, also to entice collaborators. (one photo is required to get started, but you can add others and the video later) </li>
<li>A list of the people, supplies, and funding you\'ll need for your scheme.</li>
</ul>

<p>So, let\'s get started!</p>
<p>Tell us the name that will represent your scheme around the Action Switchboard. Make it enticing, but don’t give away anything too secret...</p>',
        'show_label' => '0',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip This Step',
        ),
      ),
    ),
  );
  $export['step_add_title_and_description|node|scheme'] = $msnf;

  return $export;
}
