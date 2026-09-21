#include <stdio.h>

int main() {
    float limite;
    float temperatura;
    float soma = 0;
    float maior = 0;
    float menor = 0;
    float media;
    float percentual;

    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int entradaValida;

    printf("   SISTEMA DE MONITORAMENTO INDUSTRIAL\n");

    /*
        Solicita o limite de temperatura.
        O do...while garante que o programa continue pedindo
        enquanto o usuario nao informar um numero valido.
    */
    do {
        printf("Digite o limite de temperatura: ");

        entradaValida = scanf("%f", &limite);

        if (entradaValida != 1) {
            printf("Entrada invalida! Digite um valor numerico.\n\n");

            /* Limpa os caracteres invalidos do buffer */
            while (getchar() != '\n');
        }

    } while (entradaValida != 1);

    printf("\nLimite definido: %.2f C\n", limite);
    printf("Iniciando monitoramento...\n\n");

    /*
        O monitoramento continua enquanto nao houver
        tres temperaturas consecutivas acima do limite.
    */
    while (consecutivas < 3) {

        printf("Digite a temperatura do sensor: ");

        entradaValida = scanf("%f", &temperatura);

        /*
            Se a entrada nao for numerica, ela e ignorada
            e uma nova temperatura e solicitada.
        */
        if (entradaValida != 1) {
            printf("Entrada invalida! Digite um valor numerico.\n\n");

            /* Limpa o buffer de entrada */
            while (getchar() != '\n');
        }
        else {

            /* Atualiza quantidade e soma das temperaturas validas */
            quantidade++;
            soma += temperatura;

            /*
                Na primeira leitura, a temperatura recebida
                e considerada inicialmente como maior e menor.
            */
            if (quantidade == 1) {
                maior = temperatura;
                menor = temperatura;
            }
            else {
                if (temperatura > maior) {
                    maior = temperatura;
                }

                if (temperatura < menor) {
                    menor = temperatura;
                }
            }

            /*
                Verifica se a temperatura ultrapassou o limite.
            */
            if (temperatura > limite) {
                acimaLimite++;
                consecutivas++;

                printf("ALERTA: temperatura acima do limite!\n");
                printf("Temperaturas consecutivas acima do limite: %d\n",
                       consecutivas);
            }
            else {
                /*
                    Uma temperatura normal interrompe a sequencia
                    de temperaturas acima do limite.
                */
                consecutivas = 0;

                printf("Temperatura dentro do limite.\n");
            }

            printf("---------------------------------------------\n\n");
        }
    }

    /*
        Calcula os dados finais do monitoramento.
    */
    media = soma / quantidade;

    percentual = ((float) acimaLimite / quantidade) * 100;
    printf("MONITORAMENTO ENCERRADO\n");

    printf("\nForam detectadas 3 temperaturas consecutivas");
    printf(" acima do limite!\n\n");

    printf("RELATORIO FINAL\n");
    printf("Limite definido: %.2f C\n", limite);
    printf("Quantidade de leituras validas: %d\n", quantidade);
    printf("Maior temperatura: %.2f C\n", maior);
    printf("Menor temperatura: %.2f C\n", menor);
    printf("Media das temperaturas: %.2f C\n", media);
    printf("Temperaturas acima do limite: %d\n", acimaLimite);
    printf("Percentual acima do limite: %.2f%%\n", percentual);

    return 0;
}
