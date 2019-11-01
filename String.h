/*

                Under MIT CopyRight for Fábio Guimarães Lira Filho(@FLira2000)
                            String Library 2019

*/
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

    //Count the length of a string inside the object String. Access the 'stuff' member.
    int (*length)(struct s*); 
    //Expects a function without parameters to be executed each character inside the string.
    void (*forEach)(struct s*, void (*lambda)( void )); 
    
    //You can ask yourself why there's a name 'lambda' here.
    /*
    Read the last part of the bible above and take a moment. To create a function pointer, you must give to it a name,
    as I've done in the previous member. But, pay attention, here we have (*forEach)(parameters), and inside the parameters, 
    the same labeled 'lambda'. Resuming, this method expects a function as a parameter, which is the meaning of lambda.
    You should take a look in lambda functions by yourself to understand why this name shouldn't be 'lambda'.
    */
    //Receives the String object and a char array, and searches inside the 'stuff' member of the object for the char array.
    int (*searchFor)(struct s*, char*); 
    //Return 1 if the 'stuff' member is blank. 0 if not.
    int (*isBlank)(struct s*);
    //Receives the String object itself, and a char array, to compare then. Returns 1 if they are equal, or 0 if not.
    int (*isEqual)(struct s*, char*);
}String;
int stringLength(String *string);

void forEach( String *string, void (*lambda)( void ));

int localLength( char* local );

int searchFor( String *string, char* searching );

int isBlank( String *string );

int isNull( String *string );

int isEqual( String *string1, char *string2 );

String* newString( char *string );