# sorting.py
import random
from misc_functions import Stopwatch
from text_manip import num_to_words
from sys import argv
import time
if len(argv)>1:
	script, sort_type=argv
else:
	sort_type=None




def quicksort(a, lb=None, ub=None, random_pivot=True):
	if lb==None: lb=0
	if ub==None: ub=len(a)-1
	if lb<ub:
		i=lb
		j=ub
		pivpos=lb
		if random_pivot:
			# print "\n\n"
			# print a[lb:ub+1]
			pivpos=random.randrange(lb, ub+1)
			# print "lb: %s, ub: %s, pivpos: %s"%(lb, ub, pivpos)
			a[lb],a[pivpos]=a[pivpos],a[lb]
			# print a[lb:ub+1]
		pivot=a[lb]
		# print "pivot: %s"%pivot
		while i<j:
			i+=1
			while i<=ub and a[i]<pivot:
				i+=1
			while j>=lb and a[j]>pivot:
				j-=1
			if i<j:
				a[i],a[j]=a[j],a[i] 	# Python swap

		a[j],a[lb]=a[lb],a[j]
		# print a[lb:ub+1]
		quicksort(a,lb,j-1)
		quicksort(a,j+1,ub)






def mergesort(a):
	size = 1
	leng=len(a)
	while size<leng:
		# print "size: %s"%size
		l1=0 
		aux=[]
		while l1+size<leng:
			l2=l1+size
			u1=l2-1
			u2=-1
			if (l2+size-1) <leng:
				u2=l2+size-1
			else: u2=leng-1

			i=l1
			j=l2
			while i<=u1 and j<=u2:
				if a[i] <=a[j]:
					aux.append(a[i])
					i+=1
				else: 
					aux.append(a[j])
					j+=1
			
			while i<=u1:
				aux.append(a[i])
				i+=1
			while j<=u2:
				aux.append(a[j])
				j+=1

			l1=u2+1

		while l1<leng:
			aux.append(a[l1])
			l1+=1
		for i in range(0,leng):
			a[i]=aux[i]
		size=size*2




	
def merge(a,p,m,q):
	i=p
	j=m+1
	aux=[]
	while i<=m and j<=q:
		if a[i]<=a[j]:
			aux.append(a[i])
			i+=1
		else:
			aux.append(a[j])
			j+=1
	while i<=m:
		aux.append(a[i])
		i+=1
	while j<=q:
		aux.append(a[j])
		j+=1
	x=0
	while x+p<=q:
		a[x+p]=aux[x] # copy back
		x+=1

	

def mergesort_rec(a,p=None,q=None):
	if p==None: p=0
	if q==None: q=len(a)-1

	if p<q:
		if p==q-1:
			if a[p]>a[q]:
				a[p],a[q]=a[q],a[p]
		else:
			m=int((p+q)/2)		
			mergesort_rec(a,p=p,q=m)
			mergesort_rec(a,p=m+1,q=q)
			merge(a,p,m,q)





def heapify(a, i, last):
	k=2*i+1
	while k<last:
		if k+1<last and a[k]<a[k+1]:
			k+=1
		if a[i]<a[k]:
			a[i],a[k]=a[k],a[i]
			i=k
			k=2*k+1
		else: 
			break


def heapsort(a):
	i=int(len(a)/2 -1)
	while i>=0:
		heapify(a,i,len(a))
		i-=1
	i=len(a)-1
	while i>0:
		a[0],a[i]=a[i],a[0]
		heapify(a,0,i)
		i-=1











def is_sorted(a, ascending=True):
	if ascending:
		for i in range(0,(len(a)-1)):
			if a[i]>a[i+1]:
				return False
		return True
	else:
		for i in range(0,len(a)-1):
			if a[i]<a[i+1]:
				return False
		return True


def sort(num, num_range=None, sort=None, print_arrays=False, timed=False, print_time=False):
	if num_range==None: 
		num_range=num

	if timed:
		s=Stopwatch()
		s.start()

	a=[(i%num_range) for i in range(0,num)]
	if timed:
		build_array_time=s.lap()
		if print_time:
			print " Time to build array of %s elements, range 0-%s: %s"%(num_to_words(num), num_to_words(num_range), float(build_array_time))

	random.shuffle(a)
	if timed:
		shuffle_time=s.lap()
		if print_time:
			print " Time to shuffle array: %s"%float(shuffle_time)

	if print_arrays:
		print "\n Unsorted:\n %s"%a

	if sort is not None:
		if sort.lower()=="mergesort":
			mergesort(a)
		if sort.lower()=="quicksort":
			quicksort(a)
		if sort.lower()=="mergesort_rec":
			mergesort_rec(a)
		if sort.lower()=="heapsort":
			heapsort(a)
	else:
		# something I made from test data...
		if float(num)/float(num_range) > 6 and num<=50000 :
			mergesort(a)
			sort="mergesort"
		elif float(num)/float(num_range) < 100 and num>=50000 and num<500000:
			quicksort(a)
			sort="quicksort"
		else: 
			mergesort(a)
			sort="mergesort"

	if timed:
		sort_time=s.lap()
		if print_time:
			print " Time to sort array: %s"%float(sort_time)
		s.stop()


	if print_arrays:
		print "\n Sorted:\n %s"%a

	# print "\n Sorted: %s"%is_sorted(a)
	# print "Used: %s"%sort
	if timed: 
		return sort_time
	

total_time=0
num=1000
for i in range(1,num+1):
	total_time+=sort(num=100000, num_range=10000, timed = True, print_time=False, sort=sort_type)
	avg_time=float(total_time)/i
	print "\rCurrent:",i,"avg_time:",avg_time,


print "\n\navg_time: %s"%avg_time