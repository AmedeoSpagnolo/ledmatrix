var row = 16
var column = 24
var matrix = new Array(column).fill(new Array(row).fill(0));

;$( document ).ready(function() {
  $("svg").on("click", "circle", function(){
    toggleled(this)
  })
})

function toggleled(element){
  el = $(element)
  if(el.hasClass("active")){
    el.removeClass("active")
  } else {
    el.addClass("active")
  }
  update_matrix()
  $("#value").text(get_value_from_matrix())
}

function get_value_from_matrix(){
  // first number: max column
  // convert binary every column
  var temp = []
  matrix.forEach(function(i){
    var bin = i.join("")
    temp.push(parseInt(bin, 2))
  })
  return "uint8_t newChar[] = { " + temp.join(", ") + " } // rename newChar"
}

function update_matrix(){
  // get value from svg
}
