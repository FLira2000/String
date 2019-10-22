#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    char *stuff;
    struct s* self;
    int (*length)(struct s*);
    void (*forEach)(struct s*, void (*lambda)( void ));
    int (*searchFor)(struct s*, char*);
    int (*isBlank)(struct s*);
}String;

int stringLength(String *string){
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    return i;
}

int localLength( char* local ){
    int i = 0;
    for(i; local[i] != '\0'; i++);
    return i;
}

void forEach( String *string, void (*lambda)( void ) ){
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++){
        lambda();
    }
}

int searchFor( String *string, char* searching ) {
    int i = 0; int condition = localLength(searching);
    for(i; string->stuff[i] != '\0'; i++){
        if( searching[0] == string->stuff[i] ){
            condition--;
            for( int y = 1; searching[y] != '\0'; y++ ){
                if( searching[y] == '\0') break;
                else if( searching[y] == string->stuff[i + y] ){
                    condition--;
                    continue;
                }else{
                    condition = localLength(searching);
                    break;
                }
            }
            if(condition == 0) return 1;
        }
    }
    return 0;
}

int isBlank( String *string ){ //No sense in add this function to a 'object' that is not defined, lol
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    if(i == 0) return 1;
    else return 0;
}

int isNull( String *string ){
    if(string == NULL){
        return 1;
    }
    if(string->stuff == NULL){
        return 1;
    }
    return 0;
}

String* newString( char *string ){
    String *s = (String*) malloc(sizeof(String));
    s->stuff = string;
    s->self = s;
    s->length = &stringLength;
    s->forEach = &forEach;
    s->searchFor = &searchFor;
    s->isBlank = &isBlank;
    return s;
}

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
    
}