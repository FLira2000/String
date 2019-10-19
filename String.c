#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    char *stuff;
    struct s* self;
    int (*length)(struct s*);
}String;

int stringLength(String *string){
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    return i;
}


String* newString( char *string ){
    String *s = (String*) malloc(sizeof(String));
    s->stuff = string;
    s->self = s;
    s->length = &stringLength;
    return s;
}


int main( void ){
    String *nome = newString("Fabio");
    printf("Nome: %s\n", nome->stuff);
    printf("Tamanho por metodo: %i\n", nome->length(nome->self));
}