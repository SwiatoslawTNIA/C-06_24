//here I can use the vars:
#include <iostream>
extern int num;
void print_num(void)
{
   fprintf(stdout, "Hello!!!!<%d>", num);
}
//so we don't need to include the source code, since we compile and then link the files
//together using a linker, what we need however is a common naming conventions, and 
//proper syntax
//if we define int var = 1 in one file, it will be available for all the file, 
//to access it, we have to say extern int var;but to overwrite the default value 
//on the file scope level, just write static: static int var = 234;
//since the value is local, there is no attempt in redefining the value globally.
//so it works 