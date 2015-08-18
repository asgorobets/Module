<?php


function form_change_article($form, &$form_state)
{
    $form = array();
    
    $type = "Article";
    $nodes = node_load_multiple(array(), array('type' => $type));
    foreach ($nodes as $nid => $node):
        $options[$nid] = $node->title;
        $options_p[$nid] = $node->status;
    endforeach;
    foreach ($options_p as $k => $state):
        if ($options_p[$k] == 1) {
            $options_p[$k] = 'Published';
        } else {
            $options_p[$k] = 'Unpublished';
        }
    endforeach;

    $form['articles_select'] = array(
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
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Update'),
        '#submit' => array('custom_form_update')
    );
    $form['actions']['submit2'] = array(
        '#type' => 'submit',
        '#value' => t('Delete'),
        '#submit' => array('custom_form_delete')
    );
    return $form;
}

function custom_form_update($form, &$form_state)
{
    $node_update = node_load($form_state['values']['articles_select']);
    $node_update->status = $form_state['values']['status_select'];
    node_save($node_update);
}

function custom_form_delete($form, &$form_state)
{
    node_delete($form_state['values']['articles_select']);
}