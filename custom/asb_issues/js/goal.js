(function($) {
  Drupal.behaviors.asbGoal = {
    attach: function(context, settings) {
      $('#edit-field-scheme-goals-taxonomy', context).once('asbGoal', function () {
        $(this).hide();
        $('#edit-workflow').hide();
      });
    }
  }
})(jQuery);
