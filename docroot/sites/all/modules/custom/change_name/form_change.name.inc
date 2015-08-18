<?php
function drupal_get_form_page() {
  return drupal_get_form('form_change_name');
}


/*function form_change_name(&$form_state){
  $form = array();

  $form['Site name'] = array(
   '#type' => 'textfield',
    '#title' => t('New site name'),
    '#default_value' => 'AAA',
  );

  return $form;
}
*/

function form_change_name($form, &$form_state) {
  $form = array();

  $form['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('New site name'),
    '#default_value' => variable_get('site_name'),

  );

  /*$form['buttons']['submit'] = array(  //First variant
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
*/

  //$form['#submit'][] = 'custom_form_submit';//Third variant

  return system_settings_form($form);//Second variant
  //return $form; //First variant
}

function form_change_name_validate($form, &$form_state) {
  if ($form_state['values']['site_name'] == variable_get('site_name')) {
    form_set_error('site_name', t('Be original - use another name'));
  }

  if (strlen($form_state['values']['site_name']) < 6) {
    form_set_error('site_name', t('Name too short - use more than 6 characters'));
  }
  if ($form_state['values']['site_name'] == 'Drupal') {
    form_set_error('site_name', t('Do ot use drupal'));
  }
}

//First variant
/*function form_change_name_submit($form, &$form_state) {
  variable_set('site_name', $form_state['values']['site_name']);
}
*/
//Third variant
//function custom_form_submit($form, &$form_state) {
//  variable_set('site_name', $form_state['values']['site_name']);
//}