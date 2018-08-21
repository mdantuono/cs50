from cs50 import get_string
import sys

key = int(sys.argv[1])
plaintext = get_string("plaintext: ")
print("ciphertext: ", end="")
for i in range(len(plaintext)):
    if plaintext[i].isalpha():
        if plaintext[i].isupper():
            charNum = ord(plaintext[i]) - 65
            ciphertext = chr((charNum + key) % 26 + 65)
            print(ciphertext, end="")
        elif plaintext[i].islower():
            charNum = ord(plaintext[i]) - 97
            ciphertext = chr((charNum + key) % 26 + 97)
            print(ciphertext, end="")
    else:
        ciphertext = plaintext[i]
        print(ciphertext, end="")
print()