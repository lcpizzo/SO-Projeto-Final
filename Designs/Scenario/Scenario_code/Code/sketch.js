function setup(){
  createCanvas(1920, 1080);
  
  // ======================================================
  // Colorindo o asfalto
  background('#363636');

  noStroke();
  /*fill('#656464');
  for(var i = 5; i < width; i += 60)
    for(var j = height / 7; j < (height / 7) * 3; j += 60)
      rect(i, j, 20, 10);
  
  for(var i = 5; i < width; i += 60)
    for(var j = (height / 7) * 4; j < (height / 7) * 6; j += 60)
      rect(i, j, 20, 10);
  
  fill('#4f4e4e');
  for(var i = 20; i < width; i += 60)
    for(var j = (height / 7) + 15; j < (height / 7) * 3; j += 60)
      rect(i, j, 20, 10);
  
  for(var i = 20; i < width; i += 60)
    for(var j = ((height / 7) * 4) + 15; j < (height / 7) * 6; j += 60)
      rect(i, j, 20, 10);
  
  fill('#797979');
  for(var i = 35; i < width; i += 60)
    for(var j = (height / 7) + 30; j < (height / 7) * 3; j += 60)
      rect(i, j, 20, 10);
  
  for(var i = 35; i < width; i += 60)
    for(var j = ((height / 7) * 4) + 30; j < (height / 7) * 6; j += 60)
      rect(i, j, 20, 10);
 
  fill('#8c8c8c');
  for(var i = 50; i < width; i += 60)
    for(var j = (height / 7) + 45; j < (height / 7) * 3; j += 60)
      rect(i, j, 20, 10);  

  for(var i = 50; i < width; i += 60)
    for(var j = ((height / 7) * 4) + 45; j < (height / 7) * 6; j += 60)
      rect(i, j, 20, 10);
  */
      
  fill(255, 255, 255);
  for(var i = 10; i < width; i += 200)
    rect(i, ((height / 7) * 2)/* - 5*/, 100, 10);

  for(var i = 10; i < width; i += 200)
    rect(i, ((height / 7) * 5)/* - 5*/, 100, 10);


  // ======================================================
  // Colorindo o gramado
  fill(67, 137, 34);
  rect(0, 0, width, 150);
  rect(0, height - 150, width, 150);
  
  fill(75, 157, 36);
  for(var i = 5; i < width; i += 20)
    for(var j = 0; j < 150; j += 20)
      square(i, j, 10);
    
  for(var i = 5; i < width; i += 20)
    for(var j = height - 10; j > height - 160; j -= 20)
      square(i, j, 10);
  
  fill(98, 151, 31);
  for(var i = -5; i < width; i += 20)
    for(var j = 10; j < 150; j += 20)
      square(i, j, 10);
    
  for(var i = -5; i < width; i += 20)
    for(var j = height - 20; j > height - 160; j -= 20)
      square(i, j, 10);
 
  // ======================================================
  // Colorindo o rio
  fill(0, 0, 255);
  rect(0, (height - 150) / 2, width, 150);

  /*fill(0, 0, 220);
  for(var i = 5; i < width; i += 420)
    for(var j = ((height / 2) - 65); j < (height / 2) + 75; j += 40)
      rect(i, j, 20, 10);
  
  fill(255, 255, 255);
  for(var i = 10; i < width; i += 420)
    for(var j = ((height / 2) - 62); j < (height / 2) + 75; j += 40)
      rect(i, j, 10, 4);
  */

  // ======================================================
  // Separando os slots
  /*stroke(0, 0, 0)
  fill(0, 0, 0);

  for(var i = 1; i <= 10; i++){
   line((width / 10) * i, 0, (width / 10) * i, height); 
  }

  for(var i = 1; i <= 10; i++){
   line(0, (height / 7) * i, width, (height / 7) * i); 
  }*/
}

function draw(){
  
}