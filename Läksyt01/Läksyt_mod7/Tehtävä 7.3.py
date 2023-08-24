# Kirjoita ohjelma lentoasematietojen hakemiseksi ja tallentamiseksi.
# Ohjelma kysyy käyttäjältä, haluaako tämä syöttää uuden lentoaseman,
# hakea jo syötetyn lentoaseman tiedot vai lopettaa.
# Jos käyttäjä valitsee uuden lentoaseman syöttämisen, ohjelma kysyy käyttäjältä lentoaseman
# ICAO-koodin ja nimen. Jos käyttäjä valitsee haun, ohjelma kysyy ICAO-koodin ja tulostaa sitä
# vastaavan lentoaseman nimen. Jos käyttäjä haluaa lopettaa, ohjelman suoritus päättyy.
# Käyttäjä saa valita uuden toiminnon miten monta kertaa tahansa aina siihen asti,
# kunnes hän haluaa lopettaa. (ICAO-koodi on lentoaseman yksilöivä tunniste.
# Esimerkiksi Helsinki-Vantaan lentoaseman ICAO-koodi on EFHK. Löydät koodeja helposti selaimen avulla.)

ports = {}

def search(ports):
    key = input('Syötä lentoaseman ICAO-koodi: ')
    return ports[key]

def add(ports):
    ICAO = input('Syötä lentoaseman ICAO-koodi: ')
    name = input('Syötä lentoaseman nimi: ')
    ports[ICAO] = name
    return

while True:
    userInput = input('Lentoasemat:\n 1. Hae lentoasema\n 2. Lisää lentoasema\n 0. Lopeta\n')
    if userInput == '1':
        print(search(ports))
    if userInput == '2':
        add(ports)
    if userInput == '0':
        print('Ohjelma lopetettu.')
        break

