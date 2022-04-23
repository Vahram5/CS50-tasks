from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    pyramid(height, 1)


def pyramid(height, c):
    if height == 0:
        quit()
    space = height - 1
    print(" " * space, end="")
    print("#" * (c), end="")
    print("")
    c += 1
    pyramid(space, c)


main()