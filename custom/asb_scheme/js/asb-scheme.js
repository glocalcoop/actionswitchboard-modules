(function($) {

  Drupal.behaviors.asbScheme = {
    attach: function(context, settings) {
      $('ul.primary li.ctools-use-ajax a.use-ajax').ajaxComplete(function() {
        $('ul.primary a.active').removeClass('active');
        $(this).addClass('active');
      });
    }
  }

  //add necessary markup for the scheme slideshow
  $(window).bind('load', function() {
    // we could append this in the HTML just trying to take some of the load off.
    if( $("#carousel-wrapper .carousel-div").length > 1 ) {
      $("#carousel-wrapper").after('<nav id="scheme-images-nav"><a class="cycle-arrow" id="scheme-images-previous" href="#"><span class="screen-reader-text">Previous</span></a><a id="scheme-images-next" class="cycle-arrow" href="#"><span class="screen-reader-text">Next</span></a></nav>');
      $("#carousel-wrapper").cycle({
        fx:     'fade', 
        speed:  450, 
        timeout: 4000,
        fx:    'scrollHorz',
        pause: 1, // pause on hover
        next:   '#scheme-images-next', 
        prev:   '#scheme-images-previous',
        fit: 1
      });      
    }
  });

})(jQuery);
