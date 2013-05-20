<?php
/**
 * @file
 * Common settings for Gigya. hans.gutknecht@mlssoccer.com
 * gigya_top_streams
 */
function gigya_top_streams_form() {
  $form = array();

  $form['gigya_top_streams_categoryID'] = array(
    '#title' => t('Comments Category ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_categoryID', ''),
    '#description' => t('The identifier of the comments category from which to retrieve the top streams. If this parameter is not specified, the method returns the top streams for all categories'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_item_count'] = array(
    '#title' => t('Item Count'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_item_count', '10'),
    '#description' => t('The maximum number of streams to display. The default is 10 streams. The maximum is 100.'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_streams_requested_count'] = array(
    '#title' => t('Streams Requested Count'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_streams_requested_count', '100'),
    '#description' => t('The maximum number of streams to retrieve from Gigya. The default and maximum is 100 streams.'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_maxStreamAge'] = array(
    '#title' => t('Date Range'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_maxStreamAge', '7'),
    '#description' => t('Set the max age of streams being retrieved through the Gigya API call. The default and maximum is 7 days.'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_max_item_age'] = array(
    '#title' => t('Max age of item (hours)'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_max_item_age', '72'),
    '#description' => t('Set the max age in hours for any visible item. Any items older than this will not be displayed'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_includeLastComment'] = array(
    '#title' => t('Include Last Comment'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_includeLastComment', 'false'),
    '#description' => t('This parameter specifies whether to include the most recent comment in each stream. The default value of this parameter is false. If this parameter is set to true, the response of this method includes a lastComment field in each of the stream objects'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_time_modifier'] = array(
    '#title' => t('Time modifier'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_time_modifier', '1.5'),
    '#description' => t('Modifies the weight of the item age in the popularity alogrithm, must be set to a value between 1.0 and 2.0. Algorithm: (# of Comments-1)^Comment Modifier/(Item Age+2)^Time Modifier'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_comment_modifier'] = array(
    '#title' => t('Comment modifier'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_comment_modifier', '1'),
    '#description' => t('Modifies the weight of the number of items comments in the popularity alogrithm, must be set to a value between 1.0 and 2.0. Algorithm: (# of Comments-1)^Comment Modifier/(Item Age+2)^Time Modifier'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_api_key'] = array(
    '#title' => t('Site Gigya Api key'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_api_key', ''),
    '#description' => t('Your API key can be found on the dashboard of the Gigya website.'),
    '#required' => TRUE,
  );

  $form['gigya_top_streams_secretKey'] = array(
    '#title' => t('Gigya SecretKey'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_secretKey', ''),
    '#description' => t('Your secret key can be found at the bottom of the Site Setup page on the Gigya website.'),
    '#required' => TRUE,
  );

  $form['gigya_top_streams_google_analytics_queue'] = array(
    '#title' => t('Google Analytics Queue'),
    '#type' => 'textfield',
    '#default_value' => variable_get('gigya_top_streams_google_analytics_queue', ''),
    '#description' => t('Enter the name of the queue that will be applied to Google Analytics onClick event for each displayed node'),
    '#required' => FALSE,
  );

  $form['gigya_top_streams_promote'] = array(
    '#title' => t('Promoted to Front Page Toggle'),
    '#type' => 'checkboxes',
    '#options' => array(
      'promote' => t('Display only nodes that have been promoted to the front page?')
    ),
    '#default_value' => variable_get('gigya_top_streams_promote', array('promote' => ''))
  );

  $form = system_settings_form($form);

  return $form;
}

/**
 * Form validation
 *
 */
function gigya_top_streams_form_validate($form, &$form_state) {
  $comment_modifier = $form_state['values']['gigya_top_streams_comment_modifier'];
  $time_modifier = $form_state['values']['gigya_top_streams_time_modifier'];

  if ($comment_modifier > 2 || $comment_modifier < 1) {
    form_set_error('gigya_top_streams_comment_modifier', t('You must enter a comment modifier value between 1.0 and 2.0.'));
  }
  if ($time_modifier > 2 || $time_modifier < 1) {
    form_set_error('gigya_top_streams_time_modifier', t('You must enter a time modifier value between 1.0 and 2.0.'));
  }
}
