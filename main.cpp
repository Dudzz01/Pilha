#include <stdio.h>
#include <stdlib.h>

//Implementei a Pilha em uma lista simplesmente encadaeada

void empilhar(int dado);
void imprimir();


typedef struct No{

    int dado;
    No *proximo;

}No;

No *Topo = nullptr;

void empilhar(int dado){

    No *novo = new No();
    novo->dado = dado;
    novo->proximo = Topo;
    Topo = novo;

}


void desempilhar(No *topo){

    if(Topo == topo && Topo!=nullptr){
        No *remover = Topo;
        Topo = Topo->proximo;
        delete(remover);
    }
    else{
        printf("Topo e/ou pilha nao encontrado");
    }

}

void busca(int dado){
    No *aux;

    for(aux = Topo; aux!=nullptr; aux = aux->proximo){
         if(aux->dado == dado){
             printf("Numero encontrado e a informacao do mesmo a seguir: Num end: %p  || Num dado: %d\n", aux, aux->dado);
             return;
         }
    }
    printf("Numero nao encontrado\n");
}

void imprimir(){
    if(Topo!=nullptr){
       No *aux;

        for(aux = Topo; aux!=nullptr; aux = aux->proximo){
            printf("Num end: %p || Dado: %d \n",aux,aux->dado);
        }
    }
    else{
        printf("Pilha nao encontrada");
    }
}

No * buscaTopo(){
    No *aux;
    aux = Topo;
    return aux;
}


int main() {

    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 9; i>=0; i--){
        empilhar(vetor[i]);
    }
    printf("Pilha antes de desempilhar\n");
    imprimir();
    desempilhar(Topo);
    printf("Pilha depois de desempilhar\n");
    imprimir();
    desempilhar(Topo);
    printf("Pilha depois de imprimir\n");
    imprimir();
    desempilhar(Topo);
    printf("Pilha depois de imprimir\n");
    imprimir();
    desempilhar(Topo);
    printf("Pilha depois de imprimir\n");
    imprimir();
    desempilhar(Topo);
    printf("Pilha depois de imprimir\n");
    imprimir();
    busca(7);
    printf("Buscando topo:   END: %p  ||   DADO: %d  ", buscaTopo(), buscaTopo()->dado);
    return 0;
}
