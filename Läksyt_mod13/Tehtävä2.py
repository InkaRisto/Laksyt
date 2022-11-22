from flask import Flask, Response
import json
import mysql.connector

link = mysql.connector.connect(
    host='127.0.0.1',
    port=3306,
    database='flight_game',
    user='root',
    password='dB22',
    autocommit=True
    )

app = Flask(__name__)

def get_info(icao):
    try:
        icao = str.upper(icao)
        mycursor = link.cursor()
        mycursor.execute('SELECT NAME, municipality FROM airport WHERE ident = "' + icao + '";')
        find = mycursor.fetchone()
        if find != None:
            name = find[0]
            municip = find[1]
            response = {
                "ICAO": icao,
                "Name": name,
                "Municipality": municip
            }
            return response
    except:
        status=404
        response = {
            "Error": status,
            "Message": "ICAO not found"}

        return Response(response=json.dumps(response), status=404)


@app.route('/airport/<icao>')
def get_name(icao):
    try:
        statuscode = 200
        airport = get_info(icao)
        return airport

    except:
        statuscode = 400
        response = {
            "Status": statuscode,
            "Message": "Unrecognized ICAO-code2"
        }

    jsonrespo = json.dumps(response)
    return Response(response=jsonrespo, status=statuscode)


@app.errorhandler(404)
def page_not_found(error):
    response = {
        "status" : "404",
        "teksti" : "Endpoint not found"
    }
    jsonrespo= json.dumps(response)
    return Response(response=jsonrespo, status=404)


if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)