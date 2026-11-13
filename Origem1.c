#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <locale.h>


// Os #define são usados apenas para dar valores globais, assim não sundo necessrio definir novamente os valores em cada função
#define MAX_UTENTES 100
#define MAX_CONSULTAS 300


int main()
{
    setlocale(LC_ALL, "pt_PT.UTF8"); // Para caracteres especiais 


    int menu, quantidade = 0;
    int totalConsultas = 0;
    int proximoIDConsulta = 1;


    int id_utente[MAX_UTENTES];
    int idade[MAX_UTENTES];


    char nome_utente[MAX_UTENTES][50];
    char telefone[MAX_UTENTES][20];


    // Arrays para guardar as consultas
    int id_consulta[MAX_CONSULTAS];
    int id_utente_consulta[MAX_CONSULTAS];
    int especialidade[MAX_CONSULTAS];
    int consulta_ativa[MAX_CONSULTAS];


    do
    {
        // Menu Principal
        printf("\n===== CENTRO DE SAUDE =====\n");
        printf("1 - Registar Utente\n");
        printf("2 - Marcar Consulta\n");
        printf("3 - Cancelar Consulta\n");
        printf("4 - Mostrar Utentes\n");
        printf("5 - Mostrar Totais\n");
        printf("0 - Sair\n");


        printf("\nEscolha uma opção: ");
        scanf("%d", &menu);
        getchar();


        // Registrar Utente
        if (menu == 1)
        {
            if (quantidade >= MAX_UTENTES) { // Comparar caso o numero de utentes seja maior ou igual a 100(MAX_UTENTES)
                printf("\nLimite de utentes atingido!\n");
            } 
            else
            {
                printf("\n===== REGISTAR UTENTE =====\n");
                id_utente[quantidade] = quantidade + 1;
                printf("ID: %d\n", id_utente[quantidade]);


                printf("Nome: ");
                fgets(nome_utente[quantidade], 50, stdin);
                nome_utente[quantidade][strcspn(nome_utente[quantidade], "\n")] = '\0';


                printf("Idade: ");
                scanf("%d", &idade[quantidade]);
                getchar();


                printf("Telefone: ");
                fgets(telefone[quantidade], 20, stdin);
                telefone[quantidade][strcspn(telefone[quantidade], "\n")] = '\0';

                quantidade++; // A quantidade de utentes registados aumenta em 1


                printf("\nUtente registado com sucesso!\n");
            }
        }


        // Marcar Consultas
        else if (menu == 2){
            if (quantidade == 0) { 
                printf("\nNão existem utentes registados!\n"); 
            }
            else if (totalConsultas >= MAX_CONSULTAS) { 
                printf("\nLimite de consultas atingido!\n"); 
            }

            else
            {
                int id, posicao = -1;


                printf("\n===== UTENTES REGISTADOS =====\n");
                for (int i = 0; i < quantidade; i++) // Vai mostrar todos os utentes registados até ler todos guardados na variável quantidade
                {
                    printf("ID: %d | Nome: %s\n", id_utente[i], nome_utente[i]);
                }


                printf("\nIntroduza o ID do utente: ");
                scanf("%d", &id);
                getchar();


                // Procurar o utente pelo ID
                for (int i = 0; i < quantidade; i++)
                {
                    if (id_utente[i] == id) { 
                        posicao = i; 
                    }
                }


                if (posicao == -1) { 
                    printf("\nUtente nao encontrado!\n"); 
                }
                else
                {
                    printf("\nUtente: %s\n", nome_utente[posicao]);


                    printf("\n===== ESPECIALIDADES =====\n");
                    printf("1 - Medicina Geral\n");
                    printf("2 - Pediatria\n");
                    printf("3 - Enfermagem\n");


                    printf("\nEscolha uma especialidade: ");
                    scanf("%d", &especialidade[totalConsultas]);
                    getchar();


                    if (especialidade[totalConsultas] >= 1 &&
                        especialidade[totalConsultas] <= 3)
                    {
                        id_consulta[totalConsultas] = proximoIDConsulta;
                        id_utente_consulta[totalConsultas] = id;


                        consulta_ativa[totalConsultas] = 1;


                        printf("\nConsulta marcada com sucesso!\n");
                        printf("Numero da consulta: %d\n", proximoIDConsulta);


                        totalConsultas++;
                        proximoIDConsulta++;
                    }
                    else
                    {
                        printf("\nEspecialidade invalida!\n");
                    }
                }
            }
        }


        // Cancelar consultas 
        else if (menu == 3)
        {
            int id, encontrada = 0;


            printf("\n===== CANCELAR CONSULTA =====\n");
            printf("Introduza o numero da consulta: ");
            scanf("%d", &id);
            getchar();


            for (int i = 0; i < totalConsultas; i++)
            {
                if (id_consulta[i] == id && consulta_ativa[i] == 1)
                {
                    consulta_ativa[i] = 0;
                    encontrada = 1;


                    printf("\nConsulta cancelada com sucesso!\n");
                }
            }


            if (encontrada == 0)
            {
                printf("\nConsulta nao encontrada ou ja cancelada!\n");
            }
        }


        // Mostrar Utentes
        else if (menu == 4)
        {
            printf("\n===== LISTA DE UTENTES =====\n");
            if (quantidade == 0) {
                printf("Nao existem utentes registados!\n"); 
            }
            for (int i = 0; i < quantidade; i++)
            {
                printf("\nID: %d\n", id_utente[i]);
                printf("Nome: %s\n", nome_utente[i]);
                printf("Idade: %d\n", idade[i]);
                printf("Telefone: %s\n", telefone[i]);
            }
        }


        // Mostrar os totais
        else if (menu == 5)
        {
            int consultasAtivas = 0;
            for (int i = 0; i < totalConsultas; i++)
            {
                if (consulta_ativa[i] == 1) {
                    consultasAtivas++;
                }
            }


            printf("\n===== TOTAIS DO CENTRO DE SAUDE =====\n");
            printf("Total de utentes: %d\n", quantidade);
            printf("Total de consultas registadas: %d\n", totalConsultas);
            printf("Consultas ativas: %d\n", consultasAtivas);
            printf("Consultas canceladas: %d\n", totalConsultas - consultasAtivas);
        }


        else if (menu == 0) {
            printf("\nA encerrar o programa...\n");
        }  // Sair do programa


        else {
            printf("\nOpcao invalida! Tente novamente.\n");
        } // Qualquer outro numero que nao seja 0,1,2,3,4 ou 5


    } while (menu != 0);


    return 0;
}
