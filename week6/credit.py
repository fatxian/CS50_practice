from cs50 import get_int

def main():
    number = get_number()
    if luhn_sum(number)%10 == 0:
        print("true")
    else:
        print("No")

def split(n):
    return n//10, n%10

def sum_digit(n):
    if n < 10:
        return n
    else:
        all_but_last, last = split(n)
        return sum_digit(all_but_last) + last

def luhn_sum(n):
    if n < 10:
        return n
    else:
        all_but_last, last = split(n)
        return luhn_double_sum(all_but_last) + last

def luhn_double_sum(n):
        all_but_last, last = split(n)
        luhn_digit = sum_digit(2 * last)
        if n < 10:
            return luhn_digit
        else:
            return luhn_sum(all_but_last) + luhn_digit

def get_number():
    while True:
        n = get_int("Number: ")
        if n > 0:
            return n

main()


------------------------
from cs50 import get_int

def main():
    number = get_number()

    if is_valid_luhn(number):
        company = get_card_company(number)
        print(company)
    else:
        print("INVALID")

def get_number():
    while True:
        n = get_int("Number: ")
        if n > 0:
            return n

def is_valid_luhn(number):
    total = 0
    is_second = False

    while number > 0:
        digit = number % 10
        number //= 10

        if is_second:
            doubled = digit * 2
            total += doubled if doubled < 10 else doubled - 9
        else:
            total += digit

        is_second = not is_second

    return total % 10 == 0

def get_card_company(number):
    num_str = str(number)
    length = len(num_str)

    if length == 15 and num_str.startswith(("34", "37")):
        return "AMEX"
    elif length == 16 and num_str.startswith(("51", "52", "53", "54", "55")):
        return "MASTERCARD"
    elif length in [13, 16] and num_str.startswith("4"):
        return "VISA"
    else:
        return "INVALID"
