#Kirjoita ohjelma, joka kysyy käyttäjältä massan keskiaikaisten mittojen mukaan leivisköinä, nauloina
#ja luoteina. Ohjelma muuntaa syötteen täysiksi kilogrammoiksi ja grammoiksi sekä ilmoittaa tuloksen käyttäjälle.

leivis = float(input('Anna leiviskät: '))
naulat = float(input('Anna naulat: '))
luodit = float(input('Anna luodit: '))

gnaulat = (naulat / 32) * 13.3
gleivis = (leivis / (20*32)) * 13.3
gluodit = 13.3 * luodit

massa = gnaulat + gleivis + gluodit
kilo = massa / 1000
print(f'Massa nykymittojen mukaan: \n {kilo: 7.2f} kilogrammaa ja{massa:7.2f} grammaa')


