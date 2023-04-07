# python3

from collections import namedtuple

Bracket = namedtuple("Bracket", ["char", "position"])


def are_matching(left, right):
    return (left + right) in ["()", "[]", "{}"]


def find_mismatch(text):
    opening_brackets_stack = []

    for i, character in enumerate(text):
        if character in "([{":
            opening_brackets_stack.append(Bracket(character, i + 1))

            continue

        if character in ")]}":
            try:
                opening = opening_brackets_stack.pop()
            except:
                return i + 1

            is_matching = are_matching(opening.char, character)

            if not is_matching:
                return i + 1

            continue

    if len(opening_brackets_stack) > 0:
        return opening_brackets_stack.pop().position

    return "Success"


def main():
    text = input()
    mismatch = find_mismatch(text)
    print(mismatch)


if __name__ == "__main__":
    main()
