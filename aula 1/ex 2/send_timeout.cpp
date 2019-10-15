#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

void print_elementos(vector<vector<int> > v, int numero_de_times){
    int i;
    vector<int>::iterator it;
    for(i = 0; i < numero_de_times; i++){
        for(it=v[i].begin(); it!=v[i].end(); it++){
            printf("%d ", (*it));
        }
        printf("\n");    
    }
}

int main(){
    int a, i, j, count = 0;
    char c;
    queue<int> fila_de_ordem;
    
    scanf("%d", &a);
    do{
        printf("Scenario #%d\n", count+1);
        //vector<vector<int> > elemento_times(a);
        map<int, int> map_elemento;
        pair<int, int> elemento;
        vector<queue<int> > elemento_added(a);
        
        for(i = 0; i < a; i++){
            int qtde_elementos;
            scanf("%d", &qtde_elementos);
            for(j = 0; j< qtde_elementos; j++){
                int b;
                scanf("%d%c", &b, &c);
                
                elemento.first = b;
                elemento.second = i;
                map_elemento.insert(elemento);
                
                //elemento_times[i].push_back(b);
                //printf("%d ", b);
            }
            //printf("\n");
        }
        
        char key[100];
        int value, time_of_value, time_to_dequeue = -1;
        scanf("%s", key);
        while(strcmp(key, "STOP") != 0){
            if(strcmp("ENQUEUE", key) == 0){
                scanf("%d", &value);
                //printf("value: %d\n", value);
                
                time_of_value = map_elemento[value];
                //time_of_value = get_team(value, elemento_times);
                
                //printf("value: %d, time: %d\n", value, time_of_value);
                if(elemento_added[time_of_value].size() == 0){
                    fila_de_ordem.push(time_of_value);
                    //printf("time: %d added to fila de ordem\n", time_of_value);
                }
                elemento_added[time_of_value].push(value);
            }else if(strcmp("DEQUEUE", key) == 0){
                //printf("DEQUEUE\n");
                if(time_to_dequeue == -1 || elemento_added[time_to_dequeue].size() == 0){
                    time_to_dequeue = fila_de_ordem.front();
                    fila_de_ordem.pop();
                    //printf("time %d dequeued\n", time_to_dequeue);
                }
                //printf("dequeue time: %d\n", time_of_value);
                value = elemento_added[time_to_dequeue].front();
                elemento_added[time_to_dequeue].pop();
                printf("%d\n", value);
            }
            scanf("%s", key);
        }
        printf("\n");
        scanf("%d", &a);
        count++;
    }while(a != 0);
    return 0;
}