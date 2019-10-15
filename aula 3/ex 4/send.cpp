#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

vector<int> result;
vector<int> toPrint;
map<vector<int>, int> m;

void printv(vector<int> v){
    int size = (int)v.size();
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printmap(map<vector<int>, int> m){
    map<vector<int>, int>::reverse_iterator it;
    int size, i;
    for(it = m.rbegin(); it != m.rend(); it++){
        size = (int)it->first.size();
        for(i = 0; i < size; i++){
            if(i == (size - 1))
                printf("%d\n", it->first[i]);
            else
                printf("%d+", it->first[i]);
        }
    }

}

int bt(vector<int> v, int sum, int t){
    if((int)v.size() == 0)
        return 1;
    if(sum > t){
        return 2;
    }
    if(sum == t){
        // copiando result para toPrint, para ordenaçao
        toPrint.clear();
        vector<int>::iterator it;
        for(it = result.begin(); it != result.end(); it++){
            toPrint.push_back(*it);
        }
        
        sort(toPrint.rbegin(), toPrint.rend());

        pair<vector<int>, int> p;
        p.first = toPrint;
        p.second = 0;
        
        m.insert(p);
        return 3;
    }
    int i, size = (int)v.size();
    int save;
    for(i = 0; i < size; i++){
        // save = v.back();
        save = v[i];

        // v.pop_back();
        v.erase(v.begin() + i);

        result.push_back(save);

        // chama recursao
        bt(v, sum+save, t);

        result.pop_back();
        // v.push_back(save);
        v.insert(v.begin()+i, save);
    }
    return 0;
}

int main(){
    int total, n;
    scanf("%d%d", &total, &n);
    do{
        printf("Sums of %d:\n", total);
        int i, element;
        vector<int> v;
        for(i = 0; i < n; i++){
            scanf("%d", &element);
            v.push_back(element);
        }

        bt(v, 0, total);
        
        if((int)m.size() != 0){
            printmap(m);
        }
        else{
            printf("NONE\n");
        }
        
        v.clear();
        m.clear();
        result.clear();
        scanf("%d%d", &total, &n);
    }while(n != 0);

    return 0;
}