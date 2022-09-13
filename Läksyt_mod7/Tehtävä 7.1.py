# Kirjoita ohjelma, joka kysyy käyttäjältä kuukauden numeron,
# jonka jälkeen ohjelma tulostaa sitä vastaavan vuodenajan (kevät, kesä, syksy, talvi).
# Tallenna ohjelmassasi kuukausia vastaavat vuodenajat merkkijonoina monikkotietorakenteeseen.
# Määritellään kukin vuodenaika kolmen kuukauden mittaiseksi siten, että joulukuu on ensimmäinen talvikuukausi.

vuodenajat = {}



def scan(kk, vuodenajat):
    vuodenajat['talvea'] = (12, 1, 2)
    vuodenajat['kevättä'] = (3, 4, 5)
    vuodenajat['kesää'] = (6, 7, 8)
    vuodenajat['syksyä'] = (9, 10, 11)

    for n in vuodenajat:
        if kk in vuodenajat[n]:
            return n


kk = int(input('Syödä kuukauden numero: '))
season = scan(kk, vuodenajat)

print(f'{kk}. kuukausi on osa {season}.')




