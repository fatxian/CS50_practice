from cs50 import get_string

def main():
    s = get_string("Text: ")
    letters = count_letter(s)
    words = count_word(s)
    sentences = count_sentence(s)
    score = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8

    if score >= 16:
        print("Grade 16+")
    elif score < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(score)}")

def count_letter(s):
    count = 0
    for c in s:
        if c.isalpha():
            count += 1
    return count

def count_word(s):
    count = 1  # 至少有一個單字
    for c in s:
        if c.isspace():
            count += 1
    return count

def count_sentence(s):
    count = 0
    for c in s:
        if c in ".!?":
            count += 1
    return count

main()
