# Muokkaa edellistä funktiota
# funktio saa parametrinaan nopan tahkojen yhteismäärän.
# voit heitellä esimerkiksi 21-tahkoista roolipelinoppaa.
# Edellisestä tehtävästä poiketen nopan heittelyä jatketaan pääohjelmassa kunnes nopan maksimisilmäluku,
# joka kysytään käyttäjältä ohjelman suorituksen alussa.
import random

def roll(d):
    return random.randint(1, d)

def printIt():
    print(die)

d = int(input('Montako sivua noppaan? '))

while roll(d) != d:
    die = roll(d)
    printIt()
    if roll(d) == d:
        break

if roll(d) == d:
       printIt()
