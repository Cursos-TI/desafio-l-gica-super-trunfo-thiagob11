#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular os atributos derivados (densidade e PIB per capita)
void calcularIndicadores(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados principais de uma carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nome_cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("---------------------------------------\n");
}

int main() {
    // Cadastro das duas cartas manualmente
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 2300000.0, 25};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1182.3, 800000.0, 18};

    // Calcula os indicadores derivados
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe os dados das cartas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Comparação com base na POPULAÇÃO
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
