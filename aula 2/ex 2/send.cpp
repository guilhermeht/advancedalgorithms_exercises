#include <stdio.h>
#include <vector>
#include <deque> //slack(push_front)
#include <queue> // queue(push), priority queue(push)
#include <string.h>

using namespace std;

int main(){
    int times;
    scanf("%d", &times);
    do{
        int i, op, check;
        int check_pq = 0, check_q = 0, check_sl = 0;
        
        priority_queue<int> pq;
        queue<int> q;
        deque<int> sl;
        
        for(i = 0; i < times; i++){
            scanf("%d%d", &op, &check);

            if(op == 1){ //throw check
                if(!check_pq)
                    pq.push(check);
                if(!check_q)
                    q.push(check);
                if(!check_sl)
                    sl.push_front(check);

            }else if(op == 2){ //take out and check
                if(pq.size() == 0)
                    check_pq = 1;
                if(q.size() == 0)
                    check_q = 1;
                if(sl.size() == 0)
                    check_sl = 1;
                
                int out;
                if(!check_pq){ //top e pop
                    out = pq.top();
                    pq.pop();
                    if(out != check)
                        check_pq = 1;
                }
                if(!check_q){ // front e pop
                    out = q.front();
                    q.pop();
                    if(out != check)
                        check_q = 1;
                }
                if(!check_sl){ // front e pop_front
                    out = sl.front();
                    sl.pop_front();
                    if(out != check)
                        check_sl = 1;
                }    
            }
        }
        int general_sum = check_pq+check_q+check_sl;
        if(general_sum == 3){
            printf("impossible\n");
        }else if(general_sum ==  2){
            if(!check_pq)
                printf("priority queue\n");
            else if(!check_q)
                printf("queue\n");
            else if(!check_sl)
                printf("stack\n");
        }else{
            printf("not sure\n");
        }
    }while(scanf("%d", &times) != EOF);
    
    return 0;
}
