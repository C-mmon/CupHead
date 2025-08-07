def min_strokes_recursive(heights):
	def solve(l, r, base):
		if l > r:
			return 0
		m = min(heights[l:r+1])
		cost_h = m-base
		i= l
		while i <= r:
			if heights[i] == m:
				i+=1
			else:
				j= i
				while j <= r and heights[j] > m:
					j+=1
				cost_h += solve(i, j-1, m)
				i= j
		cost_v= r-l+1
		return min(cost_h, cost_v)
	return solve(0, len(heights)-1, 0)
