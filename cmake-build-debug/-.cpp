#include <iostream>
using namespace std;
#include <stdio.h>

int main() {
    char f[200];
    int p = 0;
    printf("Cadeia: ");
    cin >> f;
    goto e0;

    e0:
    if (f[p] == 'a') {
        p++;
        goto e0;
    } else if (f[p] == 'a') {
        goto e1;
    } else if (f[p] == 'b') {
        goto e2;
    } else if (f[p] == 'c') {
        goto e3;
    } else if (f[p] == '0') {
        p++;
        goto aceita;
    } else {
        goto rejeita;
    }
    e1:
    if (f[p] == 'b') {
        p++;
        goto e0;
    } else if (f[p] == 'a') {
        goto e1;
    } else if (f[p] == 'b') {
        goto e2;
    } else if (f[p] == 'c') {
        goto e3;
    } else if (f[p] == '0') {
        p++;
        goto aceita;
    } else {
        goto rejeita;
    }
    e2:
    if (f[p] == 'c') {
        p++;
        goto e0;
    } else if (f[p] == 'a') {
        goto e1;
    } else if (f[p] == 'b') {
        goto e2;
    } else if (f[p] == 'c') {
        goto e3;
    } else if (f[p] == '0') {
        p++;
        goto aceita;
    } else {
        goto rejeita;
    }
    e3:
    if (f[p] == ' ') {
        p++;
        goto e0;
    } else if (f[p] == 'a') {
        goto e1;
    } else if (f[p] == 'b') {
        goto e2;
    } else if (f[p] == 'c') {
        goto e3;
    } else if (f[p] == '0') {
        p++;
        goto aceita;
    } else {
        goto rejeita;
    }
    aceita:
    printf("Aceita\n");
    return 0;

    rejeita:
    printf("Rejeita\n");
    return 0;
}
