#include <stdio.h>
#include <string.h>

#define MAX_NOMES 100

struct Pessoa
{
    char nome[50];
    int idade[100];
    char cidade[25];
};

struct Pessoa listaNomes[MAX_NOMES];

int numNomes = 0;

void addNome()
{
    if (numNomes >= MAX_NOMES)
    {
        printf("Lista cheia");
        return;
    }

    printf("Digite um nome:\n");
    scanf(" %[^\n]s", listaNomes[numNomes].nome);

    printf("Digite uma idade:\n");
    scanf(" %[^\n]s", listaNomes[numNomes].idade);

    printf("Digite uma cidade:\n");
    scanf(" %[^\n]s", listaNomes[numNomes].cidade);

    numNomes++;
    printf("Cadastrado com sucesso!\n");
}

void mostrarNomes()
{
	int i;
    if (numNomes == 0)
    {
        printf("Lista vazia.");
        return;
    }
    printf("\n---Lista de nomes---\n\n");
    for (i = 0; i < numNomes; i++)
    {
        printf("%s\n%s\n%s\n------------ \n", listaNomes[i].nome, listaNomes[i].idade, listaNomes[i].cidade);
    }
}

void editarNomes() {
    int indice, i, cod;

    printf("Digite o indice do usuário que deseja editar: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= numNomes) {
        printf("Indice inválido!");
    } else {

        printf("\n\nPara editar nome = 1\nPara editar idade = 2,\nPara editar cidade = 3\n\nOpcao: ");
        scanf("%d", &cod);
        for (i=indice; i<=numNomes-1; i++) {
            switch (cod) {
                case 1:
                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]s", listaNomes[i].nome);
                    printf("Nome editado com sucesso!");
                    break;

                case 2:
                    printf("Digite a nova idade: ");
                    scanf(" %[^\n]s", listaNomes[i].idade);
                    printf("Idade editada com sucesso!");
                    break;

                case 3:
                    printf("Digite a nova cidade: ");
                    scanf(" %[^\n]s", listaNomes[i].cidade);
                    printf("Cidade editada com sucesso!");
                    break;

                default:
                    printf("Opção inválida!\n");
                    break;
            }
        }
    }
}


void excluirNome()
{
    int indice, i;

    printf("Digite o indice do usuario que deseja apagar: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= numNomes) {
        printf("Indice invalido!");
    } else {

        for (i=indice; i<=numNomes-1; i++) {
            strcpy(listaNomes[i].nome, listaNomes[i+1].nome);
            strcpy(listaNomes[i].cidade, listaNomes[i+1].cidade);
            strcpy(listaNomes[i].idade, listaNomes[i+1].idade);
        }

        numNomes--;
        printf("\nUsuario excluido!");
    }
}

int main()
{
    int cod;

    printf("------ Cadastrar pessoas ------");

    do {
        printf("\n\nCodigo: ");
        scanf("%d", &cod);

        switch (cod)
        {
        case 1:
            addNome();
            break;
        case 2:
            mostrarNomes();
            break;
        case 3:
            excluirNome();
            break;
        case 4:
            editarNomes();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while(cod != 0);

    return 0;
}
