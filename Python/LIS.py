# LIS (Longest Increasing Subsequence) Problem:

# Find the length of the longest subsequence of a given sequence:
# such that all elements of the subsequence are sorted in increasing order. 
# For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and the LIS is {10, 22, 33, 50, 60, 80}.

# This is a Dynamic Programming Problem

import random
from misc_functions import Stopwatch
s=Stopwatch()

def LIS(arr): # O(n^2) algorithm...an O(n.log(n)) solution also exists, using binary search.
	lis=[]
	maximum=0
	for i in range(0,len(arr)):  # for (i=0; i<len(arr); i++){
		lis.append(1)
	# print lis

	for i in range(0,len(arr)):
		for j in range(0,i):
			if arr[i]>arr[j] and lis[i]<lis[j]+1:
				lis[i]=lis[j]+1
	# print lis

	maximum=max(lis)
	return maximum
num=1000
num_range=1000
arr=[(i%num_range) for i in range(0,num)]
random.shuffle(arr)
s.start()
print "Length of Longest Increasing Subsequence: %s"%LIS(arr)
print s.stop()