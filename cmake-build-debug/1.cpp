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
	else
	if(f[p] == 'b'){
		goto e2;
}
    else{
        p++;
        goto rejeita;
    }

    e1:
    if(f[p] == 'b'){
        p++;
        goto e2;
    }
	else
	if(f[p] == 'b'){
		goto e2;
}
    else{
        p++;
        goto rejeita;
    }

    e2:
    if(f[p] == 0){
        p++;
        goto aceita;
    }
	else
	if(f[p] == 'b'){
		goto e2;
}
    else{
        p++;
        goto rejeita;
    }
    aceita:
        p++;
        puts("aceita");
    
    rejeita:
        p++;
        puts("rejeita");
    }
