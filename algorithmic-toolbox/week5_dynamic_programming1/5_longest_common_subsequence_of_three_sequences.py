# Uses python3
import sys


def lcs3(s, t, u):
    leng_s = len(s)
    leng_t = len(t)
    leng_u = len(u)

    sub_sq_lens = [[[0 for h in range(leng_u + 1)] for i in range(leng_s + 1)] for i in range(leng_t + 1)]

    # initialise the matrix with initial values
    for i in range(leng_t + 1):
        sub_sq_lens[i][0][0] = 0

    for i in range(leng_s + 1):
        sub_sq_lens[0][i][0] = 0

    for i in range(leng_u + 1):
        sub_sq_lens[0][0][i] = 0

    for r in range(1, leng_t + 1):
        for c in range(1, leng_s + 1):
            for d in range(1, leng_u + 1):
                ins1 = sub_sq_lens[r][c - 1][d]
                ins2 = sub_sq_lens[r - 1][c][d]
                ins3 = sub_sq_lens[r][c][d - 1]
                match = sub_sq_lens[r - 1][c - 1][d - 1] + 1
                mismatch = sub_sq_lens[r - 1][c - 1][d - 1]

                if s[c - 1] == t[r - 1] == u[d - 1]:
                    sub_sq_lens[r][c][d] = match
                else:
                    sub_sq_lens[r][c][d] = max(ins1, ins2, ins3, mismatch)

    return sub_sq_lens[leng_t][leng_s][leng_u]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))
