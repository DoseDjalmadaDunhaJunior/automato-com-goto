#include <iostream>
using namespace std;
#include <stdio.h>

int main(){
    char f[200];
    int p = 0;
    printf("Cadeia: ");
    cin>>f;
    goto e0;

    e0:
    if(f[p] == 'a'){
        p++;
        goto e0;
    }
    else
    if(f[p] == 0){
        p++;
        goto aceita;
    }
else{
goto rejeita;
}
    aceita:
    printf("Aceita\n");
    return 0;

    rejeita:
    printf("Rejeita\n");
    return 0;
}
