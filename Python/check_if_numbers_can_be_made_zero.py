'''
 Given an array of +ve as well as -ve numbers, find out whether it is possible or not to convert it to 0 by adding/subtracting operations on all the elements.

e.g arr[]={1,2,3}
YES (1+2-3)

arr[]={3,6,2}
3+6-2 != 0
3-6-2 !=0
-3-6-2 !=0
-3-6+2 !=0
-3+6-2 !=0
-3+6+2 !=0
3-6+2 !=0
3+6+2 !=0

Hence ans= NO
'''
import random

def isFeasible(A, p, _sum):
  if p == len(A):
    if _sum==0:
      return True
    else: return False;

  return (isFeasible(A, p+1, _sum+A[p]) or isFeasible(A, p+1, _sum-A[p])) 
  


def try_XOR(A):
  XOR=0
  for x in range(0,len(A)):

    XOR=XOR^x
    print bin(XOR)

  
    


def driver(arr):
  print isFeasible(arr,0,0)
  try_XOR(arr)



arr=[1,3,3,4,5,7,3,7,3,1,4,6,2,7,2,4,5,3,6,3,6,3,7,3,7,6,8,9,2,0,4,5,3,6,10,10,1,1,3,13,5]
arr=[random.randrange(0,10) for i in range(0,4)]
print arr
driver(arr)




