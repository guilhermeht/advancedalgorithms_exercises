#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    pair<vector<int>, int> p;
    map<vector<int>, int> m;
    map<vector<int>, int>::iterator it;
    vector<int> v;
    std::pair<std::map<vector<int>,int>::iterator, bool> ret;
    
    // debug
    // vector<int>::iterator it2;

    int number;
    scanf("%d", &number);
    do{
        int i;
        int a,b,c,d,e;
        for(i = 0; i < number; i++){
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            v.push_back(d);
            v.push_back(e);
            sort(v.begin(), v.end());
            
            // for(it2 = v.begin(); it2 != v.end(); it2++){
            //     printf("%d ",*it2);
            // }
            // printf("\n");
            
            p.first = v;
            p.second = 0;
            
            ret = m.insert(p);
            if(ret.second == true){ //new
                m[v] = 1;
            }
            else{ //old 
                m[v] = m[v] + 1;
            }
            // printf("second: %d\n",m[v]);
            v.clear();
        }
        int max_combination = 0, total = 0;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second > max_combination){
                max_combination = it->second;
                total = it->second;
            }else if(it->second == max_combination){
                total = total + it->second;
            }
        }
        printf("%d\n", total);
        m.clear();
        scanf("%d", &number);
    }while(number != 0);
    
    return 0;
}