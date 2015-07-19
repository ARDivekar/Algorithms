# prime_compute.py

n=10000000
list_of_primes=[2]
for i in range(3, n+1):
	# print  "\n\t"+str(i)
	is_prime=True
	for j in list_of_primes:
		if j>int(pow(i,0.5)) +1:
			break
		# print j
		if i%j==0:
			is_prime=False
			break
	if is_prime:
		list_of_primes.append(i)

print len(list_of_primes)