#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_cenarios 20

struct Investimento {
    int identificadorCenario;
    char descricao[51];
    float aporteMensal;
    float taxaJurosMensal;
    int numeroMeses;
    float montanteFinal;
    float totalInvestido;
    float totalJurosGanho;
};

float calcularMontante(float aporte, float taxa, int meses) {
    float i;
    int j;
    float potencia = 1;

    i = taxa / 100; // Porcentagem para decimal

    if (i == 0) {
        return aporte * meses;
    } else {
        for (j = 0; j < meses; j++) {
            potencia = potencia * (1 + i);
        }

        return aporte * ((potencia - 1) / i);
    }
}

int buscarPorID(struct Investimento investimentos[], int quantidade, int id) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (investimentos[i].identificadorCenario == id) {
            return i;
        }
    }

    return -1;
}

void cadastrar(struct Investimento investimentos[], int *quantidade) {
    struct Investimento *investimento;

    if (*quantidade >= max_cenarios) {
        printf("\nLimite de cenarios atingido.\n");
        return;
    }

    investimento = &investimentos[*quantidade];

    investimento->identificadorCenario = *quantidade + 1;

    printf("\nDescricao do cenario: ");
    scanf(" %50[^\n]", investimento->descricao);

    do {
        printf("Aporte mensal: R$ ");
        scanf("%f", &investimento->aporteMensal);

        if (investimento->aporteMensal <= 0) {
            printf("O aporte deve ser positivo.\n");
        }

    } while (investimento->aporteMensal <= 0);

    do {
        printf("Taxa de juros mensal (%%): ");
        scanf("%f", &investimento->taxaJurosMensal);

        if (investimento->taxaJurosMensal < 0) {
            printf("A taxa nao pode ser negativa.\n");
        }

    } while (investimento->taxaJurosMensal < 0);

    do {
        printf("Numero de meses: ");
        scanf("%d", &investimento->numeroMeses);

        if (investimento->numeroMeses < 1 ||
            investimento->numeroMeses > 360) {

            printf("O numero de meses deve estar entre 1 e 360.\n");
        }

    } while (investimento->numeroMeses < 1 ||
             investimento->numeroMeses > 360);

    investimento->montanteFinal = calcularMontante(
        investimento->aporteMensal,
        investimento->taxaJurosMensal,
        investimento->numeroMeses
    );

    investimento->totalInvestido =
        investimento->aporteMensal * investimento->numeroMeses;

    investimento->totalJurosGanho =
        investimento->montanteFinal - investimento->totalInvestido;

    (*quantidade)++;

    printf("\nCenario cadastrado com sucesso!\n");
    printf("Identificador: %d\n",
           investimento->identificadorCenario);
}

void listar(struct Investimento investimentos[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("\nNenhum cenario cadastrado.\n");
        return;
    }

    printf("\n");
    printf("%-5s %-25s %-15s %-15s %-15s\n",
           "ID", "Descricao", "Investido", "Juros", "Montante");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        printf("%-5d %-25s R$ %-11.2f R$ %-11.2f R$ %.2f\n",
               investimentos[i].identificadorCenario,
               investimentos[i].descricao,
               investimentos[i].totalInvestido,
               investimentos[i].totalJurosGanho,
               investimentos[i].montanteFinal);
    }
}

void comparar(struct Investimento investimentos[], int quantidade) {
    int i;
    int maiorMontante;
    int maiorRendimento;

    float rendimentoAtual;
    float maiorRendimentoPercentual;

    if (quantidade == 0) {
        printf("\nNenhum cenario cadastrado.\n");
        return;
    }

    maiorMontante = 0;
    maiorRendimento = 0;

    maiorRendimentoPercentual =
        (investimentos[0].totalJurosGanho /
         investimentos[0].totalInvestido) * 100;

    for (i = 1; i < quantidade; i++) {

        if (investimentos[i].montanteFinal >
            investimentos[maiorMontante].montanteFinal) {

            maiorMontante = i;
        }

        rendimentoAtual =
            (investimentos[i].totalJurosGanho /
             investimentos[i].totalInvestido) * 100;

        if (rendimentoAtual > maiorRendimentoPercentual) {
            maiorRendimentoPercentual = rendimentoAtual;
            maiorRendimento = i;
        }
    }

    printf("\n========== MAIOR MONTANTE ==========\n");
    printf("ID: %d\n",
           investimentos[maiorMontante].identificadorCenario);

    printf("Descricao: %s\n",
           investimentos[maiorMontante].descricao);

    printf("Montante final: R$ %.2f\n",
           investimentos[maiorMontante].montanteFinal);

    printf("\n========== MAIOR RENDIMENTO ==========\n");
    printf("ID: %d\n",
           investimentos[maiorRendimento].identificadorCenario);

    printf("Descricao: %s\n",
           investimentos[maiorRendimento].descricao);

    printf("Rendimento: %.2f%%\n",
           maiorRendimentoPercentual);
}

void detalhar(struct Investimento investimentos[], int quantidade) {
    int id;
    int posicao;
    int mes;

    float saldoAntes;
    float saldoDepois;

    float saldos[360];

    if (quantidade == 0) {
        printf("\nNenhum cenario cadastrado.\n");
        return;
    }

    printf("\nDigite o identificador do cenario: ");
    scanf("%d", &id);

    posicao = buscarPorID(investimentos, quantidade, id);

    if (posicao == -1) {
        printf("\nCenario nao encontrado.\n");
        return;
    }

    saldoAntes = 0;

    printf("\n========== DETALHAMENTO ==========\n");
    printf("Cenario: %s\n", investimentos[posicao].descricao);

    printf("\n%-5s %-18s %-15s %-20s\n",
           "Mes", "Saldo antes", "Aporte", "Saldo apos rendimento");

    printf("---------------------------------------------------------------------\n");

    for (mes = 0; mes < investimentos[posicao].numeroMeses; mes++) {

        saldoDepois =
            (saldoAntes + investimentos[posicao].aporteMensal) *
            (1 + investimentos[posicao].taxaJurosMensal / 100);

        saldos[mes] = saldoDepois;

        printf("%-5d R$ %-14.2f R$ %-11.2f R$ %.2f\n",
               mes + 1,
               saldoAntes,
               investimentos[posicao].aporteMensal,
               saldos[mes]);

        saldoAntes = saldos[mes];
    }
}

int main() {
    struct Investimento investimentos[max_cenarios];
    int opcao;
    int quantidade = 0;

    do {
        printf("\n========== SIMULADOR DE INVESTIMENTOS DE LOURES ==========\n");
        printf("1 - Cadastrar cenario\n");
        printf("2 - Listar cenarios\n");
        printf("3 - Comparar cenarios\n");
        printf("4 - Detalhar cenario\n");
        printf("5 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(investimentos, &quantidade);
                break;

            case 2:
                listar(investimentos, quantidade);
                break;

            case 3:
                comparar(investimentos, quantidade);
                break;

            case 4:
                detalhar(investimentos, quantidade);
                break;

            case 5:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 5);

    return 0;
}