from cs50 import get_int

def main():
    height = get_height()
    for i in range(1, height + 1):
        print_row(i, height)

def print_row(row, height):
    print(" " * (height - row) + "#" * row + " " + "#" * row)


def get_height():
    while True:
        height = get_int("Height = ? ")
        if 1 <= height <= 8:
            return height

main()
