#include "ArvoreBinDefinitions.h"

//criando �rvore

ArvBin * criaArvBin();

//liberando a �rvore

void liberarArv(ArvBin * raiz);
//libera No utilizado por libera �rvore
void liberaNo(struct No * no);

//percorer ArvBin em pre-ordem
void preOrdem(ArvBin * raiz);

//percorer ArvBin em in-ordem
void inOrdem(ArvBin * raiz);

//percorer ArvBin em in-ordem
void posOrdem(ArvBin * raiz);

//Buscar elemento no ABB
int buscaABB(ArvBin * raiz,int v);

//Inserir elem na ABB
int insereABB(ArvBin * raiz,int v);

//Remove elem da ABB
struct No * removeAtual(struct No * atual);

//remove No utilizado por remove elem
struct No * removeAtual(struct No * atual);
