#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <map>

#define END 1000

using namespace std;

//                  size  sequencia
priority_queue<pair<int, vector<int> > > pilha;
map<vector<int>, int> discovered;

void printv(vector<int> v){
    int size = (int)v.size();
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printforbidden(vector<vector<int> > forbidden){
    int i, size = (int)forbidden.size();
    for(i = 0; i < size; i++){
        printv(forbidden[i]);
    }
}

// !!!!! to sentindo que isso vai dar merda
// Calculates distance from A to B
int distanceAB(int a, int b){
    int sem = abs(b-a);
    if(sem > 5)
        return 10-sem;
    return sem;
}

int charUp(int a){
    if(a == 9)
        return 0;
    else
        return a+1;
}

int charDown(int a){
    if(a == 0)
        return 9;
    else
        return a-1;
}

// copia conteudo de A para o B;
vector<int> cpVector(vector<int> a, vector<int> b){
    b.clear();
    int size = (int)a.size();
    int i;
    for(i = 0; i < size; i++){
        b.push_back(a[i]);
    }
    
    return b;
}

// check if "a" is equal to some of the forbidden vectors
// return: true -> existe vetor igual
//         false -> nao existe vetor igual no forbidden
bool isForbidden(vector<vector<int> > forbidden, vector<int> a){
    int size = (int)forbidden.size();
    int i;
    for(i = 0; i < size; i++){
        if(a == forbidden[i])
            return true;
    }
    return false;
}

void bt(vector<int> begin, vector<int> end, int altura, vector<vector<int> > forbidden){
    if(begin == end){
        printf("%d\n", altura);
        return;
    }
    vector<int> aux;
    // if(altura < END){
    // calculando distancia entre o vetor destino e o begin;
    int i,j;
    aux.clear();
    aux = cpVector(begin, aux);
    
    forbidden.push_back(begin);

    for(i = 0; i < 4; i++){
        int saveElement = aux[i];
        int charToAdd;
        pair<int, vector<int> > p;
        pair<vector<int>, int> mappair;
        pair<map<vector<int>, int>::iterator, bool> ret;
        
        
        charToAdd = charUp(saveElement);
        aux[i] = charToAdd;
        if(!isForbidden(forbidden, aux)){
            int bgtoend_distance = 0;
            for(j = 0; j < 4; j++){
                bgtoend_distance = bgtoend_distance + distanceAB(aux[j], end[j]);        
            }

            // printf("%d, %d :",bgtoend_distance, altura);
            // printv(aux);
            
            mappair.first = aux;
            mappair.second = 0;
            ret = discovered.insert(mappair);
            if(ret.second == true){
                p.first = (altura + bgtoend_distance) * (-1);
                p.second = aux;
                pilha.push(p);
            }
            
        }

        charToAdd = charDown(saveElement);
        aux[i] = charToAdd;
        if(!isForbidden(forbidden, aux)){
            int bgtoend_distance = 0;
            for(j = 0; j < 4; j++){
                bgtoend_distance = bgtoend_distance + distanceAB(aux[j], end[j]);        
            }

            // printf("%d, %d :",bgtoend_distance, altura);
            // printv(aux);
    
            mappair.first = aux;
            mappair.second = 0;
            ret = discovered.insert(mappair);
            if(ret.second == true){
                p.first = (altura + bgtoend_distance) * (-1);
                p.second = aux;
                pilha.push(p);
            }
        }
        aux[i] = saveElement;
    }
    // }
    
    if((int)pilha.size() == 0){
        printf("-1\n");
        return;
    }
    
    int allPeso, onlypeso = 0;
    // aux recebe o proximo elemento da pilha(que eh o que possui menor distancia f(n) = g(n) + h(n) ) --> talvez se multiplicar a distancia por -1, nao precisa mexer com a priority queue ao contrario.
    aux = pilha.top().second;
    
    allPeso = (-1)*pilha.top().first;
    for(j = 0; j < 4; j++){
        onlypeso = onlypeso + distanceAB(aux[j], end[j]);        
    }
    altura = allPeso - onlypeso;
    // printv(aux);
    // printf("%d\n", altura);
    
    pilha.pop();
    bt(aux, end, altura+1, forbidden);
}

int main(){
    int tests;
    scanf("%d", &tests);
    int i;
    for(i = 0; i < tests; i++){
        vector<int> initial;
        vector<int> final;

        pilha = priority_queue<pair<int, vector<int> > > ();  // reset priority queue
        initial.clear();
        final.clear();
        discovered.clear();
        
        int j, value;
        for(j = 0; j < 4; j++){
            scanf("%d", &value);
            initial.push_back(value);
        }

        for(j = 0; j < 4; j++){
            scanf("%d", &value);
            final.push_back(value);
        }
        
        int nforbidden;
        scanf("%d", &nforbidden);
        vector<vector<int> > forbidden(nforbidden);
        for(j = 0; j < nforbidden; j++){
            int k;
            for(k = 0; k < 4; k++){
                scanf("%d", &value);
                forbidden[j].push_back(value);
            }
        }
        
        bt(initial, final, 0 , forbidden);
    }
    
    return 0;
}