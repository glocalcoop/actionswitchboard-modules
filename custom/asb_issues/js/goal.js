(function($) {
  Drupal.behaviors.asbGoal = {
    attach: function(context, settings) {
      $('.page-node-add-goal').find('#edit-field-scheme-goals-taxonomy').hide();
    }
  }
})(jQuery);
