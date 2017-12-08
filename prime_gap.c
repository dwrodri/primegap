#include <stdio.h>
#include <stdlib.h>

/*
* n = a number that could be prime
* This function uses a linear-scale algorithm to check for primality
*/
int isPrime(unsigned long long n){

	int outcome = 1;
	for(unsigned long long i = 2; i <= (n/2); i++){ //from 2 to half of n...
			if (n % i == 0){
				outcome--;
				break;
			}//return false if you find a perfect divisor
	}

	return outcome; //otherwise return true

}

/*
* prevPrime : the previous known prime
* This function finds the next prime
*/
unsigned long long  getNextPrime(int prevPrime){

	unsigned long long nextPrime = ++prevPrime;
	while(!isPrime(nextPrime))nextPrime++; //search for nextPrime linearly

	return nextPrime;
}

/*
* THE FUN HAPPENS HERE
*/
int main(int argc, char** argv){

	//assert correct usage
	if(argc != 2){
		printf("Usage ./PrimeGap [num of gaps > 0]");
		return 1;
	}

	const unsigned long long maxPrimeCount = atoi(argv[1]);

	//handle special cases
	//if (maxPrimeCount >= 1) printf("1 ");
	unsigned long long currentPrime = 2; //start from second prime number
	for(register unsigned long long currentPrimeCount = 0; currentPrimeCount < maxPrimeCount; currentPrimeCount++){
		unsigned long long temp = getNextPrime(currentPrime); //temporary holding space for next prime to avoid recalculating;
		unsigned long long primeGap = temp - currentPrime; //this is where the "magic" happens

		printf("%llu\n ", primeGap);
		currentPrime = temp;
	}

	return 0;
}
