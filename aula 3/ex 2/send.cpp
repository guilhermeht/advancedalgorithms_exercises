#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

vector<int> linha; // linha
vector<int> coluna; // coluna
vector<pair<int, int> > added;
vector<pair<int, int> > toPrint;

map<vector<int>, int > m;


void printmap(map<vector<int>, int> solutions){
    map<vector<int>, int>::iterator it;
    int i, sz;
    for(it = solutions.begin(); it != solutions.end(); it++){
        sz = it->first.size();
        for(i = 0; i < sz; i++){
            printf("%d ", it->first[i]);
        }
        printf("\n");
    }
}

int getIndex(vector<int> v, int element){
    int size = (int)v.size();
    int i;
    for(i = 0; i < size; i++){
        if(v[i] == element)
            return i;
    }
    return -1;
}

void printvp(vector<pair<int, int> > vp){
    vector<pair<int, int> >::iterator it;
    
    for(it = vp.begin(); it != vp.end(); it++){
        printf("%d,%d ", it->first, it->second);
    }
    printf("\n");
}

void printv(vector<int> v){
    int i, size = (int)v.size();
    for(i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void cpVector(){
    int size = (int)added.size();
    pair<int, int> p;
    int i;
    for(i = 0; i < size; i++){
        p.first = added[i].first;
        p.second = added[i].second;
        toPrint.push_back(p);
    }
}

// value_i = linha, value_j = coluna
// x = linha, y = coluna
// e = linha, f = coluna
// first = coluna, second = linha
void queens(int n, int x, int y){
    if((int)added.size() == n){
        vector<int> a;
        pair<vector<int>, int> p;
        
        a.clear();
        toPrint.clear();
        
        cpVector();

        sort(toPrint.begin(), toPrint.end());
        int i, size = (int)toPrint.size();
        for(i = 0; i < size; i++){
            a.push_back(toPrint[i].second);
        }
        
        p.first = a;
        p.second = 0;
        m.insert(p);
        
        // printvp(toPrint);
        return;    
    }
    
    int i, j, k;
    int i_size, j_size;
    int valido;
    int value_i, value_j;
    i_size = (int)linha.size();
    j_size = (int)coluna.size();

    for(i = 0; i < i_size; i++){
        value_i = linha[i];
        for(j = 0; j < j_size; j++){
            value_j = coluna[j];
            if(value_i != x && value_j != y){
                valido = 1;
                for(k = 0; k < (int)added.size(); k++){
                    int e, f;
                    f = added[k].first; //linha e, aftr: coluna
                    e = added[k].second; // coluna f, aftr: linha
                    if(abs(value_i - e) == abs(value_j - f)){
                        // lugar invalido
                        valido = 0;
                    }
                }
                if(valido == 1){
                    // value_i e value_j sao validos
                    // adiciona value_i e value_j para adicionados
                    pair<int, int> p;
                    p.first = value_j; // value_i
                    p.second = value_i; // value_j
                    added.push_back(p);
                    // remover value_i e value_j, pois essas linhas e colunas nao sao mais validas
                    int idx_i, idx_j;
                    idx_i = getIndex(linha, value_i);
                    idx_j = getIndex(coluna, value_j);
                    linha.erase(linha.begin() + idx_i);
                    coluna.erase(coluna.begin() + idx_j);
                    
                    // chama recursao
                    queens(n, x, y);
                    
                    // remove value_i e value_j dos adicionados, pois se voltou, nao funciona
                    added.pop_back();

                    // adiciona value_i e value_j, pois se voltou, essas linhas podem ser validas
                    linha.insert(linha.begin() + idx_i, value_i);
                    coluna.insert(coluna.begin() + idx_j, value_j);
                }
            }
        }
    }
    
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int x,y;
        scanf("%d%d", &x, &y);
        // adicionando a primeira rainha
        pair<int, int> p;
        p.first = y;// coluna
        p.second = x;// linha
        added.push_back(p);
    
        int i;
        for(i = 0; i < n; i++){
            linha.push_back(i+1);
            coluna.push_back(i+1);
        }
        
        int idx_i, idx_j;
        idx_i = getIndex(linha, x);
        idx_j = getIndex(coluna, y);
        
        linha.erase(linha.begin() + idx_i);
        coluna.erase(coluna.begin() + idx_j);
        
        printf("Solution\n");
        queens(n, x, y);
        
        printmap(m);
        m.clear();
        linha.clear();
        coluna.clear();
        added.clear();
    }

    return 0;
}