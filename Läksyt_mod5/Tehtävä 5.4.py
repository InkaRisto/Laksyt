places = []

for i in range (5):
    town = input('Anna kaupungin nimi: ')
    places.append(town)
    i=+1

print('')
print('Syötit kaupungit:')
for p in places:
    print(f'-{p}')