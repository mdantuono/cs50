from cs50 import get_string
import sys

if len(sys.argv) > 2 or not sys.argv[1].isalpha():
    sys.exit(1)
keyword = sys.argv[1]
plaintext = get_string("plaintext: ")
print("ciphertext: ", end="")
for i in range(len(plaintext)):
    n = 0
    if n > len(keyword) - 1:
        n -= len(keyword)
    if keyword[n].isupper():
        key = ord(keyword[n]) - 65
    elif keyword[n].islower():
        key = ord(keyword[n]) - 97
    if plaintext[i].isalpha:
        if plaintext[i].isupper():
            charNum = ord(plaintext[i]) - 65
            ciphertext = chr((charNum + key) % 26 + 65)
            print(ciphertext, end="")
            n += 1
        elif plaintext[i].islower():
            charNum = ord(plaintext[i]) - 97
            ciphertext = chr((charNum + key) % 26 + 97)
            print(ciphertext, end="")
            n += 1
    else:
        ciphertext = plaintext[i]
        print(ciphertext, end="")
print()

# Only partially working, will fix in future