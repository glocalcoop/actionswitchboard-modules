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
/**
* Provide the HTML to create the modal dialog.
*/
(function ($) {

  Drupal.theme.prototype.asb_modal_gt = function () {
    var html = '';
    html += '<div id="ctools-modal" class="popups-box">';
    html += '   <div class="ctools-modal-content ctools-modal-asb-modal-gt">';
    html += '       <div class="modal-content-wrapper">'
    html += '           <header class="modal-head-wrapper">';
    html += '               <span class="modal-update-title" style="display:none;">Add Update</span>';
    html += '               <span class="popups-close"><a class="close ctools-close-modal" href="#"><span>Close Window</span></a></span>';
    html += '           </header>';
    html += '           <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '       </div>';
    html += '   </div>';
    html += '</div>';
    return html;
  }
})(jQuery);
