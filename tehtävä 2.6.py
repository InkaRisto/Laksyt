#Kirjoita ohjelma, joka arpoo ja tulostaa kaksi erilaista numerolukon koodia:

   # kolmenumeroisen koodin, jonka kukin numeromerkki on väliltä 0..9.
    # nelinumeroisen koodin, jonka kukin numeromerkki on väliltä 1..6.

import random

luku = random.randint(0,9)

kolmikko = str('Numerosarjasi on' + str(luku) + str(luku) + str(luku))

print(luku)