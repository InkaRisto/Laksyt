#Kirjoita ohjelma, joka arpoo ja tulostaa kaksi erilaista numerolukon koodia:

   # kolmenumeroisen koodin, jonka kukin numeromerkki on väliltä 0..9.
    # nelinumeroisen koodin, jonka kukin numeromerkki on väliltä 1..6.

import random

kolmikko = []
neljä = []

for i in range (3):
    kolmikko.append(random.randint(0, 9))

for i in range (4):
    neljä.append(random.randint(1, 6))

print(kolmikko)
print(neljä)



#En tykkää outputin ulkomuodosta, mutta en saanut listoja toimimaan nätisti Pythonilla. Dartilla oli toString...









