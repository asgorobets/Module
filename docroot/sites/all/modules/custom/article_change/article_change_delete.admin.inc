<?php


function form_change_article($form, &$form_state)
{
    $form = array();
    $type = "article";

    $nodes = node_load_multiple(array(), array('type' => $type));
    foreach ($nodes as $nid => $node) {
        $options[$nid] = $node->title;
        $options_p[$nid] = $node->status;
    }

    $form['articles_nid'] = array(
        '#type' => 'select',
        '#title' => t('Selected articles you want to change'),
        '#options' => $options,
        '#description' => t('Here you can select the articles you want tot change'),
    );
    $form['status_select'] = array(
        '#type' => 'select',
        '#title' => t('Selected articles you want to change'),
        '#options' => array(
            0 => t('Unpublished'),
            1 => t('Published'),
        ),
        '#description' => t('Here you can select the articles you want tot change'),
    );
    $form['actions']['update_article_button'] = array(
        '#type' => 'submit',
        '#value' => t('Update'),
        '#submit' => array('update_article_form')
    );
    $form['actions']['delete_article_button'] = array(
        '#type' => 'submit',
        '#value' => t('Delete'),
        '#submit' => array('delete_article_form')
    );
    return $form;

}

$match = false;

function form_change_article_validate($form, &$form_state) {
    $type = 'article';
    $node_update = node_load($form_state['values']['articles_nid']);
    if ($node_update->type != $type) {
        form_set_error('articles_nid', t('This is not an article'));
  }
}

function update_article_form($form, &$form_state)
{
    $node_update = node_load($form_state['values']['articles_nid']);
    $node_update->status = $form_state['values']['status_select'];
    node_save($node_update);
}


function delete_article_form($form, &$form_state)
{
    node_delete($form_state['values']['articles_nid']);

}