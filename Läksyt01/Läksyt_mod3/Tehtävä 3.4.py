# Kirjoita ohjelma, joka kysyy vuosiluvun ja ilmoittaa, onko annettu vuosi karkausvuosi.
# Vuosi on karkausvuosi, jos se on jaollinen neljällä.
# Sadalla jaolliset vuodet ovat karkausvuosia vain jos ne ovat jaollisia myös neljälläsadalla.

year = int(input('Syötä vuosiluku: '))

if (year % 100 == 0 and year % 400 == 0) or year % 4 == 0:
    print('Vuosi on karkausvuosi.')

else:
    print('Vuosi ei ole karkausvuosi.')
