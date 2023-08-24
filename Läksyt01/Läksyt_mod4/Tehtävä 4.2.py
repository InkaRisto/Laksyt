# Kirjoita ohjelma, joka muuntaa tuumia senttimetreiksi
# niin kauan kunnes käyttäjä antaa negatiivisen tuumamäärän.
# Sen jälkeen ohjelma lopettaa toimintansa.

inch = float(input('Syötä tuumat (negatiivinen luku lopettaa): '))

while inch >= 0:
    cm = inch * 2.54
    print (f'{inch} tuumaa on {cm} senttimetriä.')
    inch = float(input('Syötä tuumat: '))

print('Ohjelma päättynyt.')
