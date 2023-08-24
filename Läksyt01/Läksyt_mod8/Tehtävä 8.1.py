# Kirjoita ohjelma, joka kysyy käyttäjältä lentoaseman ICAO-koodin.
# Ohjelma hakee ja tulostaa koodia vastaavan lentokentän nimen ja
# sen sijaintikunnan kurssilla käytettävästä lentokenttätietokannasta.

import mysql.connector

yhteys = mysql.connector.connect(
         host='127.0.0.1', # Loal Host IP
         port=3306,  # MySQL/MariaDB TCP-portti
         database='flight_game',
         user='root',
         password='dB22',
         autocommit=True
         )

userICAO = input('Syötä ICAO-koodi: ')

sql = 'select NAME, municipality from airport where gps_code  = "' + userICAO + '"'

kursori = yhteys.cursor()
kursori.execute(sql)

response = kursori.fetchall()
for r in response:
    print(f'{r[0]}, {r[1]}')


