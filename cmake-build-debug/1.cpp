#include <iostream>
using namespace std;
#include <stdio.h>

int main(){
    char f[200];
	int ok = 0;
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
     if(f[p] == 'b'){
       goto e1;
  }
    aceita:
    printf("Aceita\n");
    return 0;

    rejeita:
    printf("Rejeita\n");
    return 0;
}
    e1:
    if(f[p] == 'b'){
        p++;
        goto e1;
    }
    else
     if(f[p] == 'a'){
       goto e0;
  }
    aceita:
    printf("Aceita\n");
    return 0;

    rejeita:
    printf("Rejeita\n");
    return 0;
}
