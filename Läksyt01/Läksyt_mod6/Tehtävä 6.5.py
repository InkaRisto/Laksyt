# Kirjoita funktio; saa parametrinaan listan kokonaislukuja.
# Ohjelma palauttaa toisen listan, joka on muuten samanlainen kuin parametrina saatu lista
# paitsi että siitä on karsittu pois kaikki parittomat luvut.
# Kirjoita testausta varten pääohjelma, jossa luot listan, kutsut funktiota ja tulostat
# sekä alkuperäisen että karsitun listan.

def sort(evens):
    fixed = []
    for n in evens:
        if n % 2 == 0:
            fixed.append(n)
    return fixed


numbers = [20,21,22,23,24,25,35,36,74,75,877,965,1000]

print(numbers)
print(sort(numbers))
