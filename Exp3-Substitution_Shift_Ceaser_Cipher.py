def encrypt(text, shift):
    encrypted_text = ""
    for alphabet in text:
        encrypted_text += chr((ord(alphabet) - 65 + shift) % 26 + 65)
    return encrypted_text


def decrypt(text, shift):
    decrypted_text = ""
    for alphabet in text:
        decrypted_text += chr((ord(alphabet) - 65 - shift) % 26 + 65)
    return decrypted_text


if __name__ == '__main__':
    plain_text = input("Enter plain text (all uppercase): ")
    shift_value = int(input("Enter shift value (Enter 3 for Caesar cipher): "))

    encrypted = encrypt(plain_text, shift_value)
    print("Encrypted text:", encrypted)

    decrypted = decrypt(encrypted, shift_value)
    print("Decrypted text:", decrypted)


'''
A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
'''