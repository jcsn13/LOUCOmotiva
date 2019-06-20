import re

from flask import Flask
from flask_restful import Resource, Api, request
from flask_cors import CORS

app = Flask(__name__)
api = Api(app)
cors = CORS(app, resources={r"*": {"origins": "*"}})

def add_headers_to_fontawesome_static_files(response):
    """
    Fix for font-awesome files: after Flask static send_file() does its
    thing, but before the response is sent, add an
    Access-Control-Allow-Origin: *
    HTTP header to the response (otherwise browsers complain).
    """
    print("aqui")
    response.headers.add('Access-Control-Allow-Origin', 'localhost')
    return response


app.after_request(add_headers_to_fontawesome_static_files)


class HelloWorld(Resource):
    #@app.route('/teste', methods=['GET'])
    def get(self):
        print("funciona")
        return {'hello': 'world'}
#outra forma de mapear a rota
api.add_resource(HelloWorld, '/teste')

if __name__ == '__main__':
    app.run(debug=True)																		