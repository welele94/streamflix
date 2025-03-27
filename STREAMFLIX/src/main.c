// this main will just handle all the .c files 
#include <stdio.h>
#include <string.h>
#include "catalogo.h"



int main(){
  Catalogo catalogo = carregarCatalogo("data/catalogo.csv");

  int opcao;
  char input[100];

  do {
    printf("\nWelcome to STREAMFLIX\n");
    printf("\n===== MAIN MENU =====\n");
    printf("1. Pesquisar conteúdo por titulo\n");
    printf("2. Listar conteudos por categoria\n"); 
    printf("0. Sair \n");
    scanf("%d", &opcao);
    getchar();


    switch (opcao){
      case 1: 
        printf("Titulo a pesquisar: "); 
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        Conteudo* c = pesquisarPorTitulo(&catalogo, input); 
        if(c){
          printf("Encontrado: %s (%d min, +%d) - %d views\n", c->titulo, c->duracao, c-> classificacao, c->visualiozacoes);
        }else{
          printf("Titulo não encontrado.\n");
        }
        break;

      case 2:
        printf("Categoria  listar: \n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        listar_por_categoria(&catalogo, input);
        break;
      
      case 0:
        printf("A sair...");
        break;

      default:
        printf("Opcao inválida!\n"); 
    }
  } while (opcao != 0);

  libertar_catalogo(&catalogo);
  return 0;
}