(function($, Drupal) {
   // Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
   Drupal.ajax.prototype.commands.afterAjaxTabLoad = function(ajax, response, status) {
     // Remove Active tab from others
     $('ul.tabs-primary').find('li.active').find('a.active').find('span.element-invisible').remove();
     $('ul.tabs-primary').find('li.active').find('a.active').removeClass('active');
     $('ul.tabs-primary').find('li.active').removeClass('active')
     // Add active class to tab
     $('li.update-tab').addClass('active');
     $('li.update-tab').find('a').addClass('active');
     // Now let's remove unwanted  views and comments
     $('section.related-schemes').next('.comments-wrapper').remove();
     $('section.related-schemes').remove();
   };
}(jQuery, Drupal));
