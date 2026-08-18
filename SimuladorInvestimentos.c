#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_cenarios 20

struct Investimento {
    int identificadorCenario;
    char descricao[50];
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
    i = taxa/100; //Porcentafgem pra decimal

    if(i == 0){
        return aporte * meses;
    }else{
        for (j = 0; j < meses; j++){
            potencia = potencia * (1 + i);
        }
        return aporte * ((potencia - 1) / i);
         }
}

int buscarPorID(struct Investimento investimentos[], int quantidade, int id) {
    
}

void cadastrar(struct Investimento investimentos[], int *quantidade) {

}

void listar(struct Investimento investimentos[], int quantidade) {

}

void comparar(struct Investimento investimentos[], int quantidade) {

}

void detalhar(struct Investimento investimentos[], int quantidade) {

}

int main() {
    struct Investimento investimentos[max_cenarios];
    int opcao;
    int quantidade = 0;

    do {
        printf("\n========== SIMULADOR DE INVESTIMENTOS ==========\n");
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

    }while (opcao != 5);

    return 0;
}