# Uses python3


# Find optimal sequence using greedy approach
def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        if n % 3 == 0:
            n = n // 3
        elif n % 2 == 0:
            n = n // 2
        else:
            n = n - 1
    return reversed(sequence)


# Find the optimal sequence using dynamic programming
def optimal_sequence_fast(num):
    # store the result as we progress
    steps_cnt = [float('inf') for i in range(num + 1)]
    # initialise the starting values
    steps_cnt[0], steps_cnt[1] = 0, 0

    # find the shortest number of operations for smaller subproblems
    for n in range(2, num + 1):
        if (n % 3) == 0:
            cur_val = steps_cnt[n // 3] + 1
            if cur_val < steps_cnt[n]:
                steps_cnt[n] = cur_val

        if (n % 2) == 0:
            cur_val = steps_cnt[n // 2] + 1
            if cur_val < steps_cnt[n]:
                steps_cnt[n] = cur_val

        cur_val = steps_cnt[n - 1] + 1
        if cur_val < steps_cnt[n]:
            steps_cnt[n] = cur_val

    # backtrace the path to the solution
    breadcrumb = num
    path = [num for i in range(steps_cnt[num] + 1)]
    # the final element will be the input number itself and first one will be 1
    s = len(path) - 1
    path[s], path[0] = num, 1
    s -= 1

    while s > 0:
        if (breadcrumb % 3) == 0:
            cur_val = steps_cnt[breadcrumb // 3]
            if cur_val < steps_cnt[path[s]]:
                path[s] = breadcrumb // 3

        if (breadcrumb % 2) == 0:
            cur_val = steps_cnt[breadcrumb // 2]
            if cur_val < steps_cnt[path[s]]:
                path[s] = breadcrumb // 2

        cur_val = steps_cnt[breadcrumb - 1]
        if cur_val < steps_cnt[path[s]]:
            path[s] = breadcrumb - 1

        breadcrumb = path[s]
        s -= 1

    return path


n = int(input())
sequence = optimal_sequence_fast(n)
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
