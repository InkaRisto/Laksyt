# Kirjoita ohjelma, joka kysyy käyttäjältä laivan hyttiluokan (LUX, A, B, C)
# Tulostaa sen sanallisen kuvauksen
# Tehtävässä on käytettävä if/elif/else-

put = input('Syötä hyttiluokka: ')
cabin = put.lower()

if cabin == 'lux':
    print('LUX on parvekkeellinen hytti yläkannella.')
elif cabin == 'a':
    print('A on ikkunallinen hytti autokannen yläpuolella.')
elif cabin == 'b':
    print('B on ikkunaton hytti autokannen yläpuolella.')
elif cabin == 'c':
    print('C on ikkunaton hytti autokannen alapuolella.')
else:
    print('Virheellinen hyttiluokka')