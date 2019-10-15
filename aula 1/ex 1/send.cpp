#include <stdio.h>
#include<iostream>
#include <map>

using namespace std;

int main(){
    char list[256];
    int count = 0, total_sum = 0 ;
    do{
        scanf("%c", &list[count]);
        count++;
    }while(list[count-1] != '\n');
    
    int i;
    for(i = 0; i < count; i++){
        if(total_sum < 0){
            break;
        }
        else{
            if(list[i] == '('){
                total_sum++;
            }else if(list[i] == ')'){
                total_sum--;
            }    
        }
    }
    if(total_sum == 0)
        printf("YES\n");
    else
        printf("NO\n");
}
