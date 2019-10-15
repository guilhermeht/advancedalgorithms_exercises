#include <stdio.h>
#include <vector>
#include <deque> //slack(push_front)
#include <queue> // queue(push), priority queue(push)
#include <map>
#include <string.h>

using namespace std;

int main(){
    int size;
    vector<int> elements;
    vector<int> binary;
    
    // map<int, int> swapable;
    vector<priority_queue<int> > swapable;

    scanf("%d", &size);
    int i, value;
    for(i = 0; i < size; i++){
        scanf("%d", &value);
        elements.push_back(value);
    }
    // casos:
    // anterior = -1 atual = 0 [nao faz nada]
    //               atual = 1 [adiciona atual] xx
    // anterior = 1  atual = 1 [adiciona atual] xx
    //               atual = 0 [adiciona atual] xx
    // anterior = 0  atual = 1 [cria novo e adiciona atual no novo]
    //               atual = 0 [nao faz nada]
    char bin[100];
    scanf("%s", bin);
    int bin_size = (int)strlen(bin);
    int anterior = -1;
    priority_queue<int> a;
    for(i = 0; i < bin_size; i++){
        value = (int)bin[i] - '0';
        binary.push_back(value);
        if((anterior == -1 && value == 1) || (anterior == 1 && value == 1) || (anterior == 1 && value == 0)){ // adiciona atual
            a.push((-1)*elements[i]);
        }else if(anterior == 0 && value == 1){ // cria novo e adiciona atual
            if(a.size() != 0){
                swapable.push_back(a); // adiciona anterior;
                a = priority_queue<int> (); // limpa atual
            }
            a.push((-1)*elements[i]); // adiciona atual no novo
        }
        anterior = value;
    }
    if(anterior == 1){
        a.push((-1)*elements[bin_size]);
    }
    if(a.size() != 0)
        swapable.push_back(a); // adiciona o ultimo
    
    int idx = 0, binary_size = (int)binary.size();
    anterior = -1;
    for(i = 0; i < (int)elements.size(); i++){
        if(i >= binary_size){
            if(anterior == 1){
                elements[i] = (-1)*swapable[idx].top();
                swapable[idx].pop();
            }
        }else if(anterior == -1 && binary[i] == 1){
            elements[i] = (-1)*swapable[idx].top();
            swapable[idx].pop();
        }else if(anterior == 0 && binary[i] == 1){
            elements[i] = (-1)*swapable[idx].top();
            swapable[idx].pop();
        }else if(anterior == 1){
            if(binary[i] == 1){
                elements[i] = (-1)*swapable[idx].top();
                swapable[idx].pop();
            }else if(binary[i] == 0){
                elements[i] = (-1)*swapable[idx].top();
                swapable[idx].pop();
                idx++;                
            }
        }
        anterior = binary[i];
    }
    anterior = -1;
    for(i = 0; i < (int)elements.size(); i++){
        if(anterior > elements[i]){
            printf("NO\n");
            break;
        }else if(i == (int)elements.size()-1)
            printf("YES\n");
        anterior = elements[i];
    }

    return 0;
}
