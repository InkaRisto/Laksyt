# Kirjoita ohjelma, joka kysyy käyttäjältä nimiä
# kunnes käyttäjä syöttää tyhjän merkkijonon.
# Kunkin nimen syöttämisen jälkeen ohjelma tulostaa joko tekstin Uusi nimi tai Aiemmin syötetty nimi
# sen mukaan, syötettiinkö nimi ensimmäistä kertaa.
# Lopuksi ohjelma luettelee syötetyt nimet yksi kerrallaan allekkain mielivaltaisessa järjestyksessä.
# Käytä joukkotietorakennetta nimien tallentamiseen.

names = set()

while True:
    uname = input('Syötä nimi. (Tyhjä lopettaa) ')

    if uname in names:
        print('Aiemmin syötetty nimi.')

    if uname == '':
        break

    else:
        print('Uusi nimi.')
        names.add(uname)

for n in names:
    print(n)
