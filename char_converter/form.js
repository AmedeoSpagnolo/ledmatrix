$(document).ready(function() {
    $('#submit_form').on("submit", function(e) {
      e.preventDefault();
      var value = $( "input:first" ).val()
      console.log(value);
      $( "input:first" ).val("")
    });
});
