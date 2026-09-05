#include <iostream>
#include <string>
using namespace std;

enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint) {

    switch (status) {

        case HttpStatus::OK:
            cout << "[" << endpoint << "] -> 200 OK : "
                 << "Request successful" << endl;
            break;

        case HttpStatus::Created:
            cout << "[" << endpoint << "] -> 201 Created : "
                 << "Resource created" << endl;
            break;

        case HttpStatus::BadRequest:
            cout << "[" << endpoint << "] -> 400 Bad Request : "
                 << "Invalid request" << endl;
            break;

        case HttpStatus::Unauthorized:
            cout << "[" << endpoint << "] -> 401 Unauthorized : "
                 << "Authentication required" << endl;
            break;

        case HttpStatus::NotFound:
            cout << "[" << endpoint << "] -> 404 Not Found : "
                 << "Endpoint does not exist" << endl;
            break;

        case HttpStatus::ServerError:
            cout << "[" << endpoint << "] -> 500 Server Error : "
                 << "Internal server error - retry later" << endl;
            break;

        default:
            cout << "[" << endpoint << "] -> Unknown HTTP status" << endl;
            break;
    }
}

int main() {

    handleResponse(HttpStatus::OK, "/api/users");

    handleResponse(HttpStatus::Unauthorized, "/api/login");

    handleResponse(HttpStatus::NotFound, "/api/products/99");

    handleResponse(HttpStatus::ServerError, "/api/order");

    return 0;
}