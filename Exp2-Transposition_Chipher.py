def encrypt(text, key):

    num_cols = len(key)
    padded_text = text + ' ' * ((num_cols - len(text) % num_cols) % num_cols)
    matrix = [list(padded_text[i:i + num_cols]) for i in range(0, len(padded_text), num_cols)]
    sorted_columns = [col for _, col in sorted(zip(key, zip(*matrix)))]
    encrypted_text = ''.join(''.join(col) for col in sorted_columns)

    return encrypted_text


def decrypt(text, key):

    num_cols = len(key)
    num_rows = len(text) // num_cols
    matrix = [list(text[i:i + num_rows]) for i in range(0, len(text), num_rows)]
    sorted_columns = [col for _, col in sorted(zip(key, zip(*matrix)))]
    decrypted_text = ''.join(''.join(col) for col in zip(*sorted_columns))

    return decrypted_text


if __name__ == '__main__':
    plain_text = input("Enter plain text (all uppercase): ")
    key = input("Enter the key (numbers from 1 to n): ")

    encrypted = encrypt(plain_text, key)
    print("Encrypted text:", encrypted)

    decrypted = decrypt(encrypted, key)
    print("Decrypted text:", decrypted)
