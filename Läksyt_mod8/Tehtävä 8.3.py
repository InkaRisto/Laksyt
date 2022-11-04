# Kirjoita ohjelma, joka kysyy käyttäjältä kahden lentokentän ICAO-koodit.
# Ohjelma ilmoittaa lentokenttien välisen etäisyyden kilometreinä.
# Laskenta perustuu tietokannasta haettuihin koordinaatteihin.
# Laske etäisyys geopy-kirjaston avulla
# Asenna kirjasto valitsemalla View / Tool Windows / Python Packages.
# Kirjoita hakukenttään geopy ja vie asennus loppuun.


import mysql.connector
from geopy import distance

yhteys = mysql.connector.connect(
         host='127.0.0.1', # Local Host IP
         port=3306,  # MySQL/MariaDB TCP-portti
         database='flight_game',
         user='root',
         password='dB22',
         autocommit=True
         )


def haku():
    icao = input('Syötä lentokentän ICAO-koodi: ')
    sql = 'select latitude_deg, longitude_deg from airport where gps_code  = "' + icao + '"'

    kursori = yhteys.cursor()
    kursori.execute(sql)

    response = kursori.fetchall()
    if kursori.rowcount > 0:
        return response
    else:
        print('Kenttää ei löydy kannasta.')

print('\n Lasketaan kahden lentokentän etäisyys!')

loc1 = haku()
loc2 = haku()
gap = distance.distance(loc1,loc2).km

print(f'Lentokenttien välinen etäisyys on {gap:.2f} km.')
