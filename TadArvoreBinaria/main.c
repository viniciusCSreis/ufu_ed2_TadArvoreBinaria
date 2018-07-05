#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ArvoreBin.h"

void  exibirArvore();
int testar_insereABB();
int main()
{
    printf("Tad Arvore Binaria\n");

    //create ArvBin
    ArvBin * raiz=criaArvBin();
    if(raiz==NULL)
    {
       fprintf(stderr,"Erro ao criar ArvBin\n");
       return 0;
    }
    if(*(raiz)!=NULL)
    {
        fprintf(stderr,"ArvBin nao foi criada corretamente\n");
        return 0;
    }

    printf("ArvBin criada corretamente\n");

    //inserção de elementos
    insereABB(raiz,5);
    insereABB(raiz,1);
    insereABB(raiz,4);
    insereABB(raiz,3);
    insereABB(raiz,6);

    //remocao de elementos
    printf("Existe 4:%d\n",buscaABB(raiz,4));
    exibirArvore(raiz);
    removeABB(raiz,4);
    printf("Existe 4:%d\n",buscaABB(raiz,4));

    exibirArvore(raiz);

    //rotacao de elementos

    insereABB(raiz,7);
    insereABB(raiz,8);
    insereABB(raiz,9);
    exibirArvore(raiz);

    //libera ArbBin
    liberarArv(raiz);

    return 0;
}

void exibirArvore(ArvBin * raiz)
{
    int i;
    int n=pow(2,calculaAltura(raiz))-1;
    printf("Alocao Estatica:\n");
    void **vetor=alocacaoEstatica(raiz);
    for(i=0;i<n;i++)
    {
        printf(" %d:%d(%d)",i,getInfo(vetor[i]),getAlt(vetor[i]));
    }
    printf("\n");
    free(vetor);
}

