from cs50 import get_float

def main():
    cash = get_cash()
    cents = round(cash * 100)  # 避免浮點誤差

    coins = 0

    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    print(coins)

def get_cash():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n

main()
