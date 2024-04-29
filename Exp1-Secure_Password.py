import hashlib as hs

storedPassword = "Secure@123"
storedPassword_hashed = hs.sha256(storedPassword.encode()).hexdigest()

tries = 4

while tries > 0:
    enteredPassword = input("Enter a password: ")
    enteredPassword_hashed = hs.sha256(enteredPassword.encode()).hexdigest()
    if enteredPassword_hashed == storedPassword_hashed:
        print("Correct! You entered the correct password.")
        break
    else:
        print(f"Incorrect! You entered the wrong password. Remaining tries: {tries - 1}")
        tries -= 1
    if tries == 0:
        print("Access Denied! You have tried maximum number of times.")