#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char sig[200];
int Q;
int S[200][200];
char qo;
int F;
int fin[200];
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
    for (int k = 0; k < Q; k++) {
        for (int i = 0; i < m; i++) {
            printf("do estado e%i com %c qual simbolo faz esse caminho?\n", k, sig[i]);
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
        cout<<fin[i1]<<" ";
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
    char resp;
    char txt[5] = ".cpp";
    puts("escolha um nome para o arquivo txt");
    cin >> nome;
    strcat(nome, txt);
    cout << nome << endl;
    arq = fopen(nome, "w");
    fprintf(arq, "#include <iostream>\n"
                 "using namespace std;\n"
                 "#include <stdio.h>\n"
                 "\n");
    fprintf(arq,"int main(){\n"
                "    char f[200];\n"
                "    int p = 0;\n"
                "    printf(\"Cadeia: \");\n"
                "    cin>>f;\n"
                "    goto e0;\n"
                "\n");
    int b;
            for(int i = 0; i < m; i++) {
                b = 0;
                fprintf(arq, "    e%i:\n", i);
                    fprintf(arq, "    if(f[p] == '%c'){\n"
                                 "        p++;\n"
                                 "        goto e%i;\n"
                                 "    }\n",sig[i],b);
                    b++;
                    for (int j = 0; j < m; j++) {
                            fprintf(arq, "    else\n"
                                         "     if(f[p] == '%c'){\n"
                                         "       goto e%i;\n"
                                         "  }\n", sig[j], b);
                            b++;
                    }
                    fprintf(arq, "    else\n"
                                 "    if(f[p] == '0'){\n"
                                 "        p++;\n"
                                 "        goto aceita;\n"
                                 "    }\n"
                                 "else{\n"
                                 "goto rejeita;\n"
                                 "}\n");
                }

    fprintf(arq, "    aceita:\n"
                 "    printf(\"Aceita\\n\");\n"
                 "    return 0;\n"
                 "\n"
                 "    rejeita:\n"
                 "    printf(\"Rejeita\\n\");\n"
                 "    return 0;\n"
                 "}\n");
}

int main() {
    questionario();
    return 0;
}