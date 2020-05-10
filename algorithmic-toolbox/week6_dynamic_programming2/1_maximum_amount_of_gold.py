# Uses python3
import sys

# the knapsack values
# opt_weights = [list()]


def optimal_weight(W, items, w):
    '''
    Dynamic programming function for finding the optimal weight of the knapsack
    '''
    global opt_weights
    for i in range(1, items + 1):
        for knapsack_weight in range(1, W + 1):
            opt_weights[i][knapsack_weight] = opt_weights[i - 1][knapsack_weight]
            if w[i - 1] <= knapsack_weight:
                # using w[i - 1] because lists are indexed from 0 and not
                # because we are looking at previous weight
                value = opt_weights[i - 1][knapsack_weight - w[i - 1]] + w[i - 1]
                if value > opt_weights[i][knapsack_weight]:
                    opt_weights[i][knapsack_weight] = value

    return opt_weights[items][W]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    global opt_weights
    opt_weights = [[0 for x in range(W + 1)] for y in range(n + 1)]

    print(optimal_weight(W, n, w))
