from cs50 import get_float


def main():
    while True:
        coins = get_float("How much money you own: ")
        if coins > 0:
            break
    coins = int(coins * 100)

    coin25 = calculate_quarters(coins)
    coins = coins - (25 * coin25)

    coin10 = calculate_dimes(coins)
    coins = coins - (10 * coin10)

    coin5 = calculate_nickels(coins)
    coins = coins - (5 * coin5)

    coin1 = calculate_pennies(coins)

    coins = coin25 + coin10 + coin5 + coin1

    print(coins)


# 25cents
def calculate_quarters(money):
    coin25 = int((money - (money % 25)) / 25)
    return coin25


# 10cents
def calculate_dimes(money):
    coin10 = int((money - (money % 10)) / 10)
    return coin10


# 5cents
def calculate_nickels(money):
    coin5 = int((money - (money % 5)) / 5)
    return coin5


# 1cents
def calculate_pennies(money):
    coin1 = int(money / 1)
    return coin1


main()