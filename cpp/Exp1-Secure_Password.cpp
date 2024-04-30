#include <iostream>
#include <string>

using namespace std;

int main() {
    string storedPassword = "Secure@123";
    int tries = 4;

    while (tries > 0) {
        string enteredPassword;
        cout << "Enter a password: ";
        cin >> enteredPassword;

        if (enteredPassword == storedPassword) {
            cout << "Correct! You entered the correct password." << endl;
            break;
        } else {
            cout << "Incorrect! You entered the wrong password. Remaining tries: " << tries - 1 << endl;
            tries--;
        }

        if (tries == 0) {
            cout << "Access Denied! You have tried maximum number of times." << endl;
        }
    }

    return 0;
}
