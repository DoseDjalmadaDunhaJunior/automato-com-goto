#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    char f[200];
    int p = 0;
    printf("Cadeia: ");
    cin>>f;
    goto e0;

    e0:
    if(f[p] == 'a'){
        p++;
        goto e1;
    }
    else if(f[p] == 'b'){
        p++;
        goto e2;
    }
    else{
        goto rejeita;
    }

    e1:
    if(f[p] == 'a'){
        p++;
        goto rejeita;
    }
    else if(f[p] == 'b'){
        p++;
        goto e2;
    }
    else{
        goto rejeita;
    }
    e2:
    if (f[p] == '\0'){
        goto aceita;
    } else{
        goto rejeita;
    }

    aceita:
    printf("Aceita\n");
    return 0;

    rejeita:
    printf("Rejeita\n");
    return 0;
}