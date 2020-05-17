# Uses python3
import sys


# find the length of the longest subsequence in two sequences
def lcs2(s, t):
    leng_s = len(s)
    leng_t = len(t)

    ed_dists = [[0 for i in range(leng_s + 1)] for i in range(leng_t + 1)]

    # initialise the matrix with initial values
    for i in range(leng_t + 1):
        ed_dists[i][0] = 0

    for i in range(leng_s + 1):
        ed_dists[0][i] = 0

    for r in range(1, leng_t + 1):
        for c in range(1, leng_s + 1):
            ins = ed_dists[r][c - 1]
            dele = ed_dists[r - 1][c]
            match = ed_dists[r - 1][c - 1] + 1
            mismatch = ed_dists[r - 1][c - 1]

            if s[c - 1] == t[r - 1]:
                ed_dists[r][c] = match
            else:
                ed_dists[r][c] = max(ins, dele, mismatch)

    return ed_dists[leng_t][leng_s]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
