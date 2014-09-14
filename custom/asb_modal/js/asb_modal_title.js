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
(function($) {
  Drupal.behaviors.asbModal = {
    attach: function(context, settings) {
      $('.modal-update-title').hide();
      $('ul.primary li.ctools-use-ajax a.use-ajax').click(function() {
        $('ul.primary a.active').removeClass('active');
        $(this).addClass('active');
      });
      $('#modalContent').ajaxComplete(function() {
        var nodeId = $('form.node-form').attr('id');
        // var nodeId = 'update-node-form';
        var nodeType = nodeId.split('-');
        var typeUp = nodeType[0].substr(0,1).toUpperCase()+nodeType[0].substr(1);
        $('.modal-update-title').html('Add ' + typeUp);
        $('.modal-update-title').show();
      });
    }
  }
})(jQuery);

