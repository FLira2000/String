#include <stdio.h>
#include <stdlib.h>

//This is the 'class' itself
typedef struct s{ 
    char *stuff;
    struct s* self;
    /*  
    Ok, now this could be confusing. Look wisely: the 'methods' over here are not more than pointers - they are initialized
    as a pointer receiving an address, and setted as a pointer itself.
    Remember this: p->stuff <==> (*p).stuff
    So, as I cannot type p.method(parameter) because it was constructed as a pointer, we assume that the initializazion
    of those methods must seek the same way of acessing members with the 'member access dot'(see above, the right one).
    Creating a member that is a (*pointer) is the way that we access the references of this pointer inside a struct or
    union, because here we just need the additional information of this pointer, which is a function reference - will 
    expects parameters too, not just a simple pointer to a primitive data type.
    Now, if I write (*method)(parameter, parameter2) I'm acessing a function pointer, and executing it passing the
    parameters. Note the similarity with the members below. Note too that I've created the member, and instead of setting
    the names of the parameters variables, I wrote the datatypes only. 'Why?' Simple. If this is a representation of a 
    data type, I can't label it's values, just reasemble them. It just expect a data type, not the variable name.  
    */
    int (*length)(struct s*); 
    void (*forEach)(struct s*, void (*lambda)( void )); //You can ask yourself why there's a name 'lambda' here.
    /*
    Read the last part of the bible above and take a moment. To create a function pointer, you must give to it a name,
    as I've done in the previous member. But, pay attention, here we have (*forEach)(parameters), and inside the parameters, 
    the same labeled 'lambda'. Resuming, this method expects a function as a parameter, which is the meaning of lambda.
    You should take a look in lambda functions by yourself to understand why this name shouldn't be 'lambda'.
    */
    int (*searchFor)(struct s*, char*); 
    int (*isBlank)(struct s*);
    int (*isEqual)(struct s*, char*);
}String;

//Method creation

//Count the length of a string inside the object String. Access the 'stuff' member.
int stringLength(String *string){ 
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    return i;
}

//Should be private.
int localLength( char* local ){ 
    int i = 0;
    for(i; local[i] != '\0'; i++);
    return i;
}

//Expects a function without parameters to be executed each character inside the string.
void forEach( String *string, void (*lambda)( void ) ){ 
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++){
        lambda();
        /*
            Pretty simple to understand when you are looking to it.
        */
    }
}

//Receives the String object and a char array, and searches inside the 'stuff' member of the object for the char array.
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

//Return 1 if the 'stuff' member is blank. 0 if not.
int isBlank( String *string ){ 
    int i = 0;
    for(i; string->stuff[i] != '\0'; i++);
    if(i == 0) return 1;
    else return 0;
}


//Return 1 if the pointer is NULL. 0 if not.
int isNull( String *string ){ 
    if(string == NULL){
        return 1;
    }
    if(string->stuff == NULL){
        return 1;
    }
    return 0;
}

int isEqual( String *string1, char *string2 ){
    int i = 0;
    if(string1->length(string1->self) != localLength(string2)) return 0;
    for(i; string1->stuff[i] != '\0'; i++){
        if(string1->stuff[i] != string2[i]) return 0;
    }
    return 1;
}

//Constructor. Receives the stuff in characters to fill the object that will be created.
String* newString( char *string ){
    String *s = (String*) malloc(sizeof(String));
    s->stuff = string;
    s->self = s;
    s->length = &stringLength;
    s->forEach = &forEach;
    s->searchFor = &searchFor;
    s->isBlank = &isBlank;
    s->isEqual = &isEqual;
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

    if(nome->isEqual(nome->self, "Fabio")) printf("igual");
    else printf("diferente");
    
}