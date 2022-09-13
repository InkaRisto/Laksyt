# Kirjoita funktio saa parametrinaan listan kokonaislukuja.
# Ohjelma palauttaa listassa olevien lukujen summan.
# testausta varten pääohjelma, jossa luot listan, kutsut funktiota ja tulostat sen palauttaman summan.

def sumUp(ints):
    sums = 0
    for n in ints:
        sums = sums + n
    return sums

numbers = [20,21,22,23,24,25,26]

print(sumUp(numbers))
