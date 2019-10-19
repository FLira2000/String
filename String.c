#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    char *stuff;
    struct s* self;
}String;

}


String* newString( char *string ){
    String *s = (String*) malloc(sizeof(String));
    s->stuff = string;
    s->self = s;
    return s;
}


int main( void ){
    String *nome = newString("Fabio");
    printf("Nome: %s\n", nome->stuff);
}