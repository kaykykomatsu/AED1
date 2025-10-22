#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int info;
  struct celula *prox;
} Celula;

typedef struct pilha {
  Celula *ini;
  Celula *fim;
} Pilha;

Pilha* criarPilha() {
  Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  p->ini = p->fim = NULL;
  return p;
}

void push(Pilha *p, int valor) {
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->info = valor;
  nova->prox = NULL;
  if (p->ini == NULL) {
    p->ini = p->fim = nova;
  } else {
    p->fim->prox = nova;
    p->fim = nova;
  }
}

int popTopo(Pilha *p) {
  if (p->ini == NULL) return -1;
  Celula *temp = p->ini;
  int valor = temp->info;
  p->ini = temp->prox;
  if (p->ini == NULL) p->fim = NULL;
  free(temp);
  return valor;
}

void moverParaFim(Pilha *p) {
  if (p->ini == NULL || p->ini == p->fim) return;
  Celula *temp = p->ini;
  p->ini = temp->prox;
  temp->prox = NULL;
  p->fim->prox = temp;
  p->fim = temp;
}

void simularCartas(Pilha *p) {
  int descartadas[50];
  int cont = 0;

  while (p->ini != NULL && p->ini != p->fim) {
    descartadas[cont++] = popTopo(p);
    moverParaFim(p);
  }

  printf("Discarded cards: ");
  for (int i = 0; i < cont; i++) {
    printf("%d", descartadas[i]);
    if (i < cont - 1) printf(", ");
  }

  if (p->ini != NULL) {
    printf("\nRemaining card: %d\n", p->ini->info);
  }
}

void liberarPilha(Pilha *p) {
  while (p->ini != NULL) {
    Celula *temp = p->ini;
    p->ini = p->ini->prox;
    free(temp);
  }
  free(p);
}

int main() {
  int n;

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;

    Pilha *p = criarPilha();
    for (int i = 1; i <= n; i++) {
      push(p, i);
    }

    simularCartas(p);
    liberarPilha(p);
  }

  return 0;
}
