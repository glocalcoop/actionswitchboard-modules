(function($) {
  Drupal.behaviors.asbIssues = {
    attach: function(context, settings) {
      $('#edit-field-issues-goals-und').find('input[name=field_issues_goals[und]]:checked').click();
      $('#edit-field-scheme-goals-taxonomy').show();
    }
  }
})(jQuery);
