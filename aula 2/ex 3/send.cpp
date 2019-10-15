#include <stdio.h>
#include <vector>
#include <deque> //slack(push_front)
#include <queue> // queue(push), priority queue(push)
#include <map>
#include <string.h>

using namespace std;

int main(){
    map<int,int> registers;
    map<int,int>::iterator register_it;
    pair<int,int> p;
    char op[20];
    int id, period;
    scanf("%s",op);
    do{
        if(strcmp(op, "Register") == 0){
            scanf("%d %d", &id, &period);
            p.first = id;
            p.second = period;
            registers.insert(p);
        }else if(strcmp(op, "#") == 0){
            break;
        }
        scanf("%s", op);
    }while(1);
    int i, k, count = 0;
    scanf("%d", &k);
    for(i = 1; count < k; i++){
        for(register_it = registers.begin(); register_it != registers.end(); register_it++){
            if(i%register_it->second == 0 && count < k){
                printf("%d\n", register_it->first);
                count++;
            }
        }
    }

    return 0;
}
