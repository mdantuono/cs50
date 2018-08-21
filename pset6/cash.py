from cs50 import get_float

coins = 0
quarter = 25
dime = 10
nickle = 5
penny = 1

while True:
    change = get_float("Change: ")
    if change > 0:
        break
change = round(change * 100)
while change >= 25:
    coins = coins + 1
    change = change - quarter
while change >= 10:
    coins = coins + 1
    change = change - dime
while change >= 5:
    coins = coins + 1
    change = change - nickle
while change >= 1:
    coins = coins + 1
    change = change - penny

print("Coins: {}".format(coins))