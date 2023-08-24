'use strict';

let number1, number2, number3, sum, product, average;
number1 = parseInt(prompt('Syötä kokonaisluku: '));
number2 = parseInt(prompt('Syötä toinen kokonaisluku: '));
number3 = parseInt(prompt('Syötä vielä yksi kokonaisluku: '));

sum = number1 + number2 + number3;
product = number2 * number3 * number1;
average = (number1 + number2 + number3) / 3;

document.querySelector('#print1').innerHTML = 'Numeroiden summa on: ' + sum
document.querySelector('#print2').innerHTML = 'Numeroiden tulo on: ' + product
document.querySelector('#print3').innerHTML = 'Numeroiden keskiarvo on: ' + average;

//3p.