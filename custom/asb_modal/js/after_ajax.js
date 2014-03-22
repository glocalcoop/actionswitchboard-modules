(function($, Drupal) {
  // Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
  Drupal.ajax.prototype.commands.afterAjaxCallbackAsbModal = function(ajax, response, status) {
    var commentId = Drupal.settings.asb_modal.commentId
    // Now we close the modal
    $('a.close')[0].click();
    // We were having problems with ckeditor wanting to add
    // to an id that was removed by ajax so we cancel the 
    // Drupal.freezeheight function to close the window space.
    $('#freeze-height').remove();
    // If we're on the update tab we want to reload it to get the
    // newest content
    if($('li.update-tab').hasClass('active')) {
      $('li.update-tab a')[0].click();
    }

    // Now we take the current comment and place it after it's parent
    var currentComment = $(commentId).prev('div');
    var parentComment = $(commentId);
    parentComment.next('article.comment').append(currentComment);
    // Then we scroll back to the parent comment
    $('html, body').animate({
      scrollTop: $(commentId).offset().top
    }, 2000);
  };
  Drupal.ajax.prototype.commands.afterAjaxCallbackAsb = function(ajax, response, status) {
    // This unfreezes the height on non-modal comment submissions.
    $('#freeze-height').remove();
  };
}(jQuery, Drupal));
