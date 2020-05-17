# Uses python3
def print_mat(mat):
    r, c = len(mat), len(mat[0])

    for i in range(r):
        for j in range(c):
            print(mat[i][j], end=' ')

        print('\n')


# compute the edit distance using dynamic programming
def edit_distance(s, t):
    leng_s = len(s)
    leng_t = len(t)

    ed_dists = [[0 for i in range(leng_s + 1)] for i in range(leng_t + 1)]

    # initialise the matrix with initial values
    for i in range(leng_t + 1):
        ed_dists[i][0] = i

    for i in range(leng_s + 1):
        ed_dists[0][i] = i

    for r in range(1, leng_t + 1):
        for c in range(1, leng_s + 1):
            ins = ed_dists[r][c - 1] + 1
            dele = ed_dists[r - 1][c] + 1
            match = ed_dists[r - 1][c - 1]
            mismatch = ed_dists[r - 1][c - 1] + 1

            if s[c - 1] == t[r - 1]:
                ed_dists[r][c] = min(ins, dele, match)
            else:
                ed_dists[r][c] = min(ins, dele, mismatch)

    return ed_dists[leng_t][leng_s]


if __name__ == "__main__":
    print(edit_distance(input(), input()))
