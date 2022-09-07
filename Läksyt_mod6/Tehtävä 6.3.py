# Kirjoita funktio, joka saa parametrinaan bensiinin määrän Yhdysvaltain nestegallonoina
# palauttaa paluuarvonaan vastaavan litramäärän.
# Kirjoita pääohjelma, joka kysyy gallonamäärän käyttäjältä ja muuntaa sen litroiksi.
# Muunnos on tehtävä aliohjelmaa hyödyntäen.
# Muuntamista jatketaan siihen saakka, kunnes käyttäjä syöttää negatiivisen gallonamäärän.

def convert(gallons):
    litres = 3.78541178 * gallons
    return litres


userInput = float(input('Paljonko polttoainetta gallonoina? (Negatiivinen luku lopettaa) '))

while userInput > 0:

    print(f'{userInput} gallonia polttoainetta vastaa {convert(userInput):.3f} litraa')
    print('')
    userInput = float(input('Paljonko polttoainetta gallonoina? '))

