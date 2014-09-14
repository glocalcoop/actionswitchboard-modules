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
 *
 * Handle the cycling of images in the grand tour.
 */
(function($) {

  Drupal.behaviors.asbGrandTour = {
    attach: function(context, settings) {
      $('#modalContent').animate({ "top": "95px", "left": "88px" }, "slow");
      console.log(context);
      console.log(settings);
      var title = $('.views-field-title .field-content').html();
      console.log(title);
      $('.views-field-title .field-content').remove();
      var images = $('.view-grand-tour .view-content .views-row img')
      $.each( images, function( i, val ) {
        $(this).parent().append('<span class="img-title" style="z-index: 1000;">' + $(this).attr('title') + '</span>')
      });
      $('.view-grand-tour .view-content .views-row').cycle({
        fx:    'fade',
        speed:  450, 
        timeout: 4000,
        pause: 1, // pause on hover
        slideExpr: '.field-image',
        containerResize: 1,
        fit: 1,
        height: '187px',
        width: '325px',
      });      
    }
  }
})(jQuery);
