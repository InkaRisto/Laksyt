# Kirjoita funktio saa parametrinaan listan kokonaislukuja.
# Ohjelma palauttaa listassa olevien lukujen summan.
# testausta varten pääohjelma, jossa luot listan, kutsut funktiota ja tulostat sen palauttaman summan.

def sumUp(ints):
    sums = 0
    for n in ints:
        sums = sums + n
    return sums

numbers = [1,2,3,4,5]

print(sumUp(numbers))
