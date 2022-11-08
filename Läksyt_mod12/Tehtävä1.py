import requests

url = 'https://api.chucknorris.io/jokes/random'

try:
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        print(data['value'])
    else:
        print(f'Virhe! Error: {response.status_code}')

except:
    print('Huumorin haku epäonnistui')