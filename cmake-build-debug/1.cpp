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
void e1(){
    if(f[p] == 'b'){
        p++;
        e2();
    }
void e2(){
    if(f[p] == ' '){
        p++;
        e3();
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
    else{
        rejeita();
    }
}

int main() {
    cin>>f;
    e0();
    return 0;
}