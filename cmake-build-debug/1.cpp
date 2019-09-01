#include <iostream>
using namespace std;

void e0();
void e1();
void e2();

void aceita();
void rejeita();

char f[200];
int p;

void e0(){
    if(f[p] == 'a'){
        p++;
        e1();
    }
	else{
	rejeita();
	}
}
void e1(){
    if(f[p] == 'b'){
        p++;
        e2();
    }
	else{
	rejeita();
	}
}

void e2(){
    if(f[p] == 0){
        p++;
        aceita();
	exit(0);
    } else{
        rejeita();
	exit(0);
    }
}
void aceita(){
    puts("viva!!!");
    exit(0);
}

void rejeita(){
    puts(":c");
    exit(0);
}

int main() {
    cin>>f;
    e0();
    return 0;
}