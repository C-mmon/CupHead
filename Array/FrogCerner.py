def smallest_starting_stair(jumps: list[int]) -> int:
    """
    Calculates the smallest positive starting stair number for a frog
    such that it always remains on a positive stair after all jumps.

    Args:
        jumps: A list of integers representing the jumps the frog makes.
               Positive values mean jumping up, negative values mean jumping down.

    Returns:
        The smallest positive integer representing the starting stair.
    """
    cumulative_sum = 0  # Represents the frog's position relative to its start
    min_cumulative_sum_achieved = 0  # Tracks the lowest relative position reached

    # Iterate through each jump
    for jump_value in jumps:
        cumulative_sum += jump_value
        # Update the minimum relative position if the current one is lower
        if cumulative_sum < min_cumulative_sum_achieved:
            min_cumulative_sum_achieved = cumulative_sum

    # To ensure the frog is always on a stair >= 1:
    # start_stair + min_cumulative_sum_achieved >= 1
    # So, start_stair >= 1 - min_cumulative_sum_achieved
    # The smallest integer start_stair is 1 - min_cumulative_sum_achieved.
    
    # If min_cumulative_sum_achieved is 0 (e.g., all jumps are positive),
    # the frog can start at stair 1.
    # If min_cumulative_sum_achieved is negative (e.g., -7), means the frog dipped 7 stairs
    # below its starting point. To keep that lowest point at 1, it must start at 1 - (-7) = 8.
    required_start_stair = 1 - min_cumulative_sum_achieved
    
    return required_start_stair

# Example usage:
jumps1 = [-5, 1, 2, 1, -6] # Assuming "1-6" from the prompt was a typo for "1, -6"
output1 = smallest_starting_stair(jumps1)
print(f"For jumps {jumps1}, the smallest starting stair is: {output1}") # Expected: 8

jumps2 = [1, 2, 3]
output2 = smallest_starting_stair(jumps2)
print(f"For jumps {jumps2}, the smallest starting stair is: {output2}") # Expected: 1

jumps3 = [-1, -2, -3]
output3 = smallest_starting_stair(jumps3)
print(f"For jumps {jumps3}, the smallest starting stair is: {output3}") # Expected: 7
# Trace for jumps3:
# jump -1: cum_sum = -1, min_cum_sum = -1
# jump -2: cum_sum = -3, min_cum_sum = -3
# jump -3: cum_sum = -6, min_cum_sum = -6
# start = 1 - (-6) = 7

jumps4 = [5, -2, 3, -8, 4]
output4 = smallest_starting_stair(jumps4)
print(f"For jumps {jumps4}, the smallest starting stair is: {output4}") # Expected: 3
# Trace for jumps4:
# initial: cum_sum = 0, min_cum_sum = 0
# jump 5:  cum_sum = 5,  min_cum_sum = 0
# jump -2: cum_sum = 3,  min_cum_sum = 0
# jump 3:  cum_sum = 6,  min_cum_sum = 0
# jump -8: cum_sum = -2, min_cum_sum = -2
# jump 4:  cum_sum = 2,  min_cum_sum = -2
# start = 1 - (-2) = 3

jumps5 = [] # Edge case: no jumps
output5 = smallest_starting_stair(jumps5)
print(f"For jumps {jumps5}, the smallest starting stair is: {output5}") # Expected: 1
