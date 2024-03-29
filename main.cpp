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
int qo = 0; // caso de entrada (para facilitar o raciocinio inicialmente ele sera fixo em e0)
int F; // quantidade de casos finais
int fin[200]; // casos finais
int n, m;// m = quantidade de simbolos
int prox = 0;
int c = 0;
FILE *arq;

void questionario () {
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
    //puts("qual o estado inicial?");
    //scanf("%i", &qo);

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
           "n estados finais %i\n"
           "caso inicial: %i\n", m, Q, F, qo);
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
    arq = fopen(nome, "w");
    bool ok = 0;
    if (op == 1) {
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
        for (int i = 0; i < Q; i++) {
            //aqui
            n = i + 1;
            if (n > Q) {
                fprintf(arq, "\n"
                             "    rejeita:\n"
                             "    puts(\":C\");\n"
                             "    return 0;\n\n"
                             "    aceita:\n"
                             "    puts(\"aceitou!!!\")\n"
                             "    }\n");
                return;
            } else {
                if (sig[i] == 0) {
                    fprintf(arq, "\n"
                                 "    e%i:\n"
                                 "    if(f[p] == 0){\n"
                                 "        p++;\n"
                                 "        goto aceita;\n"
                                 "    }\n", i);
                } else {
                    if (S[i][n] >= 0) {
                        fprintf(arq, "\n"
                                     "    e%i:\n"
                                     "    if(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        goto e%i;\n"
                                     "    }\n", i, sig[i], S[i][c]);
                        c++;
                    } else {
                        fprintf(arq, "\n"
                                     "    e%i:\n"
                                     "    if(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        goto e%i;\n"
                                     "    }\n", i, sig[i], S[i][c]);
                        c++;
                    }
                }
                for (int k = 0; k < F; k++) {
                    if (fin[k] == S[i][k]) {
                        fprintf(arq, "\n"
                                     "    e%i:\n"
                                     "    if(f[p] == 0){\n"
                                     "        goto aceita;\n"
                                     "    }\n"
                                     "}\n", i);
                    }
                }

            }
            for (int j = 1; j < m; j++) {
                if (j != i) {
                    if (S[i][j] < 0) {
                        fprintf(arq, "\n"
                                     "\telse\n"
                                     "\tif(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        goto rejeita;\n"
                                     "    }\n", sig[j]);
                    } else {
                        fprintf(arq, "\n"
                                     "\telse\n"
                                     "\tif(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        goto e%i;\n"
                                     "    }\n", sig[j], S[i][j]);
                    }
                }
            }
            fprintf(arq, "\n"
                         "\telse{\n"
                         "        goto rejeita;\n"
                         "    }\n");
        }
        fprintf(arq, "\n"
                     "    rejeita:\n"
                     "    puts(\":C\");\n"
                     "    return 0;\n\n"
                     "    aceita:\n"
                     "    puts(\"aceitou!!!\");\n"
                     "    }\n");

    } else if (op == 2) {
        fprintf(arq, "#include <iostream>\n"
                     "using namespace std;\n"
                     "\n");
        for (int i = 0; i < Q; i++) {
            fprintf(arq, "void e%i();\n", i);
        }
        fprintf(arq, "\nvoid aceita();\n"
                     "void rejeita();\n"
                     "\n");
        fprintf(arq, "char f[200];\n"
                     "int p;\n"
                     "\n");
        for (int j = 0; j < Q; j++) {
            n = (j + 1);
            if (j == (Q - 1)) {
                fprintf(arq, "\n"
                             "void e%i(){\n"
                             "    if(f[p] == 0){\n"
                             "        p++;\n"
                             "        aceita();\n"
                             "\texit(0);\n"
                             "    } else{\n"
                             "        rejeita();\n"
                             "\texit(0);\n"
                             "    }\n"
                             "}\n", j);
            } else {
                if (S[j][0] < 0) {
                    fprintf(arq, "void e%i(){\n"
                                 "    if(f[p] == '%c'){\n"
                                 "        p++;\n"
                                 "        rejeita();\n"
                                 "}\n", j, sig[0]);
                } else {
                    fprintf(arq, "void e%i(){\n"
                                 "    if(f[p] == '%c'){\n"
                                 "        p++;\n"
                                 "        e%i();\n"
                                 "}\n", j, sig[0], n);
                }
                for (int i = 1; i < m; i++) {
                    c++;
                    if ((S[j][i]) < 0) {
                        fprintf(arq, "    else\n"
                                     "\tif(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        rejeita();\n"
                                     "}\n", sig[c]);
                    } else {
                        fprintf(arq, "    else\n"
                                     "\tif(f[p] == '%c'){\n"
                                     "        p++;\n"
                                     "        e%i();\n"
                                     "}\n", sig[c], S[j][i]);
                    }
                    if (sig[i] == 0) {
                        fprintf(arq, "    else\n"
                                     "\tif(f[p] == 0){\n"
                                     "        p++;\n"
                                     "        aceita();\n"
                                     "}\n");
                    }
                }
                c = 0;
                fprintf(arq, "\n"
                             "\telse{\n"
                             "\trejeita();\n"
                             "\t}\n"
                             "}\n");
            }
        }
        fprintf(arq, "void aceita(){\n"
                     "    puts(\"viva!!!\");\n"
                     "    exit(0);\n"
                     "}\n"
                     "\n"
                     "void rejeita(){\n"
                     "    puts(\":c\");\n"
                     "    exit(0);\n"
                     "}\n");
        fprintf(arq, "\nint main() {\n"
                     "    cin>>f;\n"
                     "    e0();\n"
                     "    return 0;\n"
                     "}");
    } else {
        puts("opcao invalida");
    }
}

int main() {
    questionario();
    fclose(arq);
    return 0;
}