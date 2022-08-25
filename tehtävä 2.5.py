#Kirjoita ohjelma, joka kysyy käyttäjältä massan keskiaikaisten mittojen mukaan leivisköinä, nauloina
#ja luoteina. Ohjelma muuntaa syötteen täysiksi kilogrammoiksi ja grammoiksi sekä ilmoittaa tuloksen käyttäjälle.
import math

leivis = float(input('Anna leiviskät: '))
naulat = float(input('Anna naulat: '))
luodit = float(input('Anna luodit: '))

gluoti = luodit * 13.3
gnaula = (32*13.3) * naulat
gleivis = leivis * (20*32*13.3)

massa = gnaula + gleivis + gluoti
kilo = massa / 1000
gyli = massa - math.floor(kilo)*1000


print(f'Massa ({massa}) nykymittojen mukaan: \n {kilo: 7.0f} kilogrammaa ja {gyli:7.2f} grammaa')


