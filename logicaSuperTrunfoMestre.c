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

// Função para exibir o menu de atributos
void exibirMenu(int excluido) {
    printf("Escolha um atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área (km²)\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
}

float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.areaKm;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuriscos;
        case 5: return c.densidadePopulacional;
        default: return 0;
    }
}

int main() {
    struct Carta carta1 = {'A', "Fortaleza", "A1", 15, 312.353, 73000000000.0, 2627482};
    struct Carta carta2 = {'B', "Pernambuco", "B1", 10, 218.843, 5469100000.0, 1587707};

    // Cálculos
    carta1.densidadePopulacional = carta1.populacao / carta1.areaKm;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.areaKm;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributo1 = 0, atributo2 = 0;

    printf("=== SUPER TRUNFO: COMPARAÇÃO AVANÇADA ===\n");

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida! Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo
    do {
        exibirMenu(atributo1);
        printf("Digite o número do segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
            printf("Opção inválida ou repetida! Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Comparação
    float valor1_a = obterValor(carta1, atributo1);
    float valor2_a = obterValor(carta2, atributo1);
    float valor1_b = obterValor(carta1, atributo2);
    float valor2_b = obterValor(carta2, atributo2);

    // Regra especial para densidade demográfica
    int vencedorA = (atributo1 == 5) ? (valor1_a < valor2_a ? 1 : (valor1_a > valor2_a ? 2 : 0))
                                     : (valor1_a > valor2_a ? 1 : (valor1_a < valor2_a ? 2 : 0));
    int vencedorB = (atributo2 == 5) ? (valor1_b < valor2_b ? 1 : (valor1_b > valor2_b ? 2 : 0))
                                     : (valor1_b > valor2_b ? 1 : (valor1_b < valor2_b ? 2 : 0));

    float soma1 = valor1_a + valor1_b;
    float soma2 = valor2_a + valor2_b;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2) ? 2 : 0;

    // Exibição dos resultados
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Cartas: %s vs %s\n", carta1.cidade, carta2.cidade);
    printf("Atributo 1 (%d): %.2f vs %.2f => %s\n", atributo1, valor1_a, valor2_a,
           vencedorA == 1 ? carta1.cidade : vencedorA == 2 ? carta2.cidade : "Empate");
    printf("Atributo 2 (%d): %.2f vs %.2f => %s\n", atributo2, valor1_b, valor2_b,
           vencedorB == 1 ? carta1.cidade : vencedorB == 2 ? carta2.cidade : "Empate");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.cidade, soma1);
    printf("%s: %.2f\n", carta2.cidade, soma2);
    printf("Resultado final: %s\n", vencedorFinal == 1 ? carta1.cidade :
                                    vencedorFinal == 2 ? carta2.cidade : "Empate!");

    return 0;
    
}