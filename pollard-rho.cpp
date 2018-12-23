/* PollardRho O(n^(1/4))
 * returns a prime divisor */
long long int PollardRho(long long int n) { 
	srand (time(NULL)); 

	if (n==1) return n; 
	if (n % 2 == 0) return 2; 

	/* we will pick from the range [2, N) */
	long long int x = (rand()%(n-2))+2; 
	long long int y = x; 

	/* the constant in f(x). 
	* Algorithm can be re-run with a different c 
	* if it throws failure for a composite. */
	long long int c = (rand()%(n-1))+1; 

	/* Initialize candidate divisor (or result) */
	long long int d = 1; 

	/* until the prime factor isn't obtained. 
	If n is prime, return n */
	while (d==1) 
	{ 
		/* Tortoise Move: x(i+1) = f(x(i)) */
		x = (pow1(x, 2, n) + c + n)%n; 

		/* Hare Move: y(i+1) = f(f(y(i))) */
		y = (pow1(y, 2, n) + c + n)%n; 
		y = (pow1(y, 2, n) + c + n)%n; 

		/* check gcd of |x-y| and n */
		d = __gcd(abs(x-y), n); 

		if (d==n) return PollardRho(n); 
	} 

	return d; 
} 
