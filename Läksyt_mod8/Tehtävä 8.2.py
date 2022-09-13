# Kirjoita ohjelma, joka kysyy käyttäjältä maakoodin (esimerkiksi FI)
# ja tulostaa kyseisessä maassa olevien lentokenttien lukumäärät tyypeittäin.
# Esimerkiksi Suomen osalta tuloksena on saatava tieto siitä,
# että pieniä lentokenttiä on 65 kappaletta, helikopterikenttiä on 15 kappaletta jne.

import mysql.connector

yhteys = mysql.connector.connect(
         host='127.0.0.1', # Local Host IP
         port=3306,  # MySQL/MariaDB TCP-portti
         database='flight_game',
         user='root',
         password='dB22',
         autocommit=True
         )

code = input('Syötä kaksikirjaiminen maakoodi: ')
sql = 'SELECT type, COUNT(*) FROM airport WHERE iso_country = "' + code + '" GROUP BY TYPE;'
kursori = yhteys.cursor()
kursori.execute(sql)

response = kursori.fetchall()

for r in response:
    print(r[0], r[1])