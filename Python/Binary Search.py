def binarySearch(a, data):
    low = 0
    high = len(a)-1
    while low<=high:
        mid = int((low+high)/2)
        if data<a[mid]:
            high = mid-1
        elif data>a[mid]:
            low = mid+1
        else:
            return mid
    return -1     ## data should be between high & low==high+1

print "\n\n\nChecking various test cases to ensure no index out of bounds:"
print ""
print "binarySearch([1,4,6,8,9], 1) : ",binarySearch([1,4,6,8,9], 1)
print "binarySearch([1,4,6,8,9], 4) : ",binarySearch([1,4,6,8,9], 4)
print "binarySearch([1,4,6,8,9], 6) : ",binarySearch([1,4,6,8,9], 6)
print "binarySearch([1,4,6,8,9], 8) : ",binarySearch([1,4,6,8,9], 8)
print "binarySearch([1,4,6,8,9], 9) : ",binarySearch([1,4,6,8,9], 9)
print "binarySearch([1,4,6,8,9], 0) : ",binarySearch([1,4,6,8,9], 0)
print "binarySearch([1,4,6,8,9], 5) : ",binarySearch([1,4,6,8,9], 5)
print "binarySearch([1,4,6,8,9], 10) : ",binarySearch([1,4,6,8,9], 10)
print ""
print "binarySearch([1,4,6,8], 1) : ",binarySearch([1,4,6,8], 1)
print "binarySearch([1,4,6,8], 4) : ",binarySearch([1,4,6,8], 4)
print "binarySearch([1,4,6,8], 6) : ",binarySearch([1,4,6,8], 6)
print "binarySearch([1,4,6,8], 8) : ",binarySearch([1,4,6,8], 8)
print "binarySearch([1,4,6,8], 0) : ",binarySearch([1,4,6,8], 0)
print "binarySearch([1,4,6,8], 5) : ",binarySearch([1,4,6,8], 5)
print "binarySearch([1,4,6,8], 10) : ",binarySearch([1,4,6,8], 10)
print ""
print "binarySearch([1,4,6], 1) : ",binarySearch([1,4,6], 1)
print "binarySearch([1,4,6], 4) : ",binarySearch([1,4,6], 4)
print "binarySearch([1,4,6], 6) : ",binarySearch([1,4,6], 6)
print "binarySearch([1,4,6], 0) : ",binarySearch([1,4,6], 0)
print "binarySearch([1,4,6], 5) : ",binarySearch([1,4,6], 5)
print "binarySearch([1,4,6], 10) : ",binarySearch([1,4,6], 10)
print ""
print "binarySearch([1,4], 1) : ",binarySearch([1,4], 1)
print "binarySearch([1,4], 4) : ",binarySearch([1,4], 4)
print "binarySearch([1,4], 0) : ",binarySearch([1,4], 0)
print "binarySearch([1,4], 3) : ",binarySearch([1,4], 3)
print "binarySearch([1,4], 10) : ",binarySearch([1,4], 10)
print ""
print "binarySearch([1], 1) : ",binarySearch([1], 1)
print "binarySearch([1], 0) : ",binarySearch([1], 0)
print "binarySearch([1], 10) : ",binarySearch([1], 10)
