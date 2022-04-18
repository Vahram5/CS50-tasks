from cs50 import get_string


def main():
    text = get_string("Text: ")
    letter = sentece = 0
    word = 1
    length = len(text)
    # print(chr(53))
    for c in text:
        if ord(c) == 32:
            word += 1
        elif ord(c) == 33 or ord(c) == 46 or ord(c) == 63:
            sentece += 1
        elif (ord(c) >= 65 and ord(c) <= 90) or (ord(c) >= 97 and ord(c) <= 122):
            letter += 1
    L = round(letter / word * 100, 2)
    S = round(sentece / word * 100, 2)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index > 16:
        print("Grade 16+")
    elif index <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()