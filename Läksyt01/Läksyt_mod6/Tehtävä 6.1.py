# Kirjoita parametriton funktio, joka palauttaa paluuarvonaan satunnaisen nopan silmäluvun 1..6.
# Kirjoita pääohjelma, joka heittää noppaa kunnes tulee kuutonen.
# Pääohjelma tulostaa kunkin heiton jälkeen saadun silmäluvun.
import random

def roll():
    return random.randint(1, 6)

def printIt():
    print(die)
    return

while True:
    die = roll()
    printIt()

    if die == 6:
        break