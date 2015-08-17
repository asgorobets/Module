<?php

function menu_hello_name($wildcard) {
  $content = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('Hello someone named "%wildcard" .', array('%wildcard' => $wildcard)) . '</p>',
  );
  return $content;
}