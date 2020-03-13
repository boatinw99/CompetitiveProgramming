let color = ["red","blue"];
function colorX(index){
  return color[index];
  
}
var i ;
for(i=0;i<=20;i++){
  console.log(colorX(i%2));
}