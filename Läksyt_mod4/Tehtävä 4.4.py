# Kirjoita peli, jossa tietokone arpoo kokonaisluvun väliltä 1..10.
# Kone arvuuttelee lukua pelaajalta siihen asti, kunnes tämä arvaa oikein.
# Kunkin arvauksen jälkeen ohjelma tulostaa tekstin Liian suuri arvaus,
# Liian pieni arvaus tai Oikein. Huomaa, että tietokone ei saa vaihtaa lukuaan arvauskertojen välissä.

import random

comp = random.randint(1, 10)
guess = int(input('Arvaa mitä lukua ajattelen välillä 1-10. '))

while comp != guess:

    if comp < guess:
        print('Liian suuri arvaus.')
        guess = int(input('Arvaa uudestaan. '))

    elif comp > guess:
        print('Liian pieni arvaus.')
        guess = int(input('Arvaa uudestaan. '))

if comp == guess:
    print('Arvasit oikein!')
