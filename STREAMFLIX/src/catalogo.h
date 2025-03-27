//catalogo.h 

#ifndef CATALOGO_H
#define CATALOHO_H 

// definir os tamanhos maximo para o titulo e categoria
#define MAX_TITULO 100
#define MAX_CATEGORIA 50

typedef struct{
  char titulo[MAX_TITULO];
  char categoria[MAX_CATEGORIA];
  int duracao;
  int classificacao;
  int visualiozacoes;


} Conteudo; 

typedef struct {
  Conteudo* items; 
  int tamanho;
  int capacidade;
} Catalogo; 



Catalogo carregarCatalogo(const char* nomeFicheiro);


// lista todos os conteudos de uma determinada categoria
void listarPorCategoria(Catalogo* catalogo, const char* categoria);

// pesquisar por titulo
Conteudo* pesquisar_por_titulo(Catalogo * catalogo, const char* titulo);

// libertar memoria 
void libertar_catalogo(Catalogo* catalogo);

#endif // CATALOGO_H

