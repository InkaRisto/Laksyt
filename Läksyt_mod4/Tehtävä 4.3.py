# Kirjoita ohjelma, joka kysyy käyttäjältä lukuja
# kunnes tämä syöttää tyhjän merkkijonon lopetusmerkiksi.
# Lopuksi ohjelma tulostaa saaduista luvuista pienimmän ja suurimman.

put = input('Syötä luku (Tyhjä lopettaa): ')
minV = float(put)
maxV = minV

while put != '':
    numb = float(put)
    if numb < minV:
        minV = numb
    elif numb > maxV:
        maxV = numb
    else:
        put = input('Syötä uusi luku: ')

print('Ohjelma on päättynyt.')

if minV != 1 and maxV != 1:
    print(f'Pienin syöttämäsi luku on {minV} ja suurin on {maxV}')

