# Uses python3
import math


# Function to evaluate an expression
def evalt(a, op, b):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False


# Find the minimum and maximum of a subexpression
def min_max(dataset, start, end, max_vals, min_vals):
    # declare the minimum and maximum values to infinities
    min_val = math.inf
    max_val = -math.inf

    if start == end:
        return dataset[start], dataset[start]

    # loop through all the possible last operations
    calc_vals = [0 for i in range(4)]
    for k in range(start, end):
        if type(dataset[k]) == str:
            # calculate all the possible values of operations
            calc_vals[0] = evalt(max_vals[start][k - 1], dataset[k], max_vals[k + 1][end])
            calc_vals[1] = evalt(max_vals[start][k - 1], dataset[k], min_vals[k + 1][end])
            calc_vals[2] = evalt(min_vals[start][k - 1], dataset[k], min_vals[k + 1][end])
            calc_vals[3] = evalt(min_vals[start][k - 1], dataset[k], max_vals[k + 1][end])

            # calculate the minimum of all and store it
            min_val = min(calc_vals + [min_val])
            # calculate the maximum of all and store it
            max_val = max(calc_vals + [max_val])

    # return the minimum and maximum
    return min_val, max_val


# Find the maximum value of a mathematical expression
def get_maximum_value(dataset):
    # convert the string into a list
    OPERATORS = ['+', '-', '*', '/']
    data_list = list()
    lst_op_ind = 0
    for i in range(len(dataset)):
        if dataset[i] in OPERATORS:
            data_list.append(int(dataset[lst_op_ind:i]))
            data_list.append(dataset[i])
            lst_op_ind = i + 1

    data_list.append(int(dataset[lst_op_ind]))

    # store the maximal and minimal value of subexpression
    max_vals = [['#' for i in range(0, len(data_list) + 1)] for j in range(0, len(data_list))]
    min_vals = [['#' for i in range(0, len(data_list) + 1)] for j in range(0, len(data_list))]

    length = len(data_list)
    # initialise the middle elements to numbers in the expression
    for i in range(length):
        if type(data_list[i]) == int:
            max_vals[i][i] = data_list[i]
            min_vals[i][i] = data_list[i]

    for s in range(0, length, 2):
        for t in range(0, length - s, 2):
            j = s + t
            min_vals[t][j], max_vals[t][j] = min_max(data_list, t, j, max_vals, min_vals)

    return max_vals[0][length - 1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
