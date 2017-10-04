var app = {}
app.leds = {}

app.leds.row = 16
app.leds.column = 24
app.leds.matrix = matrix = new Array(app.leds.column);
for (var i = 0; i < app.leds.column; i++) {
  matrix[i] = new Array(app.leds.row).fill(0);
}

;$( document ).ready(function() {
  $("svg").on("click", "circle", function(){
    toggleled(this)
  })
  $("#value").text(get_value_from_matrix())
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

  matrix[0][15] = 1
  matrix[5][13] = 1

  // convert binary every column
  var temp = []
  matrix.forEach(function(i){
    var bin = i.join("")
    temp.push(parseInt(bin, 2))
  })
  var arr = delete_empty_column(temp)
  return "uint8_t newChar[] = { " + arr.join(", ") + " } // rename newChar"
}

function update_matrix(){
  // get value from svg
  // TO DO
}

function delete_empty_column(ar){
  for (var i = ar.length - 1; i != 0; i--){
    if (parseInt(ar[i],2) == 0 ) {
      ar.splice(i)
    } else {
      return ar
    }
  }
}
