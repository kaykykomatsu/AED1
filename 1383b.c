#include <stdio.h>
#include <stdlib.h>

int verifica_linha(int **mat, int l) {
    int v[10] = {0};
    for (int i = 0; i < 9; i++) v[mat[l][i]]++;
    for (int i = 1; i <= 9; i++) if (v[i] != 1) return 0;
    return 1;
}

int verifica_coluna(int **mat, int c) {
    int v[10] = {0};
    for (int i = 0; i < 9; i++) v[mat[i][c]]++;
    for (int i = 1; i <= 9; i++) if (v[i] != 1) return 0;
    return 1;
}

int verifica_regiao(int **mat, int l0, int c0) {
    int v[10] = {0};
    for (int i = l0; i < l0+3; i++)
        for (int j = c0; j < c0+3; j++)
            v[mat[i][j]]++;
    for (int i = 1; i <= 9; i++) if (v[i] != 1) return 0;
    return 1;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int inst = 1; inst <= n; inst++) {
        int **mat = (int**) malloc(9 * sizeof(int*));
        for (int i = 0; i < 9; i++) {
            mat[i] = (int*) malloc(9 * sizeof(int));
        }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &mat[i][j]);
        int ok = 1;
        for (int i = 0; i < 9 && ok; i++)
            if (!verifica_linha(mat, i) || !verifica_coluna(mat, i))
                ok = 0;
        for (int i = 0; i < 9 && ok; i += 3)
            for (int j = 0; j < 9 && ok; j += 3)
                if (!verifica_regiao(mat, i, j))
                    ok = 0;
        printf("Instancia %d\n", inst);
        printf("%s\n\n", ok ? "SIM" : "NAO");
        // Liberação da matriz
        for (int i = 0; i < 9; i++) free(mat[i]);
        free(mat);
    }
    return 0;
}