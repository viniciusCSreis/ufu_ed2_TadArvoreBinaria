#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ArvoreBin.h"

//criando árvore

ArvBin * criaArvBin()
{
    ArvBin * raiz=(ArvBin * )malloc(sizeof(ArvBin));
    if(raiz!=NULL)
        *(raiz)=NULL;
    return raiz;

}

//liberando a árvore

void liberarArv(ArvBin * raiz)
{
    if(raiz==NULL)return;
        liberaNo(*(raiz));

    free(raiz);

}
//libera No utilizado por libera árvore
void liberaNo(struct No * no)
{
    if(no==NULL)
        return;

    liberaNo(no->esq);
    liberaNo(no->dir);

    free(no);
    no=NULL;

}

//percorer ArvBin em pre-ordem
void preOrdem(ArvBin * raiz)
{
    struct No * no = *(raiz);
    if(raiz==NULL)
        return;
    if(no!=NULL)
    {
        printf("%d\n",no->info);
        preOrdem(&(no->esq));
        preOrdem(&(no->dir));

    }

}
//percorer ArvBin em in-ordem
void inOrdem(ArvBin * raiz)
{
    struct No * no = *(raiz);
    if(raiz==NULL)
        return;
    if(no!=NULL)
    {

        inOrdem(&(no->esq));
        printf("%d\n",no->info);
        inOrdem(&(no->dir));

    }

}
//percorer ArvBin em pos-ordem
void posOrdem(ArvBin * raiz)
{
    struct No * no = *(raiz);
    if(raiz==NULL)
        return;
    if(no!=NULL)
    {

        posOrdem(&(no->esq));
        posOrdem(&(no->dir));
        printf("%d\n",no->info);

    }

}

//Buscar elemento no ABB
int buscaABB(ArvBin * raiz,int v)
{
    if(raiz==NULL)
        return 0;
    struct No * atual = *(raiz);
    while(atual!=NULL)
    {
        if(v==atual->info)
            return 1;
        if(v<atual->info)
            atual=atual->esq;
        else
            atual=atual->dir;
    }
    return 0;
}

//Inserir elem na ABB
int insereABB(ArvBin * raiz,int v)
{
    if(raiz==NULL)
        return 0;

    struct No * novo_No_a_ser_inserido;

    novo_No_a_ser_inserido=(struct No *)malloc(sizeof(struct No));
    if(novo_No_a_ser_inserido==NULL)
        return 0;
    novo_No_a_ser_inserido->info=v;
    novo_No_a_ser_inserido->alt=0;
    novo_No_a_ser_inserido->esq=NULL;
    novo_No_a_ser_inserido->dir=NULL;

    if(*(raiz)==NULL)
    {
        *(raiz)=novo_No_a_ser_inserido;
    }
    else
    {
        struct No * atual = *(raiz);
        struct No * ant = NULL;
        while(atual!=NULL)
        {
            ant=atual;
            if(v == atual->info)
            {
                free(novo_No_a_ser_inserido);
                return 0;
            }
            if(v<atual->info)
                atual=atual->esq;
            else
                atual=atual->dir;
        }
        if(v > ant->info)
            ant->dir=novo_No_a_ser_inserido;
        if(v < ant->info)
            ant->esq=novo_No_a_ser_inserido;

    }
    calculaAltura(raiz);
    return 1;




}

int removeABB(ArvBin * raiz,int v)
{
    if(raiz==NULL)
        return 0 ;
    struct No * ant = NULL;
    struct No * atual = *(raiz);

    while(atual!=NULL)
    {
        if(v == atual->info)
        {

            if(atual == *(raiz))
                *(raiz)=removeAtual(*raiz);
            else if(ant->esq == atual)
                ant->esq = removeAtual(atual);
            else
                ant->dir=removeAtual(atual);

            calculaAltura(raiz);
            return 1;

        }
        //continua procurando v
        ant=atual;
        if(v < atual->info)
            atual=atual->esq;
        else
            atual=atual->dir;

    }
    return 0;//Elem nao foi removido

}
struct No * removeAtual(struct No * atual)
{
    struct No * p;
    struct No * q;

