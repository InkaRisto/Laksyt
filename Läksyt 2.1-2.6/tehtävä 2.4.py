# Kirjoita ohjelma, joka kysyy kolme kokonaislukua. Ohjelma tulostaa lukujen summan, tulon ja keskiarvon.

eka = int(input('Anna kokonaisluku:'))
toka = int(input('Anna uusi luku:'))
koke = int(input('Anna vielä yksi luku:'))

summa = eka + toka + koke
tulo = eka * toka * koke
ka = summa / 3

print('Lukujen summa: ' + str(summa) + '\nLukujen tulo: ' + str(tulo) + '\nLukujen keskiarvo: ' + str(ka))



