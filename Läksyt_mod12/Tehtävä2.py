import requests

city = input('Weather for which city? ')
key = '19fea38221e9cd53bf9b7267667ca387'
url = f'https://api.openweathermap.org/data/2.5/weather?q={city}&appid={key}'

try:
    response = requests.get(url)

    if response.status_code == 200:
        data = response.json()
        weather = data['weather'][0]
        temp = data['main']['temp']
        print(f'Current weather: \n{weather["description"]}, temperature: {temp - 273.15:.1f}°C')
    else:
        print(f' Virhe! {response}')

except requests.exceptions.RequestException as er:
    print(f'Haku epäonnistui. Error {er}')

