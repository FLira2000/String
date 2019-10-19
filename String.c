#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    char *stuff;
    struct s* self;
    int (*length)(struct s*);
    void (*forEach)(struct s*, void (*lambda)( void ));
}String;

int stringLength(String *string){
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    return i;
}

void forEach( String *string, void (*lambda)( void ) ){
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++){
        lambda();
    }
}

String* newString( char *string ){
    String *s = (String*) malloc(sizeof(String));
    s->stuff = string;
    s->self = s;
    s->length = &stringLength;
    s->forEach = &forEach;
    return s;
}

int callbackCounter = 0;

void callback( void ){
    printf("callback chamada pela %i vez\n", ++callbackCounter);
}

int main( void ){
    String *nome = newString("Fabio");
    printf("Nome: %s\n", nome->stuff);
    printf("Tamanho por metodo: %i\n", nome->length(nome->self));
    nome->forEach(nome->self, callback);
    callbackCounter = 0;
}