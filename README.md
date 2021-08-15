# String Library
Welcome to my String Library(WIP).

Uses the C language(mingw/gcc).

***Tips***

All work here is simple and was created to be just a reference and a way to study the C language. 
Some tips you should take a look:

>You must know data structures even a bit to understand what is happening.
Good to start is understand what are arrays, lists and stacks. They probably are used here just once.

>You must know too pointers. At least the sufficient to understand reference and memory allocation.
Yeah, array sending over reference for functions and all those.

>I am using function pointers. You should take two looks to understand.
*I am not* saying you must know function pointers. You will learn it looking at the code. Just take look twice. 


# Object Oriented?

The 'methods' over here are not more than pointers - they are initialized as a pointer receiving an address, and setted as a pointer itself.

 >Remember this: ```p->stuff <==> (*p).stuff```
 
So, as I cannot type ```p.method(parameter)``` because it was constructed as a pointer, we assume that the initializazion of those methods must seek the same way of acessing members with the 'member access dot'(see above, the right one). Creating a member that is a ```(*pointer)``` is the way that we access the references of this pointer inside a struct or union, because here we just need the additional information of this pointer, which is a function reference - will expects parameters too, not just a simple pointer to a primitive data type. So, to access the members of the 'object', I use the 'member of struct/union pointer operator(->)'.

Now, if I write ```(*method)(type parameter1, type parameter2)``` I'm creating a member that expects a function pointer labeled 'method', which expects two parameters, as well as their data types. That can be noted in the code -  I've created the member, and instead of setting the names of the parameters variables, I wrote the datatypes only. 'Why?' Simple. If this is a representation of a  data type, I can't label it's values, just reasemble them. It just expect a data type, not allocates a variable. 


Is remarkable that those function pointers kind of implements the methods logic, even if limited. That's one of the many reasons you can't actually have a Object Oriented logic in C.

# Is it free to use?

Yes, of course it is! I just ask you to include a reference of this repository. (i accept a coffee too, or some cookies)


# How can I code with you?

To configure:
1. git clone this repo;
2. Use any text editor of your choice - but i prefer the [Visual Studio Code](https://code.visualstudio.com/). It can 'see' my comments of all method and functions properly, and has a built-in terminal. 
![VSCode showing you my comments](https://github.com/FLira2000/String/blob/master/assets/vscode%20print.png)
3. To 'execute', you must have the [MinGW C Language compiler](http://www.mingw.org/) installed in yout machine. Use the command ```gcc main.c String.h String.c -o main.exe``` - actually, you can use any name for the executable, but the 'main.exe' is already set in the `.gitignore`. 

#UPDATE 
So, I migrated to Linux some time ago, and now I'm `gcc` direct compilations.

So, with this setted, you can just open a new issue, and work on it. But, please create a good issue.
Also, I recommend the [git flow](https://danielkummer.github.io/git-flow-cheatsheet/index.html) method of team-coding. 

And that's all. I appreciate the help.
Thanks for coming here.
