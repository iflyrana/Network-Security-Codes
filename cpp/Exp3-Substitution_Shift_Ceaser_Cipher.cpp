#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& text, int shift) {
    string encrypted_text = "";
    for (char alphabet : text) {
        encrypted_text += (alphabet - 'A' + shift) % 26 + 'A';
    }
    return encrypted_text;
}

string decrypt(const string& text, int shift) {
    string decrypted_text = "";
    for (char alphabet : text) {
        decrypted_text += (alphabet - 'A' - shift + 26) % 26 + 'A';
    }
    return decrypted_text;
}

int main() {
    string plain_text;
    int shift_value;

    cout << "Enter plain text (all uppercase): ";
    cin >> plain_text;

    cout << "Enter shift value (Enter 3 for Caesar cipher): ";
    cin >> shift_value;

    string encrypted = encrypt(plain_text, shift_value);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift_value);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
