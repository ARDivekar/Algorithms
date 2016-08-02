def binaryAlmostSearch(a, data):
    low = 0
    high = len(a)-1
    while low<=high:
        mid = int((low+high)/2)
        # print "mid:",mid
        if data<a[mid]:
            high = mid-1
        elif data>a[mid]:
            low = mid+1
        else:
            return (mid, None)
    return (high, low)     ## data should be between high & low==high+1

print "\n\n\nChecking various test cases to ensure no index out of bounds:"
print ""
print "binaryAlmostSearch([1,4,6,8,9], 1) : ",binaryAlmostSearch([1,4,6,8,9], 1)
print "binaryAlmostSearch([1,4,6,8,9], 4) : ",binaryAlmostSearch([1,4,6,8,9], 4)
print "binaryAlmostSearch([1,4,6,8,9], 6) : ",binaryAlmostSearch([1,4,6,8,9], 6)
print "binaryAlmostSearch([1,4,6,8,9], 8) : ",binaryAlmostSearch([1,4,6,8,9], 8)
print "binaryAlmostSearch([1,4,6,8,9], 9) : ",binaryAlmostSearch([1,4,6,8,9], 9)
print "binaryAlmostSearch([1,4,6,8,9], 0) : ",binaryAlmostSearch([1,4,6,8,9], 0)
print "binaryAlmostSearch([1,4,6,8,9], 5) : ",binaryAlmostSearch([1,4,6,8,9], 5)
print "binaryAlmostSearch([1,4,6,8,9], 10) : ",binaryAlmostSearch([1,4,6,8,9], 10)
print ""
print "binaryAlmostSearch([1,4,6,8], 1) : ",binaryAlmostSearch([1,4,6,8], 1)
print "binaryAlmostSearch([1,4,6,8], 4) : ",binaryAlmostSearch([1,4,6,8], 4)
print "binaryAlmostSearch([1,4,6,8], 6) : ",binaryAlmostSearch([1,4,6,8], 6)
print "binaryAlmostSearch([1,4,6,8], 8) : ",binaryAlmostSearch([1,4,6,8], 8)
print "binaryAlmostSearch([1,4,6,8], 0) : ",binaryAlmostSearch([1,4,6,8], 0)
print "binaryAlmostSearch([1,4,6,8], 5) : ",binaryAlmostSearch([1,4,6,8], 5)
print "binaryAlmostSearch([1,4,6,8], 10) : ",binaryAlmostSearch([1,4,6,8], 10)
print ""
print "binaryAlmostSearch([1,4,6], 1) : ",binaryAlmostSearch([1,4,6], 1)
print "binaryAlmostSearch([1,4,6], 4) : ",binaryAlmostSearch([1,4,6], 4)
print "binaryAlmostSearch([1,4,6], 6) : ",binaryAlmostSearch([1,4,6], 6)
print "binaryAlmostSearch([1,4,6], 0) : ",binaryAlmostSearch([1,4,6], 0)
print "binaryAlmostSearch([1,4,6], 5) : ",binaryAlmostSearch([1,4,6], 5)
print "binaryAlmostSearch([1,4,6], 10) : ",binaryAlmostSearch([1,4,6], 10)
print ""
print "binaryAlmostSearch([1,4], 1) : ",binaryAlmostSearch([1,4], 1)
print "binaryAlmostSearch([1,4], 4) : ",binaryAlmostSearch([1,4], 4)
print "binaryAlmostSearch([1,4], 0) : ",binaryAlmostSearch([1,4], 0)
print "binaryAlmostSearch([1,4], 3) : ",binaryAlmostSearch([1,4], 3)
print "binaryAlmostSearch([1,4], 10) : ",binaryAlmostSearch([1,4], 10)
print ""
print "binaryAlmostSearch([1], 1) : ",binaryAlmostSearch([1], 1)
print "binaryAlmostSearch([1], 0) : ",binaryAlmostSearch([1], 0)
print "binaryAlmostSearch([1], 10) : ",binaryAlmostSearch([1], 10)
