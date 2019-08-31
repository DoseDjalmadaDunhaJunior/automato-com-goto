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
    else if(f[p] == 'c'){
        p++;
        goto e3;
    }
    else if(f[p] == 'e'){
        p++;
        goto e4;
    }
    else if(f[p] == 'i'){
        goto e0;
    }
    else if(f[p] == '\0'){
        p++;
        goto aceita;
    }
    else{
        goto rejeita;
    }

    e1:
    if(f[p] == 'a'){
        p++;
        goto e1;
    }
    else if(f[p] == 'b'){
        p++;
        goto e2;
    }
    else if(f[p] == 'c'){
        p++;
        goto e3;
    }
    else if(f[p] == '\0'){
        p++;
        goto aceita;
    }
    else{
        goto rejeita;
    }
    e2:
    if(f[p] == 'a'){
        p++;
        goto e1;
    }
    else if(f[p] == 'b'){
        p++;
        goto e2;
    }
    else if(f[p] == 'c'){
        goto e3;
    }
    else if (f[p] == '\0'){
        goto aceita;
    } else{
        goto rejeita;
    }

    e3:
    if(f[p] == 'c'){
        p++;
        goto e3;
    }
    else if(f[p] == 'a'){
        p++;
        goto e1;
    }
    else if(f[p] == 'b'){
        p++;
        goto e2;
    }
    e4:
    if(f[p] == 'l'){
        p++;
        goto e0;
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