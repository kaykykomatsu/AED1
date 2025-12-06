#include <stdio.h>

#define MAX 1000

typedef struct lista {
    char vet[MAX];
    int topo;
} Lista;

void push(char vet[MAX], char c, int *topo) {
    if (*topo < MAX) {
        vet[*topo] = c;
        (*topo)++;
    }
}

void pop(char vet[MAX], int *topo) {
    if (*topo > 0) {
        (*topo)--;
        vet[*topo] = '\0';
    }
}

const char* verifica_parenteses(char expressao[MAX]) {
    Lista pilha;
    pilha.topo = 0;

    for (int i = 0; expressao[i] != '\0' && expressao[i] != '\n'; i++) {
        if (expressao[i] == '(') {
            push(pilha.vet, '(', &pilha.topo);
        } else if (expressao[i] == ')') {
            if (pilha.topo == 0) {
                return "incorrect";
            }
            pop(pilha.vet, &pilha.topo);
        }
    }

    return (pilha.topo == 0) ? "correct" : "incorrect";
}

int main() {
    int n;
    char expressao[MAX];

    if (scanf("%d", &n) != 1 || n < 1 || n > 10000) {
        return 1;
    }

    while (getchar() != '\n'); // limpa o buffer

    for (int i = 0; i < n; i++) {
        if (fgets(expressao, MAX, stdin)) {
            const char* resultado = verifica_parenteses(expressao);
            printf("%s\n", resultado);
        }
    }

    return 0;
}
