'use strict';

let squareMe, result;
if(confirm('Lasketaanko neliöjuuri?')){
  squareMe = parseFloat(prompt('Syötä laskettava numero:'));
  if(squareMe >= 0){
    result = Math.sqrt(squareMe);
    document.querySelector('#here').innerHTML = 'Luvun ' + squareMe + " neliöjuuri on "
    + result + '.';
  }
  else if(squareMe < 0){
    document.querySelector('#here').innerHTML = 'Negatiivisen luvun neliöjuurta ei ole määritelty.'
  }
  else{
    document.querySelector('#here').innerHTML = 'Syötitkö varmasti numeron?'
  }
}

else{
  document.querySelector('#here').innerHTML = 'Neliöjuurta ei laskettu.'
}

//3p.