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
        p++;
        goto e2;
    }

	else
	if(f[p] == 'c'){
        p++;
        goto rejeita;
    }

	else{
        goto rejeita;
    }

    e1:
    if(f[p] == 'b'){
        p++;
        goto e3;
    }

	else
	if(f[p] == 'c'){
        p++;
        goto rejeita;
    }

	else{
        goto rejeita;
    }

    e2:
    if(f[p] == 'c'){
        p++;
        goto e3;
    }

	else
	if(f[p] == 'b'){
        p++;
        goto rejeita;
    }

	else{
        goto rejeita;
    }

    e3:
    if(f[p] == 0){
        p++;
        goto aceita;
    }

	else
	if(f[p] == 'b'){
        p++;
        goto rejeita;
    }

	else
	if(f[p] == 'c'){
        p++;
        goto rejeita;
    }

	else{
        goto rejeita;
    }

    rejeita:
    puts(":C");
    return 0;

    aceita:
    puts("aceitou!!!");
    }
