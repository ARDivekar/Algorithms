#EditDistance.py
import pickle
import time
from misc_functions import Stopwatch



def EditDistance(wordx, wordy, insert_penalty=1, delete_penalty=1, substitution_penalty=1, printing=True):
	# finds the minimum edit distance between words x and y
	# we do this by converting x into y; the cost is the same as converting y to x
	# we can set the penalties, so that we can take into account more expensive insert, delete and replacement penalites
	big_number=max(len(wordx), len(wordy)) + 1
	mat =[]
	for i in range (0,len(wordx)):
		mat.append([big_number for x in range(0,len(wordy))])
	
	
	for i in range(0,len(wordx)):
		for j in range(0,len(wordy)):
			if i==0 and j==0:   # base case
				if wordx[0]==wordy[0]:
					mat[0][0]=0
				else:
					mat[0][0]=min(substitution_penalty, insert_penalty+delete_penalty)
			
			# base case: 
			elif i==0 :   
				mat[i][j]=j
			elif j==0 :   
				mat[i][j]=i
			

			else: 
				delete_now_cost=mat[i-1][j] + delete_penalty
				insert_now_cost=mat[i][j-1] + insert_penalty
				if wordx[i]==wordy[j]:
					substitute_now_cost = mat[i-1][j-1]
				else:
					substitute_now_cost = mat[i-1][j-1] + substitution_penalty
				mat[i][j]=min([delete_now_cost,insert_now_cost,substitute_now_cost])

	if printing:
		print "Edit Distance: %s"%mat[len(wordx)-1][len(wordy)-1]
		for i in range (0,len(wordx)):
			print mat[i]		
	return mat[len(wordx)-1][len(wordy)-1]

# EditDistance('Alakazam','Abracadabra')
	
def MinEditDistance(word, dictionary, printing=True):
	closest_words=[]
	min_dist=len(word)
	for i in dictionary:
		if len(i)>min_dist:
			min_dist=len(i)
	min_dist+=1
	# print min_dist
	for i in dictionary:
		distance=EditDistance(wordx=word,wordy=i, printing=False)
		# print i, distance
		if distance==min_dist:
			closest_words.append(i)
		if distance<min_dist:
			closest_words=[]
			closest_words.append(i)
			min_dist=distance
	if printing:
		for i in closest_words:
			print "\n",i
			EditDistance(wordx=word,wordy=i, printing=True)
	print "\n\nWords closes to '%s': %s"%(word, closest_words)
	print "MinEditDistance: %s"%min_dist





