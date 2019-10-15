#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> vi;

// sieve of erathostenes
vi getPrimes(int n){
    vi primes(n, 1); //set all to 1 (set all as primes)
    primes[0] = 0;
    primes[1] = 0; // not primes
    int i,j;
    for(i = 2; i <= n; i++){
        if(primes[i] == 1){
            for(j = 2; j*i <= n; j++){
                primes[i*j] = 0;
            }
        }
    }
    return primes;
}

int reverse(int a){
    int rev = 0;
    while(a != 0){
        rev = rev * 10;
        rev = rev + a%10;
        a = a/10;
    }
    return rev;   
}

int isPrimeFromVector(vi vector, int value){
    int eulav = reverse(value);
    if(vector[value] == 1){
        if(vector[eulav] == 1){
            if(eulav==value)
                return 1;
            return 2;
        }
        else{
            return 1;
        }
    }else{
        return 0;
    }
}

int main(){
    vi primes;
    primes = getPrimes(1000000); // 1 million
    int n;
    while(scanf("%d", &n) != EOF){
        int a = isPrimeFromVector(primes, n);
        if(a == 2)
            printf("%d is emirp.\n",n);
        else if(a == 1)
            printf("%d is prime.\n",n);
        else if(a == 0)
            printf("%d is not prime.\n",n);
    }
    return 0;
}