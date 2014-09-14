/**
 *
 *
 * @licstart  The following is the entire license notice for the 
 *  JavaScript code in this page.
 *
 * Copyright (C) 2014  Ross Glover
 *
 *
 * The JavaScript code in this page is free software: you can
 * redistribute it and/or modify it under the terms of the GNU
 * General Public License (GNU GPL) as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.  The code is distributed WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU GPL for more details.
 *
 * As additional permission under GNU GPL version 3 section 7, you
 * may distribute non-source (e.g., minimized or compacted) forms of
 * that code without the copy of the GNU GPL normally required by
 * section 4, provided you include this license notice and a URL
 * through which recipients can access the Corresponding Source.
 *
 * @licend  The above is the entire license notice
 * for the JavaScript code in this page.
 *
 */
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
