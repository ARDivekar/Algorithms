# rod_cutting.py

def bestCost (price_array, saved_bestCosts, n):
	if n==0: return 0
	if saved_bestCosts[n-1]!=0:
		return saved_bestCosts[n-1]
	max_val=price_array[n-1]
	for i in range(0,n):
		max_val=max(max_val, price_array[i]+bestCost(price_array, saved_bestCosts, n-i-1))
	saved_bestCosts[n-1]=max_val
	return max_val




saved_bestCosts=[0 for x in range(0,8)]

print bestCost([2,5,8,9,15,17,17,20], saved_bestCosts, 8)
print saved_bestCosts