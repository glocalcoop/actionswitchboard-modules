(function($) {
  Drupal.behaviors.asbUsers = {
    attach: function(context, settings) {
      // Create form_state variables for javascript
      var form_items = settings.asb_users.url_query;
      // Parse the dom for civicrm submission items.
      var cividom = jQuery('.crm-section input').map(function(index,dom){return dom.id})
      // Treat custom_23 individually as it's it's own array
      // and add checks to the recurring fields
      $.each(form_items['custom_23'], function(index, val) {
        if(val == 1) {
          $('input#custom_23_' + index).attr('checked','checked');
        }
      });
      // Treat custom_101 (Host participants) individually because
      // it's two checkboxes
      if(form_items['custom_101'] == 1) {
        $('input#CIVICRM_QFID_1_2').attr('checked','checked');
      }else{
        $('input#CIVICRM_QFID_0_4').attr('checked','checked');
      }
      // Deal with custom_108 (Host participants) on live
      if(form_items['custom_108'] == 'host-yes') {
        $('select[name="custom_108"]').val('host-yes');
      }
      // Treat custom_72 individually as a select list.
      $('select#custom_72 option[value="' + form_items['custom_72'] + '"]').attr('selected','selected');
      // Select state individually
      $('select#state_province-1 option[value="' + form_items['state_province-1'] + '"]').attr('selected','selected');
      // Receive newsletter treated individually.
      if(form_items['custom_105']['Receive Yes Lab newsletter?'] == 1) {
        $('input[name="custom_105[Receive Yes Lab newsletter?]"]').attr('checked','checked');
      }
      // custom_57 is textarea, handle individually.
      $('textarea#custom_57').val(form_items['custom_57']);
      // all other items are handled in this function.
      $.each(cividom, function(index, val) { 
        if(val != "") {
          $('input#' + val).val(form_items[val]);
        }
      });
    }
  }
})(jQuery);
