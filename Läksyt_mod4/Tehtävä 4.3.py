# Kirjoita ohjelma, joka kysyy käyttäjältä lukuja
# kunnes tämä syöttää tyhjän merkkijonon lopetusmerkiksi.
# Lopuksi ohjelma tulostaa saaduista luvuista pienimmän ja suurimman.

put = (input('Syötä luku (Tyhjä lopettaa): '))
min = 1
max = 1

while put != '':
    numb = float(put)
    if numb < min:
       min = numb
    elif numb > max:
        max = numb
    else:
        put = input('Syötä uusi luku: ')

print('Ohjelma on päättynyt.')

if min != 1 and max != 1:
    print(f'Pienin syöttämäsi luku on {min} ja suurin on {max}')

