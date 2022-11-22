from flask import Flask, Response
import json

app = Flask(__name__)

@app.route('/prime/<number>')
def prime(number):
    try:
        number = float(number)
        statuscode = 200
        sendoff = {
            "number": number,
            "isPrime": False
        }

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

    jsonvast = json.dumps(sendoff)
    return Response(response=jsonvast, status=statuscode, mimetype="application/json")


@app.errorhandler(404)
def page_not_found(virhekoodi):
    sendoff = {
        "status": "404",
        "teksti": "Virheellinen pääte"
    }
    jsonvast = json.dumps(sendoff)
    return Response(response=jsonvast, status=404)


def check_it(number):
    if number == 2 or number == 3:
        return True
    else:
        for i in range(2, int(number / 2)):
            if (number % i) == 0:
                return False
            elif (number % 3) == 0:
                return False
            elif (number % 5) == 0:
                return False
            else:
                return True


if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)
