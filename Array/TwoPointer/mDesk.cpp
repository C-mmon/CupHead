You need to buy monitors for m desks. Each desk can have at most 2 monitors. You’re given a list of monitor prices, and for each desk, the total price of monitors should not exceed a given budget X. Find out how many monitors you can buy.
We want to maximize the monitor assigned, hence everytime the pair does not exist, it is more wise to assign a monitor from the top of the vector.

def max_monitors(arr, m, X):
    arr.sort()
    i, j = 0, len(arr) - 1
    desks_used = 0
    monitors_assigned = 0

    while i <= j and desks_used < m:
        if arr[i] + arr[j] <= X:
            monitors_assigned += 2
            i += 1
            j -= 1
        else:
            if arr[j] <= X:
                monitors_assigned += 1
            j -= 1
        desks_used += 1

    return monitors_assigned
