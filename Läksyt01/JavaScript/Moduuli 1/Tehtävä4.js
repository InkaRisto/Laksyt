'use strict';

const name = prompt('Hei, kerro nimesi: ');
const house = Math.floor(Math.random()*4+1);
let message;

function getHouse(){
  if(house === 1){
  message = name + ', olet Rohkelikko!';
}

else if(house === 2){
  message = name + ', olet Korpinkynsi!';
}

else if(house === 3){
  message = name + ', olet Luihunen!';
}

else{
  message = name + ', olet Puuskupuh!';
}
return message;
}

message = getHouse();
const htmlbody = document.querySelector('body');
const p = document.createElement('p');
p.innerText = message;
htmlbody.append(p);
//3p.
