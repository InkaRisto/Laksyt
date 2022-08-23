#Kirjoita ohjelma, joka kysyy käyttäjältä massan keskiaikaisten mittojen mukaan leivisköinä, nauloina
#ja luoteina. Ohjelma muuntaa syötteen täysiksi kilogrammoiksi ja grammoiksi sekä ilmoittaa tuloksen käyttäjälle.
import math
math.floor(0.0)

leivis = float(input('Anna leiviskät: '))
naulat = float(input('Anna naulat: '))
luodit = float(input('Anna luodit: '))

gnaulat = (naulat / 32) * 13.3
gleivis = (leivis / (20*32)) * 13.3
gluodit = 13.3 * luodit

massa = gnaulat + gleivis + gluodit
kilo = massa / 1000
gyli = massa - kilo


print(f'Massa ({massa})nykymittojen mukaan: \n {kilo: 7.0f} kilogrammaa ja{gyli:7.2f} grammaa')


