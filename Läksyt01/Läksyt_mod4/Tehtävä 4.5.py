# Kirjoita ohjelma, joka kysyy käyttäjältä käyttäjätunnuksen ja salasanan.
# Jos jompikumpi tai molemmat ovat väärin, tunnus ja salasana kysytään uudelleen.
# Tätä jatketaan kunnes kirjautumistiedot ovat oikein tai väärät tiedot on syötetty viisi kertaa.
# Edellisessä tapauksessa tulostetaan Tervetuloa ja jälkimmäisessä Pääsy evätty.
# (Oikea käyttäjätunnus on python ja salasana rules).

passw = 'rules'
user = 'python'
put_user = input('Syötä käyttäjätunnus: ')
put_passw = input('Syötä salasana: ')
tries = 1


if put_user == user or put_passw == passw:
    print('Tiedot oikein!')

# or put_user != user or put_passw != passw:

else:
    while put_passw != passw or put_user != user:
        print('Väärä käyttäjätunnus tai salasana. Yritä uudestaan')
        put_user = input('Syötä käyttäjätunnus: ')
        put_passw = input('Syötä salasana: ')
        tries = tries + 1

        if tries >= 5:
            break

if tries == 5:
    print('Tiedot väärin liian monta kertaa.')

print('Ohjelma päättynyt.')

