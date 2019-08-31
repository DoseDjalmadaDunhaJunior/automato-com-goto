#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ponto{
    int es;
    char l1;
    char l2;
    char l3;
};

typedef struct ponto e;

char sig[200]; // simblos
int Q; //quantidade de estados
int S[200][200]; // matriz
int qo; // caso de entrada
int F; // quantidade de casos finais
int fin[200]; // casos finais
FILE *arq;

void questionario () {
    int n, m;
    char aux;
    puts("quantos simbolos?");
    scanf("%i", &n);
    m = n;
    puts("quais simbolos?");
    for (int i = 0; i < n; i++) {
        cin >> aux;
        sig[i] = aux;
    }
    puts("quantos estados?");
    scanf("%i", &Q);
    puts("quantos estados finais?");
    scanf("%i", &F);
    puts("quais os estados finais");
    for (int j = 0; j < F; j++) {
        scanf("%i", &n);
        fin[j] = n;
    }
    puts("qual o estado inicial?");
    scanf("%i", &qo);

    for (int k = 0; k < Q; k++) {
        for (int i = 0; i < m; i++) {
            printf("do estado e%i com '%c' qual simbolo faz esse caminho?\n", k, sig[i]);
            scanf("%i", &n);
            S[k][i] = n;
        }
    }
    puts("impressao");
    printf("quant simbulos: %i\n"
           "n estados: %i\n"
           "n estados finais %i\n", m, Q, F);
    puts("estados finais");
    for (int i1 = 0; i1 < Q; i1++) {
        cout << fin[i1] << " ";
    }
    puts("");
    printf("S | ");
    for (int j1 = 0; j1 < m; j1++) {
        cout << sig[j1] << " ";
    }
    puts("");
    for (int l = 0; l < Q; l++) {
        printf("e%i ", l);
        for (int i = 0; i < m; i++) {
            printf(" %i", S[l][i]);
        }
        puts("");
    }
    char nome[100];
    int op = 0;//opcao para funcao ou goto
    puts("voce prefere gerar um programa com goto(1) ou com funcao(2) ?");
    scanf("%i", &op);
    char txt[5] = ".cpp";
    puts("escolha um nome para o arquivo txt");
    cin >> nome;
    strcat(nome, txt);
    cout << nome << endl;
    if (op == 1) {
        arq = fopen(nome, "w");
        fprintf(arq, "#include <iostream>\n"
                     "#include <stdio.h>\n"
                     "\n"
                     "using namespace std;\n"
                     "\n"
                     "int main(){\n"
                     "    char f[200];\n"
                     "    int p = 0;\n"
                     "    printf(\"Cadeia: \");\n"
                     "    cin>>f;\n"
                     "    goto e%i;\n", qo);

        fprintf(arq, "\n"
                     "    e0:\n"
                     "    if(f[p] == 'a'){\n"
                     "        p++;\n"
                     "        goto e1;\n"
                     "    }\n"
                     "    else if(f[p] == 'b'){\n"
                     "        p++;\n"
                     "        goto e2;\n"
                     "    }\n"
                     "    else{\n"
                     "        goto rejeita;\n"
                     "    }\n"
                     "\n"
                     "    e1:\n"
                     "    if(f[p] == 'a'){\n"
                     "        p++;\n"
                     "        goto rejeita;\n"
                     "    }\n"
                     "    else if(f[p] == 'b'){\n"
                     "        p++;\n"
                     "        goto e2;\n"
                     "    }\n"
                     "    else{\n"
                     "        goto rejeita;\n"
                     "    }\n"
                     "    e2:\n"
                     "    if (f[p] == '\\0'){\n"
                     "        goto aceita;\n"
                     "    } else{\n"
                     "        goto rejeita;\n"
                     "    }\n"
                     "\n"
                     "    aceita:\n"
                     "    printf(\"Aceita\\n\");\n"
                     "    return 0;\n"
                     "\n"
                     "    rejeita:\n"
                     "    printf(\"Rejeita\\n\");\n"
                     "    return 0;\n"
                     "}");
    }
    else if(op == 2){

    }
    else{
        puts("opcao invalida");
    }
}
int main() {
    questionario();
    return 0;
}