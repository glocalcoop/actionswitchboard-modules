<?php


/**
 * EntityExampleBasicControllerInterface definition.
 *
 * We create an interface here because anyone could come along and
 * use hook_entity_info_alter() to change our controller class.
 * We want to let them know what methods our class needs in order
 * to function with the rest of the module, so here's a handy list.
 *
 * @see hook_entity_info_alter()
 */
interface CannedEmailControllerInterface
  extends DrupalEntityControllerInterface {

  /**
   * Create an entity.
   */
  public function create();

  /**
   * Save an entity.
   *
   * @param object $entity
   *   The entity to save.
   */
  public function save($entity);

  /**
   * Delete an entity.
   *
   * @param object $entity
   *   The entity to delete.
   */
  public function delete($entity);

}

/**
 * controller for canned_email entity
 */
class CannedEmailController 
  extends DrupalDefaultEntityController
  implements CannedEmailControllerInterface {
  /**
   * Create and return a new entity_example_basic entity.
   */
  public function create() {
    $entity = new stdClass();
    $entity->type = 'canned_email';
    $entity->ceid = 0;
    $entity->name = '';
    $entity->email_subject = '';
    $entity->email_body = '';
    return $entity;
  }
  /**
   * Saves the custom fields using drupal_write_record().
   */
  public function save($entity) {
    // If our entity has no basic_id, then we need to give it a
    // time of creation.
    if (empty($entity->ceid)) {
      $entity->created = time();
      $entity->changed = time();
    }else{
      $entity->changed = time();
    }
    // Invoke hook_entity_presave().
    module_invoke_all('entity_presave', $entity, 'canned_email');
    // The 'primary_keys' argument determines whether this will be an insert
    // or an update. So if the entity already has an ID, we'll specify
    // basic_id as the key.
    // $primary_keys = $entity->ceid ? 'ceid' : array();
    $primary_keys = $entity->ceid ? 'ceid' : array();
    // Write out the entity record.
    drupal_write_record('canned_email', $entity, $primary_keys);
    // We're going to invoke either hook_entity_update() or
    // hook_entity_insert(), depending on whether or not this is a
    // new entity. We'll just store the name of hook_entity_insert()
    // and change it if we need to.
    $invocation = 'entity_insert';
    // Now we need to either insert or update the fields which are
    // attached to this entity. We use the same primary_keys logic
    // to determine whether to update or insert, and which hook we
    // need to invoke.
    if (empty($primary_keys)) {
      field_attach_insert('canned_email', $entity);
    }
    else {
      field_attach_update('canned_email', $entity);
      $invocation = 'entity_update';
    }
    // Invoke either hook_entity_update() or hook_entity_insert().
    module_invoke_all($invocation, $entity, 'canned_email');
    return $entity;
  }
  /* drupal_write_record('canned_email', $canned_email); */
  /* field_attach_insert('canned_email', $canned_email); */
  /* module_invoke_all('entity_insert', 'canned_email', $canned_email); */
  /* return $canned_email; */

/**
 * Delete a single entity.
 *
 * Really a convenience function for deleteMultiple().
 */
  public function delete($entity) {
    $this->deleteMultiple(array($entity));
  }

  /**
   * Delete one or more canned email entities.
   *
   * Deletion is unfortunately not supported in the base
   * DrupalDefaultEntityController class.
   *
   * @param array $entities
   *   An array of entity IDs or a single numeric ID.
   */
  public function deleteMultiple($entities) {
    $ceids = array();
    if (!empty($entities)) {
      $transaction = db_transaction();
      try {
        foreach ($entities as $entity) {
          // Invoke hook_entity_delete().
          module_invoke_all('entity_delete', $entity, 'canned_email');
          field_attach_delete('canned_email', $entity);
          $ceids[] = $entity->ceid;
        }
        db_delete('canned_email')
          ->condition('ceid', $ceids, 'IN')
          ->execute();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('canned_email', $e);
        throw $e;
      }
    }
  }
}
