# Kirjoita ohjelma, joka kysyy käyttäjän biologisen sukupuolen
# ja hemoglobiiniarvon (g/l). Ohjelma ilmoittaa, onko hemoglobiiniarvo alhainen, normaali vai korkea.

sex = input('Anna biologinen sukupuoli (N/M): ')
hemo = int(input('Anna hemoglobiiniarvo (g/l): '))

if sex == 'N' or sex == 'n':
    if 117 <= hemo <= 175:
        print(f'Hemogobiiniarvo {hemo} g/l on normaali.')
    elif hemo < 117:
        print('Hemoglobiiniarvo on alhainen.')
    elif hemo > 175:
        print('Hemoglobiiniarvo on korkea.')

elif sex == 'M' or sex == 'm':
    if 134 <= hemo <= 195:
        print(f'Hemoglobiiniarvo {hemo} g/l on normaali.')
    elif hemo < 134:
        print('Hemoglobiiniarvo on alhainen.')
    elif hemo > 195:
        print('Hemoglobiiniarvo on korkea.')




