/*

                Under MIT CopyRight for Fábio Guimarães Lira Filho(@FLira2000)
                            String Library 2019

*/

//The 'Class' itself.
typedef struct s{ 
    //The string itself. To be professional, the 'one dimensional character array'. 
    char *stuff;
    //Pointer that points to itself. Looks crazy? Assume this is a 'this' reference.
    struct s* self;
    //Count the length of a string inside the object String. Access the 'stuff' member.
    int (*length)(struct s*); 
    //Expects a function without parameters to be executed each character inside the string.
    void (*forEach)(struct s*, void (*lambda)( void )); 
    //Receives the String object and a char array, and searches inside the 'stuff' member of the object for the char array.
    int (*searchFor)(struct s*, char*); 
    //Return 1 if the 'stuff' member is blank. 0 if not.
    int (*isBlank)(struct s*);
    //Receives the String object itself, and a char array, to compare then. Returns 1 if they are equal, or 0 if not.
    int (*isEqual)(struct s*, char*);
    //Concatenate a string to another.
    void (*concat)(struct s*, struct s*);

}String;

int stringLength(String *string);

void forEach( String *string, void (*lambda)( void ));

int searchFor( String *string, char* searching );

int isBlank( String *string );

int isNull( String *string );

int isEqual( String *string1, char *string2 );

void concat( String *destiny, String *toAdd);

String* newString( char *string );