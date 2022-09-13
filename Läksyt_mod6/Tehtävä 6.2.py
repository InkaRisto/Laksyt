# Muokkaa edellistä funktiota
# funktio saa parametrinaan nopan tahkojen yhteismäärän.
# voit heitellä esimerkiksi 21-tahkoista roolipelinoppaa.
# Edellisestä tehtävästä poiketen nopan heittelyä jatketaan pääohjelmassa kunnes nopan maksimisilmäluku,
# joka kysytään käyttäjältä ohjelman suorituksen alussa.
import random

def roll(die):
    return random.randint(1, die)

# def printIt():
#   print(roll)
#   return

userDie = int(input('Montako sivua noppaan? '))
# Miksi ei suostu kutsumaan parametrina??? ^^^^
while True:
    rolled = roll(userDie)
    print(rolled)

    if rolled == userDie:
        break