# Uses python3
import math


# Find the minimum number of coins needed to change a given money
def get_change(m):
    # subproblems list
    changes_cnt = [0 for i in range(m + 1)]
    # available denominations list
    denoms = [1, 3, 4]

    # use bottom up approach for solving using dynamic programming
    for money in range(1, m + 1):
        # solve smaller change problems
        min_change = math.inf
        for den in denoms:
            if den <= money:
                cur = changes_cnt[money - den] + 1
                if cur < min_change:
                    min_change = cur

        # minimum of the different subproblems
        changes_cnt[money] = min_change

    return changes_cnt[m]


if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
