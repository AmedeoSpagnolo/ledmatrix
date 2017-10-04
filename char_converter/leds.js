var app = {}
app.leds = {}
app.scale = {}

app.leds.row = 16
app.leds.column = 24
app.leds.matrix = matrix = new Array(app.leds.column);
for (var i = 0; i < app.leds.column; i++) {
  matrix[i] = new Array(app.leds.row).fill(0);
}

app.scale.x = LinearScale().domain([25.3, 617.1]).range([0, app.leds.column - 1]);
app.scale.y = LinearScale().domain([409.3, 24.1]).range([0, app.leds.row - 1]);

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
  update_matrix(el)
  $("#value").text(get_value_from_matrix())
}

function get_value_from_matrix(){

  // convert binary every column
  var temp = []
  matrix.forEach(function(i){
    var bin = i.join("")
    temp.push(parseInt(bin, 2))
  })
  var arr = delete_empty_column(temp) || []
  console.log(arr);
  var text = "uint8_t newChar[] = {  " + arr.length + ", " + arr.join(", ") + " } // rename newChar"
  return arr.length > 0 ? text : ""
}

function update_matrix(el){
  _x = Math.abs(Math.round(app.scale.x(parseInt(el.attr("cx"),10))))
  _y = Math.abs(Math.round(app.scale.y(parseInt(el.attr("cy"),10))))
  app.leds.matrix[_x][_y] = (app.leds.matrix[_x][_y] > 0) ? 0 : 1
}

function delete_empty_column(ar){
  for (var i = ar.length - 1; i >= 0; i--){
    if (parseInt(ar[i],2) == 0 ) {
      ar.splice(i)
    } else {
      return ar
    }
  }
}
