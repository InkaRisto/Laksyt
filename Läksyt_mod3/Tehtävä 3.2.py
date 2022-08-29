# Kirjoita ohjelma, joka kysyy käyttäjältä laivan hyttiluokan (LUX, A, B, C)
# Tulostaa sen sanallisen kuvauksen
# Tehtävässä on käytettävä if/elif/else-

cabin = input('Syötä hyttiluokka: ')

if cabin == 'LUX' or cabin == 'lux':
    print('LUX on parvekkeellinen hytti yläkannella.')
elif cabin == 'A' or cabin == 'a':
    print('A on ikkunallinen hytti autokannen yläpuolella.')
elif cabin == 'B' or cabin == 'b':
    print('B on ikkunaton hytti autokannen yläpuolella.')
elif cabin == 'C' or cabin == 'c':
    print('C on ikkunaton hytti autokannen alapuolella.')
else:
    print('Virheellinen hyttiluokka')