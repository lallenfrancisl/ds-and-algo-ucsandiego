# Uses python3
import sys
import itertools


def partition3(A):
    for c in itertools.product(range(3), repeat=len(A)):
        sums = [None] * 3
        for i in range(3):
            sums[i] = sum(A[k] for k in range(len(A)) if c[k] == i)

        if sums[0] == sums[1] and sums[1] == sums[2]:
            return 1

    return 0


def partition3_fast(A):
    # return 0 if there are less than 3 souvenieres
    if len(A) < 3:
        return 0

    # return 0 if sum cannot be equally divided into 3 parts
    tot_sum = sum(A)
    souv_division = int(tot_sum / 3)
    if (tot_sum % 3) != 0:
        return 0

    global parts
    parts = [[[0 for i in range(0, len(A) + 1)] for j in range(0, souv_division + 1)] for k in range(0, souv_division + 1)]

    for i in range(1, len(A) + 1):
        for a in range(0, souv_division + 1):
            for b in range(0, souv_division + 1):
                parts[a][b][i] = parts[a][b][i - 1]
                if A[i - 1] <= a:
                    cur_val = parts[a - A[i - 1]][b][i - 1] + A[i - 1]
                    if cur_val > parts[a][b][i]:
                        parts[a][b][i] = cur_val

                if A[i - 1] <= b:
                    cur_val = parts[a][b - A[i - 1]][i - 1] + A[i - 1]
                    if cur_val > parts[a][b][i]:
                        parts[a][b][i] = cur_val

    if parts[souv_division][souv_division][len(A)] == (2 * souv_division):
        return 1

    return 0


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3_fast(A))
