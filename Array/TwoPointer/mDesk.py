You need to buy monitors for m desks. Each desk can have at most 2 monitors. You’re given a list of monitor prices, and for each desk, the total price of monitors should not exceed a given budget X. Find out how many monitors you can buy.
We want to maximize the monitor assigned, hence everytime the pair does not exist, it is more wise to assign a monitor from the top of the vector.

def max_monitors_corrected(arr, m, X):
    arr.sort()
    i, j = 0, len(arr) - 1
    desks_used = 0
    monitors_assigned = 0

    while i <= j and desks_used < m:
        if i == j: # Case: Only one monitor left
            if arr[i] <= X:
                monitors_assigned += 1
            # Move pointer past the last monitor
            i += 1
        elif arr[i] + arr[j] <= X: # Case: Can pair cheapest and most expensive
            monitors_assigned += 2
            i += 1
            j -= 1
        else: # Case: Cannot pair i and j. Try assigning j alone.
            if arr[j] <= X: # Check if the most expensive one fits alone
                monitors_assigned += 1
            # Move pointer past the most expensive monitor
            j -= 1
        
        # A desk slot was used in this iteration attempt
        desks_used += 1

    return monitors_assigned
