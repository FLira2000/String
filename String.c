#include <stdio.h>
#include <stdlib.h>
#include "String.h"

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

//Receives the String object itself, and a char array, to compare then. Returns 1 if they are equal, or 0 if not.
int isEqual( String *string1, char *string2 ){
    int i = 0;
    if(string1->length(string1->self) != localLength(string2)) return 0;
    for(i; string1->stuff[i] != '\0'; i++){
        if(string1->stuff[i] != string2[i]) return 0;
    }
    return 1;
}

//Concatenate a string to another.
void concat( String *toReceive, String *toAdd){
    int newSize = (toReceive->length(toReceive->self));
    newSize+= toAdd->length(toAdd->self);
    char *newP = (char*)  calloc(sizeof(char), newSize);

    int i = 0;
    for(i; i < toReceive->length(toReceive->self); i++){
        if(toReceive->stuff[i] != '\0')
            newP[i] = toReceive->stuff[i];
    }
    for(i; (i - toReceive->length(toReceive->self)) < toAdd->length(toAdd->self); i++){
        newP[i] = toAdd->stuff[i - toReceive->length(toReceive->self)];
    }

    toReceive->stuff = newP;
}

//Recieves the String object itself and a char array to set the value of array on object.
void setString(String *string, char *charArray){
    if(!isNull(string)){
        string->stuff = charArray;
    }
}

char* exportString(String *string){
    char *s = (char*) calloc(sizeof(char), string->length(string->self));
    for(int i = 0; i <= string->length(string->self); i++){
        s[i] = string->stuff[i];
    }
    return s;
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
    s->concat = &concat;
    s->setString = &setString;
    s->exportString = &exportString;
    return s;
}