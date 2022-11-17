'use strict';

let people;
const howManyCandi = parseInt(prompt('Montako ehdokasta kirjataan?'));
let candidates = [];

for(let i = 1; i < howManyCandi+1; i++){
  people = prompt(`Syötä ehdokkaan ${i} nimi:`);
  candidates.push({name: people, votes: 0});
}

let voters = prompt('Montako äänestäjää?');

function getIndexofCandidate (name){
  for(let i=0; i < candidates.length; i++){
    if (candidates[i].name === name){
      return i
    }
      }
    return false}

for (let i = 0; i < voters; i++){
  let vote = prompt(`Äänestäjä ${i+1}, syötä ehdokkaasi nimi:`);
    const candidateIdx = getIndexofCandidate(vote);
  if (candidateIdx !== false){
    candidates[candidateIdx].votes++
  }}

candidates.sort((a,b) => b.votes-a.votes);
  console.log(`Voittaja on ${candidates[0].name}, ${candidates[0].votes} äänellä`);
  console.log('Äänimäärät:');

for(const candidate of candidates){
  console.log(candidate.name + ': ' + candidate.votes + ' ääntä');
}
