# Uses python3
import sys


# find the maximum product revenue using greedy algorithm
def max_dot_product(a, b):
    # sort the profit per clicks in descending order
    a.sort(reverse=True)
    b.sort(reverse=True)
    leng = len(a)

    # find the maximum profit by taking the largest from profit and slot
    res = 0
    for i in range(leng):
        res += a[i] * b[i]

    return res


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:(n + 1)]
    b = data[(n + 1):]
    print(max_dot_product(a, b))
