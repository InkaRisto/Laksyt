'use strict';
const year = prompt('Anna vuosiluku:');

function CheckYear(year) {
  if (year % 4 === 0 || year % 100 === 0 && year % 400 === 0) {
      document.querySelector('body').innerHTML = "Vuosi " + year +
          " on karkausvuosi.";}
  else {
    document.querySelector('body').innerHTML = "Vuosi " + year +
        " ei ole karkausvuosi.";
  }
}

CheckYear(year);

//3p.