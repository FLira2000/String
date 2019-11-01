#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int callbackCounter = 0;

void callback( void ){
    printf("callback chamada pela %i vez\n", ++callbackCounter);
}

int main( void ){
    String *nome = newString("Fabio");
    String *naoAlocado;
    String *alocadoVazio = newString("");
    printf("Nome: %s\n", nome->stuff);
    printf("Tamanho por metodo: %i\n", nome->length(nome->self));
    nome->forEach(nome->self, callback);
    callbackCounter = 0;

    if(nome->searchFor(nome->self, "bio")) printf("Achei\n");
    else printf("Nao achei\n");

    if(isNull(naoAlocado)) printf("nao alocado\n");
    else printf("alocado\n");

    if(alocadoVazio->isBlank(alocadoVazio->self)) printf("vazio\n");
    else printf("com coisa dentro\n");

    if(nome->isEqual(nome->self, "Fabio")) printf("igual");
    else printf("diferente");   
}