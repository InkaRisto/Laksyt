'use strict';

let howManyCandi, candidates, people;
howManyCandi = parseInt(prompt('Montako ehdokasta kirjataan?'));
candidates = [];

for(let i = 1; i < howManyCandi+1; i++){
  people = prompt(`Syötä ehdokkaan ${i} nimi:`);
  candidates.push({name: people, votes: 0});
}

let voters = prompt('Montako äänestäjää?');

for (let i = 0; i < voters; i++){
  let vote = prompt('Syötä ehdokkaasi nimi:');
    for(let n in candidates){
      if(candidates[n].name === vote){
        candidates[n].votes = candidates[n].votes + 1;
      }
    }


  }

candidates.sort((a,b) => b-a);
  console.log(`Voittaja on ${candidates[0].name}, ${candidates[0].votes} äänellä`);
  console.log('Äänimäärät:');

for(let i in candidates){
  console.log(candidates[i].name + ': ' + candidates[i].votes + ' ääntä');
}
