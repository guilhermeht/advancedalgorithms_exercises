#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int tam;
int change;

int finalA = tam, finalB = tam, finalC = tam;
map<vector<int>, int> alreadyDone;

int maximo(int a, int b, int c){
    int ret;
    ret = max(max(a,b),c);
    return ret;
}

bool primeira(int x, int y, int z, int result){
    if((x+y+z) == result)
        return true;
    return false;
}

bool segunda(int x, int y, int z, int result){
    if( (x*y*z) == result)
        return true;
    return false;
}

bool terceira(int x, int y, int z, int result){
    if((int)(pow(x,2)+pow(y,2)+pow(z,2)) == result)
        return true;
    return false;
}

void bt(int a, int b, int c){
    int i, j, k;
    vector<int> v;
    pair<vector<int>, int> p;
    std::pair<std::map<vector<int>, int>::iterator,bool> ret;
    for(i = 1; i <= tam; i++){
        for(j = 1; j <= tam; j++){
            for(k = 1; k <= tam; k++){
                v.clear();
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                sort(v.begin(), v.end());
                p.first = v;
                p.second = 0;
                ret = alreadyDone.insert(p);
                if(ret.second == true){
                    if(primeira(i, j, k, a) == true){
                        if(segunda(i, j, k, b) == true){
                            if(terceira(i, j, k, c) == true){
                                if(finalA > i){
                                    finalA = i;
                                    finalB = j;
                                    finalC = k;
                                    change = 1;
                                }else if(finalA == i){
                                    if(finalB > j){
                                        finalA = i;
                                        finalB = j;
                                        finalC = k;
                                        change = 1;
                                    }                            
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(change == 0)
        printf("No solution.\n");
    
}

int main(){
    int samples, i;
    scanf("%d", &samples);
    for(i = 0; i < samples; i++){
        change = 0;
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        tam = maximo(a,b,c);
        bt(a, b, c);
        if(change == 1)
            printf("%d %d %d\n", finalA, finalB, finalC);
        finalA = tam;
        finalB = tam;
        finalC = tam;
        alreadyDone.clear();
    }

    return 0;
}