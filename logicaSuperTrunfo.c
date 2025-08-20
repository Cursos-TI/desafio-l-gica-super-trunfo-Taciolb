#include <stdio.h>

// Definição da estrutura da carta, Variáveis
struct Carta {
    char estado;
    char cidade[10],codCarta[10];
    int  pontosTuriscos;
    float areaKm, pib; 
    unsigned long int populacao;
    float densidadePopulacional, pibPerCapita, superPoder;
};

int main() {
    // Declaração das duas cartas
    struct Carta carta1, carta2;

   //Entrada dos dados solicitados ao usuário
    printf("Cadastro da Carta 1:\n");

    printf("Digite o Estado: ( Use uma letra de A a H, simbolizando um estado).\n");
    scanf(" %c", &carta1.estado);

    printf("Digite o código da carta: (ex. A1) \n");
    scanf("%s", &carta1.codCarta);

    printf("Digite a Cidade: \n");
    scanf("%s", &carta1.cidade);

    printf("Digite a População: \n");
    scanf("%lu", &carta1.populacao);

    printf("Digite a Área em km²: \n");
    scanf("%f", &carta1.areaKm);

    printf("Digite o PIB: \n");
    scanf("%f", &carta1.pib);

    printf("Digite a quantidade de Pontos Turisticos: \n");
    scanf("%d", &carta1.pontosTuriscos);
    printf("\n");

    // Cálculos da Carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.areaKm;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta1.superPoder = (float)carta1.populacao + carta1.areaKm + carta1.pib + carta1.pontosTuriscos + carta1.pibPerCapita + (1.0 / carta1.densidadePopulacional);

    printf("Cadastro da Carta 2:\n");

    printf("Digite o Estado: ( Use uma letra de A a H, simbolizando um estado).\n");
    scanf(" %c", &carta2.estado);

    printf("Digite o código da carta: (ex. A1) \n");
    scanf("%s", &carta2.codCarta);

    printf("Digite a Cidade: \n");
    scanf("%s", &carta2.cidade);

    printf("Digite a População: \n");
    scanf("%lu", &carta2.populacao);

    printf("Digite a Área em km²: \n");
    scanf("%f", &carta2.areaKm);

    printf("Digite o PIB: \n");
    scanf("%f", &carta2.pib);

    printf("Digite a quantidade de Pontos Turisticos: \n");
    scanf("%d", &carta2.pontosTuriscos);

    // Cálculos da Carta 2
    carta2.densidadePopulacional = carta2.populacao / carta2.areaKm;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;
    carta2.superPoder = (float)carta2.populacao + carta2.areaKm + carta2.pib + carta2.pontosTuriscos + carta2.pibPerCapita + (1.0 / carta2.densidadePopulacional);


    // Comparação pelo atributo escolhido: PIB per capita
    printf("\n--- Comparação de Cartas (Atributo: PIB per capita) ---\n");
    printf("Carta 1 - %s (%c): %.2f reais\n", carta1.cidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%c): %.2f reais\n", carta2.cidade, carta2.estado, carta2.pibPerCapita);

    // Lógica de decisão usando if-else
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.pibPerCapita < carta2.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}