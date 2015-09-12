#EditDistance.py
import pickle
import time
# from misc_functions import Stopwatch


def EditDistance(wordx, wordy, insert_penalty=1, delete_penalty=1, substitution_penalty=1, printing=True):
	# finds the minimum edit distance between words x and y
	# we do this by converting x into y; the cost is the same as converting y to x
	# we can set the penalties, so that we can take into account more expensive insert, delete and replacement penalites
	big_number=max(len(wordx), len(wordy)) + 1
	mat =[]
	for i in range (0,len(wordx)+1):
		mat.append([-1 for x in range(0,len(wordy)+1)])
	
	for i in range(0,len(wordx)+1):
		mat[i][0]=i
	for j in range(0,len(wordy)+1):
		mat[0][j]=j

	for i in range(1,len(wordx)+1):
		for j in range(1,len(wordy)+1):
			if(wordx[i-1]==wordy[j-1]):
				mat[i][j]=mat[i-1][j-1]
			else:
				from_left= mat[i][j-1] + insert_penalty
				from_top= mat[i-1][j] + delete_penalty
				from_top_left= mat[i-1][j-1] + substitution_penalty
				mat[i][j]=min(from_left, from_top, from_top_left)

			
	if printing:
		print "Edit Distance: %s"%mat[len(wordx)-1][len(wordy)-1]
		for i in range (0,len(wordx)+1):
			print mat[i]		
	return mat[len(wordx)][len(wordy)]

EditDistance('SUNDAY','SATURDAY',1,1,1.5)
	
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





