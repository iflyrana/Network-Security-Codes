#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string encrypt(const string& text, const string& key) {
    int num_cols = key.length();
    string padded_text = text + string((num_cols - text.length() % num_cols) % num_cols, ' ');
    vector<string> matrix;
    for (int i = 0; i < padded_text.length(); i += num_cols) {
        matrix.push_back(padded_text.substr(i, num_cols));
    }
    vector<pair<char, string>> sorted_columns;
    for (int i = 0; i < num_cols; ++i) {
        sorted_columns.emplace_back(key[i], matrix[i]);
    }
    sort(sorted_columns.begin(), sorted_columns.end());
    string encrypted_text;
    for (const auto& col : sorted_columns) {
        encrypted_text += col.second;
    }
    return encrypted_text;
}

string decrypt(const string& text, const string& key) {
    int num_cols = key.length();
    int num_rows = text.length() / num_cols;
    vector<string> matrix(num_cols);
    for (int i = 0; i < num_cols; ++i) {
        matrix[i] = text.substr(i * num_rows, num_rows);
    }
    vector<pair<char, string>> sorted_columns;
    for (int i = 0; i < num_cols; ++i) {
        sorted_columns.emplace_back(key[i], matrix[i]);
    }
    sort(sorted_columns.begin(), sorted_columns.end());
    string decrypted_text;
    for (int i = 0; i < num_rows; ++i) {
        for (const auto& col : sorted_columns) {
            decrypted_text += col.second[i];
        }
    }
    return decrypted_text;
}

int main() {
    string plain_text, key;
    cout << "Enter plain text (all uppercase): ";
    getline(cin, plain_text);
    cout << "Enter the key (unique numbers from 1 to n to define sequence): ";
    getline(cin, key);

    string encrypted = encrypt(plain_text, key);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
