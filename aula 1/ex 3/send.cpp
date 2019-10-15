#include <stdio.h>
#include <map>

using namespace std;

int main(){
    int elemento, qtde;
    char temp;
    pair<int, int> p;
    map<int, int> m;
    map<int, int>::iterator it;
 
    scanf("%d", &qtde);
    int i;
    for(i = 0 ; i < qtde; i++){
        scanf("%d%c", &elemento, &temp);
        p.first = elemento;
        p.second = 0;
        
        m.insert(p);
    }
    int count = 0;
    for(it = m.begin(); it != m.end(); it++){
        count++;
    }
    printf("%d\n", count);
}
