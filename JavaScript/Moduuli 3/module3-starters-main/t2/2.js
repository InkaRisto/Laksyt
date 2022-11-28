const listPlace = document.querySelector('#target');
const items = document.createElement('li');
items.innerHTML = '<li>First item</li><li>Second item</li>' +
    '<li>Third item</li>';

listPlace.appendChild(items);

const theOne = items.firstChild.nextSibling;
theOne.classList.add("my-item");

//2p.