#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado;
    char cidade[30], codCarta[10];
    int pontosTuriscos;
    float areaKm, pib;
    unsigned long int populacao;
    float densidadePopulacional, pibPerCapita, superPoder;
};

int main() {
    struct Carta carta1 = {'A', "Fortaleza", "A1", 15, 312.353, 73000000000.0, 2627482.0}; // a ordem dos valores segue a ordem da estrutura da carta.
    struct Carta carta2 = {'B', "Pernanbuco", "B1", 10, 218.843, 5469100000.0, 1587707.0};

    // Cálculos
    carta1.densidadePopulacional = carta1.populacao / carta1.areaKm;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.areaKm;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int opcao;

    printf("=== SUPER TRUNFO: COMPARAÇÃO DE CARTAS ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n", carta1.cidade, carta2.cidade);

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu habitantes\n", carta1.cidade, carta1.populacao);
            printf("%s: %lu habitantes\n", carta2.cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.cidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Resultado: %s venceu!\n", carta2.cidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km²\n", carta1.cidade, carta1.areaKm);
            printf("%s: %.2f km²\n", carta2.cidade, carta2.areaKm);
            if (carta1.areaKm > carta2.areaKm)
                printf("Resultado: %s venceu!\n", carta1.cidade);
            else if (carta1.areaKm < carta2.areaKm)
                printf("Resultado: %s venceu!\n", carta2.cidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2f reais\n", carta1.cidade, carta1.pib);
            printf("%s: %.2f reais\n", carta2.cidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.cidade);
            else if (carta1.pib < carta2.pib)
                printf("Resultado: %s venceu!\n", carta2.cidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d pontos\n", carta1.cidade, carta1.pontosTuriscos);
            printf("%s: %d pontos\n", carta2.cidade, carta2.pontosTuriscos);
            if (carta1.pontosTuriscos > carta2.pontosTuriscos)
                printf("Resultado: %s venceu!\n", carta1.cidade);
            else if (carta1.pontosTuriscos < carta2.pontosTuriscos)
                printf("Resultado: %s venceu!\n", carta2.cidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta1.cidade);
            else if (carta1.densidadePopulacional > carta2.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta2.cidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente com um número de 1 a 5.\n");
            break;
    }

    return 0;
}