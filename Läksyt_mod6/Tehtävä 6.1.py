import random

def roll():
    return random.randint(1, 6)

def printIt():
    print(die)

while roll() != 6:
    die = roll()
    printIt()

    if roll() == 6:
        printIt()
        break