kanta = float(input('Syötä kannan pituus:'))
kork = float(input('Syötä korkeus:'))

piiri = (2 * kanta) + (2 * kork)
ala = kanta * kork

print(f'Suorakulmion piiri on {piiri:4.3f} ja pinta-ala on {ala:4.3f}')


