from flask import Flask, Response
import json

app = Flask(__name__)


@app.route('/prime/<number>')
def prime(number):
    try:
        number = int(number)
        statuscode = 200

        if check_it(number):
            sendoff = {"number": number, "isPrime": True}
        else:
            sendoff = {"number": number, "isPrime": False}

    except ValueError:
        statuscode = 400
        sendoff = {
            "status": statuscode,
            "teksti": "Oliko arvo varmasti numero?"
        }

    jsonrespo = json.dumps(sendoff)
    return Response(response=jsonrespo, status=statuscode, mimetype="application/json")


@app.errorhandler(404)
def page_not_found(virhekoodi):
    sendoff = {
        "status": "404",
        "teksti": "Virheellinen osoite"
    }
    jsonrespo = json.dumps(sendoff)
    return Response(response=jsonrespo, status=404)


def check_it(number):
    if number == 2 or number == 3:
        return True
    else:
        for i in range(2, int(number / 2)):
            if (number % i) == 0:
                return False
            else:
                return True


if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)
