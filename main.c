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

    if(nome->isEqual(nome->self, "Fabio")) printf("igual\n");
    else printf("diferente\n");   

    alocadoVazio->concat(alocadoVazio->self, nome);
    printf("%s concatenado\n", alocadoVazio->stuff);

    alocadoVazio->setString(alocadoVazio,"Nao esta mais vazio");
    printf("%s \n", alocadoVazio->stuff);

    alocadoVazio->forEach(alocadoVazio->self,  ({
        void lambda( void ){ printf("sou uma lambda\n");} //probably will show an error, but is correct.
        lambda;
    })
    );

    char * newNome = nome->exportString(nome->self);
    printf("%s", newNome); 
}