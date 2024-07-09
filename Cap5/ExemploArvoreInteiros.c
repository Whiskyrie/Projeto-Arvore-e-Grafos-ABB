#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main()
{
    pDArvore pArvoreInt;
    int raiz, opcao, valorBuscado, valorInserido;

    printf("Informe a raiz da arvore: ");
    scanf("%d", &raiz);
    pArvoreInt = CriarArvore(raiz);

    do
    {
        system("cls"); // Limpa o console a cada seleção
        printf("\nMenu:\n");
        printf("1. Inserir Valor na Arvore\n");
        printf("2. Desenhar Arvore\n");
        printf("3. Calcular Altura da Arvore\n");
        printf("4. Calcular Quantidade de Folhas\n");
        printf("5. Calcular Quantidade de Nos\n");
        printf("6. Buscar Valor na Arvore\n");
        printf("7. Excluir Valor da Arvore\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            srand(time(NULL)); // Inicializa a semente para números aleatórios
            int t = clock();   // armazena tempo
            for (int i = 0; i < 10000; i++)
            {
                valorInserido = rand() % 10000; // Gera um número aleatório entre 0 e 999
                IncluirInfo(pArvoreInt, AlocaInt(valorInserido), ComparaInt);
            }
            t = clock() - t; // tempo final - tempo inicial
            printf("Tempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000)));

            break;
        case 2:
            DesenhaArvore(pArvoreInt, ImprimeInt);
            break;

        case 3:
            printf("Altura da Arvore: %d\n", Altura(pArvoreInt));
            break;
        case 4:
            printf("Quantidade de Folhas: %d\n", QuantidadeFolhas(pArvoreInt));
            break;
        case 5:
            printf("Quantidade de Nos: %d\n", QuantidadeNohs(pArvoreInt));
            break;
        case 6:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valorBuscado);
            if (BuscarInfo(pArvoreInt, AlocaInt(valorBuscado), ComparaInt))
            {
                printf("Valor %d encontrado na arvore!\n", valorBuscado);
            }
            else
            {
                printf("Valor %d nao encontrado na arvore!\n", valorBuscado);
            }
            break;
        case 7:
            printf("Digite o valor a ser excluido: ");
            scanf("%d", &valorBuscado);
            ExcluirInfo(pArvoreInt, AlocaInt(valorBuscado), ComparaInt);
            printf("Valor %d excluido da arvore!\n", valorBuscado);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

        printf("\nAperte Qualquer tecla Para Continuar.");
        getchar();
        getchar(); // Pausa o programa até que o usuário pressione uma tecla
    } while (opcao != 0);

    return 0;
}