#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "General database error.";
    }
};
class ConnectionFailedException : public DatabaseException {
public:
    const char* what() const noexcept override {
        return "Failed to connect to database.";
    }
};
template <typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid")
            throw ConnectionFailedException();
        throw DatabaseException();
    }
};
int main() {
    DatabaseConnector<string> db;

    try {
        db.connect("invalid"); 
    } catch (const ConnectionFailedException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    try {
        db.connect("error"); 
    } catch (const DatabaseException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}
