# Kirjoita funktio, parametreinaan pyöreän pizzan halkaisija senttimetreinä
# sekä pizzan hinnan euroina.
# Funktio laskee ja palauttaa pizzan yksikköhinnan euroina per neliömetri.
# Pääohjelma kysyy käyttäjältä kahden pizzan halkaisijat ja hinnat sekä ilmoittaa,
# kumpi pizza antaa paremman vastineen rahalle (eli kummalla on alhaisempi yksikköhinta).
# Yksikköhintojen laskennassa on hyödynnettävä kirjoitettua funktiota.
import math

def pizzaCalc(size, price):
    A = (size/2)**2 * math.pi
    sqm = A/10000
    per = price / sqm
    return per

def info():
    diam = float(input('Mikä on pizzan halkaisija (cm)? '))
    euro = float(input('Paljonko pizza maksaa? '))
    return diam, euro

pizza1 = diam, euro = info()
pizza2 = diam2, euro2 = info()
# print(f'Neliömetrihinta pizzalle 1: {pizzaCalc(diam, euro)}')
# print(f'Neliömetrihinta pizzalle 2: {pizzaCalc(diam2, euro2)}')

if pizzaCalc(diam, euro) < pizzaCalc(diam2, euro2):
    print('Ensimmäisellä pizzalla on halvempi yksikköhinta.')

elif pizzaCalc(diam, euro) > pizzaCalc(diam2, euro2):
    print('Jälkimmäisellä pizzalla on halvempi yksikköhinta.')

elif pizzaCalc(diam, euro) == pizzaCalc(diam2, euro2):
    print('Sama yksikköhinta; valitse vapaasti!')

else:
    print('Tapahtui virhe.')