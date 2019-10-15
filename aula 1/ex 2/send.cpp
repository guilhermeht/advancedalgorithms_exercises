#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

int main(){
    int a, count = 0;
    
    scanf("%d", &a);
    do{
        printf("Scenario #%d\n", count+1);

        queue<int> fila_de_ordem;

        map<int, int> map_elemento; 
        // vector< vector<int> > vector_elemento(a);

        pair<int, int> elemento;
        vector<queue<int> > elemento_added(a);

        // printf("begin\n");
        // printf("size map: %ld\n", map_elemento.size());
        // printf("size elemento_added: %ld\n", elemento_added[0].size());
        // printf("size fila de ordem: %ld\n", fila_de_ordem.size());

        int i, j;
        for(i = 0; i < a; i++){
            int qtde_elementos;
            scanf("%d", &qtde_elementos);
            for(j = 0; j < qtde_elementos; j++){
                int b;
                scanf("%d", &b);
                
                elemento.first = b;
                elemento.second = i;
                map_elemento.insert(elemento);
                // vector_elemento[a].push_back(b);

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
                
                time_of_value = map_elemento[value];
                //time_of_value = get_team(value, elemento_times);
                
                //printf("value: %d, time: %d\n", value, time_of_value);
                // printf("value = %d, time_value = %d, time size: %d\n", value, time_of_value, (int) elemento_added[time_of_value].size());
                if(elemento_added[time_of_value].size() == 0){
                    fila_de_ordem.push(time_of_value);
                    //printf("time: %d added to fila de ordem\n", time_of_value);
                }
                elemento_added[time_of_value].push(value);
            }else if(strcmp("DEQUEUE", key) == 0){
                if(time_to_dequeue == -1 || elemento_added[time_to_dequeue].size() == 0){
                    time_to_dequeue = fila_de_ordem.front();
                    fila_de_ordem.pop();
                    //printf("time %d dequeued\n", time_to_dequeue);
                }
                // printf("dequeue time: %d time size: %d\n", time_to_dequeue, (int) elemento_added[time_to_dequeue].size());
                value = elemento_added[time_to_dequeue].front();
                elemento_added[time_to_dequeue].pop();
                if(elemento_added[time_to_dequeue].size() == 0) time_to_dequeue = -1;
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