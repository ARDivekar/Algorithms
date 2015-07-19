# pascals_triangle.py
from misc_functions import Stopwatch

def Binom_coeff_tab(n,k): #tab for tabulation
	# print "Binomial coefficients by tabulation"
	n=n+1 #just for allowing us to normalize the inputs
	pas=[]

	for i in range (0,n):
		pas.append([0 for x in range(0,n)])

	pas[0][0]=1
	for i in range(1,n):
		for j in range(0,i+1):
			if (j==0 or j==i): 
				pas[i][j]=1
			else:
				pas[i][j]=pas[i-1][j-1]+pas[i-1][j]
		# for x in pas:
		# 	print x
		# print ""
	# print "Largest number: %s"%pas[n-1][int(n/2)]
	return pas[n-1][k]

def Binom_coeff_rec(i,j): #rec for recursive, not memoized
	if j==0 or j==i:
		return 1
	else: return Binom_coeff_rec(i-1,j-1) + Binom_coeff_rec(i-1,j)

def Binom_coeff_mem(table, i, j): #mem for memoized
	# print "i:%s j:%s"%(i,j)
	if j==0 or j==i:
		table[i][j]=1
	else: 

		if table[i-1][j-1]==0:	#means we haven't calculated this one yet
			# print "A"
			table[i-1][j-1]=Binom_coeff_mem(table,i-1,j-1)
		if table[i-1][j]==0:	
			# print "B"
			table[i-1][j]=Binom_coeff_mem(table,i-1,j)
		table[i][j]=table[i-1][j-1] + table[i-1][j]
	for x in table:
		print x
	print ""
	return table[i][j]
		
def Binom_coeff_mem_driver(i, j):
	
	table=[]
	for k in range (0,i+1):
		table.append([0 for k in range(0,i+1)])
	return Binom_coeff_mem(table,i,j)


print Binom_coeff_mem_driver(5,4)

def use_case(n):
	print "N=%s"%n
	s=Stopwatch()
	s.start()
	print Binom_coeff_tab(n, int(n/2))
	print str(s.lap()) +" seconds"

	print Binom_coeff_mem_driver(n, int(n/2))
	print str(s.lap()) +" seconds"

	print Binom_coeff_rec(n, int(n/2))
	print str(s.lap()) +" seconds"
	s.stop()
	print "\n\n"

# s=Stopwatch()
# s.start()
# print "Binomial coefficient of (200,100) by memoization: %s" % Binom_coeff_mem_driver(200,100)
# print "Time taken: %s"%(s.lap())
# print "Binomial coefficient of (200,100) by tabulation: %s" % Binom_coeff_tab(200,100)
# print "Time taken: %s"%(s.lap())
# s.stop()

# use_case(3)
# use_case(10)
# use_case(15)
# use_case(20)
# use_case(25)
# use_case(30)


# for i in range(0,7):
# 	print Binom_coeff_tab(7,i),
# print ""
# for i in range(0,7):
# 	print Binom_coeff_rec(6,i),
