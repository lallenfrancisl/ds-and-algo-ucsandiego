# Uses python3
import sys


def optimal_summands(n):
    summands = []

    balance = n
    i = 1
    while (i < (n + 1)) and (balance > 0):
        if (balance - i) > i or (balance - i) == 0:
            summands.append(i)
            balance -= i

        i += 1

    return summands


if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    sum = 0
    for x in summands:
        sum += x
        print(x, end=' ')
