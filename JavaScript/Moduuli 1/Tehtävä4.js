'use strict';

function generateRandomInteger(max) {
    return Math.floor(Math.random() * max) + 1;
}

let name, house;
name = prompt('Hei, kerro nimesi: ');
house = generateRandomInteger(4)

if(house <= 1){
  document.querySelector('#sorted').innerHTML = 'Hei, ' + name + '. Olet Rohkelikko!';
}

else if(house <= 2){
  document.querySelector('#sorted').innerHTML = 'Hei, ' + name + '. Olet Korpinkynsi!';
}

else if(house <= 3){
  document.querySelector('#sorted').innerHTML = 'Hei, ' + name + '. Olet Luihunen!';
}

else if(house <= 4){
  document.querySelector('#sorted').innerHTML = 'Hei, ' + name + '. Olet Puuskupuh!';
}
else{
  document.querySelector('#sorted').innerHTML = 'Voi ei, ' + name + ', olet surkki!';
}

//3p.
