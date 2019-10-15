#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197};
int count = 0;

bool isPrime(int n){
    int i;
    for(i = 0; i < (int)primes.size(); i++){
        if(primes[i] > n)
            return false;
        if(primes[i] == n)
            return true;
    }
    return false;
}

void printv(vector<int> asd){
    int i;
    int size = (int)asd.size();
    for(i = 0; i < size; i++){
        printf("%d ", asd[i]);
    }
    printf("\n");
}

void bt(vector<int> v, int n, int idx, vector<int> available){
    if(idx == n){
        printv(v);
    }
        
    int i;
    for(i = 1; i < n; i++){
        if(available[i] != -1){
            v[idx] = available[i];
            if(idx == (n-1)){
                if(isPrime(v[idx]+v[idx-1]) && isPrime(v[idx]+v[0])){
                    available[i] = -1;
                    bt(v, n, idx+1, available);
                    available[i] = v[idx];
                }
            }else if(isPrime(v[idx]+v[idx-1])){
                available[i] = -1;
                bt(v, n, idx+1, available);
                available[i] = v[idx];
            }
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(count > 0)
            printf("\n");
        printf("Case %d:\n", count+1);
        vector<int> available;
        vector<int> v(n);
        v[0] = 1;
        int i;
        for(i = 0; i < n; i++){
            available.push_back(i+1);
        }
        available[0] = -1; // 1, pois ja foi utilizado (-1 = ja usado)
        
        bt(v, n, 1, available);
        count++;
    };
    
    return 0;
}
