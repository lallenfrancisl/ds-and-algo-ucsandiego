# Uses python3
import sys


def is_greater(a, b):
    return int(a + b) >= int(b + a)


def largest_number(a):
    res = ""

    leng = len(a)
    while leng > 0:
        i = 0
        max_el = a[0]
        for number in a:
            if is_greater(number, max_el):
                max_el = number
                max_ind = i

            i += 1

        res += max_el
        del a[max_ind]
        leng = len(a)

    return res


if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
