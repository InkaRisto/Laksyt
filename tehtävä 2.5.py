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
gyli = massa % 1000 #jakojäännös

# Toinen tapa laskea
naulat = leivis * 20 + naulat # Leiviskät nauloina
luodit = naulat * 32 + luodit # Naulat luoteina
grammat = luodit * 13.3 # Luodit grammoina

print(f'Massa ({massa}) nykymittojen mukaan: \n {math.floor(kilo): .0f} kilogrammaa ja {gyli:.2f} grammaa')


