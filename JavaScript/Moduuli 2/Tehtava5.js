'use strict';

const numberArr = [];
let programRun = true
while(programRun){
  const number = parseInt(prompt('Syötä numero:'));
  if (numberArr.includes(number)){
    programRun = false;
  }
  else {
    numberArr.push(number);
  }
}

numberArr.sort((a,b) => a-b);
console.log(numberArr)