from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > -1 and height < 24:
        break

for i in range(height):
    for j in range(height - 1 - i):
        print(" ", end="")

    for n in range(i + 2):
        print("#", end="")
    print("")