    if(atual->esq==NULL) //nao tem filho esquerdo
    {
        q=atual->dir;
        free(atual);
        return q;
    }

    p=atual;
    q=atual->esq;

    while(q->dir!=NULL)
    {
        p=q;
        q=q->dir;
    }   //procura o maior item da subarvooda da esquerda

    if(p!=atual)
    {
        p->dir=q->esq;
        q->esq=atual->esq;
        q->dir=atual->dir;
        free(atual);
        return q;
    }

    q->dir=atual->dir;
    free(atual);

    return q;

}
int calculaAltura(ArvBin* raiz)
{

    if(raiz==NULL)
        return 0;
    struct No * no=*(raiz);
    if(no==NULL)
        return 0;
    int altEsq=calculaAltura(&(no->esq));
    int altDir=calculaAltura(&(no->dir));
    if(altEsq>altDir)
    {
       no->alt=(altEsq+1);
        return altEsq+1;
    }

    else
    {
        no->alt=(altDir+1);
        return altDir+1;
    }


}

int qtdeNos(ArvBin * raiz)
{
    struct No * no=*(raiz);
    if(raiz==NULL)
        return 0;
    if(*(raiz)==NULL)
        return 0;

    int qtdeEsq=qtdeNos(&(no->esq));
    int qtdeDir=qtdeNos(&(no->dir));

    return (qtdeEsq+qtdeDir + 1);

}
int fatorBalanceamento(ArvBin * raiz)
{
    struct No * no=*(raiz);
    return(
           calculaAltura(&(no->esq))
           - calculaAltura(&(no->dir))

           );
}


int maior(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void rotacaoLL(ArvBin * raiz)
{
    struct No * no;
    struct No * atual= * raiz;
    no=atual->esq;          //(1)
    atual->esq = no->dir;   //(2)
    no->dir = atual;        //(3)

    //Recalculando Altura
    atual->alt = maior(
                       calculaAltura( &(atual->esq ) )
                       , calculaAltura(& (atual->dir))
                       )
                       +1;
    no->alt = maior(
                       calculaAltura( &(no->esq) )
                       , atual->alt
                       )
                       +1;

     *raiz=no;

}
void rotacaoRR(ArvBin * raiz)
{
    struct No * no;
    struct No * atual= * raiz;
    no=atual->dir;          //(1)
    atual->dir = no->esq;   //(2)
    no->esq = atual;        //(3)

    //Recalculando Altura
    atual->alt = maior(
                       calculaAltura( &(atual->esq ) )
                       , calculaAltura(& (atual->dir))
                       )
                       +1;
    no->alt = maior(
                       calculaAltura( & (no->dir) )
                       , atual->alt
                       )
                       +1;


     *raiz=no;

}

void rotacaoLR(ArvBin * raiz)
{
     struct No * atual= * raiz;
    rotacaoRR(&(atual->esq));
    rotacaoLL(raiz);

}

void rotacaoRL(ArvBin * raiz)
{
     struct No * atual= * raiz;
    rotacaoLL(&(atual->dir));
    rotacaoRR(raiz);

}

void prencherVetorEstatico(struct  No *  no , int p ,void ** vetor)
{
    if(no==NULL)
        return;
    vetor[p]=no;
    prencherVetorEstatico(no->esq,p*2+1,vetor);
    prencherVetorEstatico(no->dir,p*2+2,vetor);


}

void ** alocacaoEstatica(ArvBin * raiz)
{
    void ** vetor;
    int n,i;
    n=pow(2,calculaAltura(raiz))-1;

    vetor=(void **)malloc(sizeof(void *)*n);
    for(i=0;i<n;i++)
        vetor[i]=NULL;
    struct No * no = * (raiz);
    vetor[0]=no;
    prencherVetorEstatico(no,0,vetor);

    return vetor;

}
int getInfo(void * p)
{
    if(p==NULL)
        return 0;
    struct No * no =(struct No *)p;
    return no->info;
}
int getAlt(void * p)
{
    if(p==NULL)
        return 0;
    struct No * no =(struct No *)p;
    return no->alt;
}

buscaEmProfundidade(vi,n,Adj)

