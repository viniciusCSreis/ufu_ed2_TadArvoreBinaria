#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBin.h"

int testar_criaArvBin();
int testar_insereABB();
int main()
{
    printf("Tad Arvore Binaria\n");
    testar_criaArvBin();
    testar_insereABB();

    return 0;
}
int testar_criaArvBin()
{
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

    liberarArv(raiz);

    return 1;
}

int testar_insereABB()
{
    ArvBin * raiz = criaArvBin();
    if(raiz==NULL)
    {
        fprintf(stderr,"Erro ao criar ArvBin\n");
        return 0;
    }

    insereABB(raiz,5);
    insereABB(raiz,1);
    insereABB(raiz,4);
    insereABB(raiz,3);
    insereABB(raiz,6);


    printf("Pre:");
    preOrdem(raiz);
    printf("In:");
    inOrdem(raiz);
    printf("Pos:");
    posOrdem(raiz);


    return 1;

}
