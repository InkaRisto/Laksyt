places = []

for i in range (5):
    town = input('Anna kaupungin nimi: ')
    places.append(town)

print('')
print('Syötit kaupungit:')
for t in places:
    print(f'-{t}')