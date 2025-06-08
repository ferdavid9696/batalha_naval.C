22#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define TORPEDOS 4

// Inicializa o mapa com água
void inicializarMapa(char mapa[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mapa[i][j] = '~';
        }
    }
}

// Mostra o mapa atual
void mostrarMapa(char mapa[TAM][TAM]) {
    printf("\n  0 1 2 3 4\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char mapa[TAM][TAM];
    int linhaNavio, colunaNavio;
    int linhaTiro, colunaTiro;
    int acertou = 0;

    srand(time(NULL));
    inicializarMapa(mapa);

    // Define posição aleatória do navio
    linhaNavio = rand() % TAM;
    colunaNavio = rand() % TAM;

    printf("=== BATALHA NAVAL - OPERACAO FANTASMA ===\n");
    printf("Missao: localizar e destruir o navio inimigo furtivo.\n");
    printf("Setor monitorado: grade 5x5. Torpedos disponiveis: %d\n", TORPEDOS);
    printf("Alvo pode se mover uma vez durante a operacao.\n");

    for (int i = 0; i < TORPEDOS; i++) {
        printf("\nLancamento %d de %d\n", i + 1, TORPEDOS);
        mostrarMapa(mapa);

        printf("Informe a linha (0 a 4): ");
        scanf("%d", &linhaTiro);
        printf("Informe a coluna (0 a 4): ");
        scanf("%d", &colunaTiro);

        if (linhaTiro == linhaNavio && colunaTiro == colunaNavio) {
            printf("Impacto confirmado. O navio inimigo foi destruido.\n");
            mapa[linhaTiro][colunaTiro] = '*';
            acertou = 1;
            break;
        } else {
            printf("Nenhum contato. Setor marcado como vazio.\n");
            mapa[linhaTiro][colunaTiro] = 'X';

            // O navio muda de posição após a 2ª tentativa (apenas uma vez)
            if (i == 1) {
                linhaNavio = rand() % TAM;
                colunaNavio = rand() % TAM;
                printf("Alerta: sensores indicam deslocamento de calor no setor.\n");
            }
        }
    }

    if (!acertou) {
        printf("\nMissao encerrada. O navio inimigo escapou.\n");
        mapa[linhaNavio][colunaNavio] = '*'; // Revela o navio ao fim
    }

    mostrarMapa(mapa);
    printf("Operacao finalizada.\n");

    return 0;
}
