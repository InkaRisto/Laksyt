# Kirjoita ohjelma, joka kysyy kalastajalta kuhan pituuden senttimetreinä.
# Jos kuha on alamittainen, ohjelma käskee laskea kuhan takaisin järveen
# ilmoittaen samalla montako senttiä alimmasta sallitusta pyyntimitasta puuttuu.
# Kuha on alamittainen, jos sen pituus on alle 37 cm.

lgt = float(input('Kuinka suuri kuha? (Syötä senttimetreinä) '))

if lgt < 37:
    missing = 37 - lgt
    print(f'Päästä kuha järveen, kokoa puuttuu {missing} cm.')

else:
    print('Kuha on hyvä pyydettäväksi!')