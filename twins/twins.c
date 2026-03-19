#include <stdio.h>
#include <math.h>
#include "twins.h"

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void findTwinPrimes(int limit) {
    printf("\n=== Twin primes up to %d ===\n", limit);
    int found = 0;
    
    for(int i = 2; i <= limit - 2; i++) {
        if(isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
            found = 1;
        }
    }
    
    if(!found) {
        printf("No twin primes found up to %d\n", limit);
    }
}
