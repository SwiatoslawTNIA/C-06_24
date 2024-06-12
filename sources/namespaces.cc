#include "namespaces.h"
int num; //the value is set to 0 by default + static storage duration + external linkage + file scope
static int num_2 = 1;//static storage duration + internal linkage + file scope
void example(void);
void experiment_1(void);
//to use the print_num func:
void print_num(void);
int main(void)
{
   std::cout << "Namespaces:\n\n";
   example();
   for(int i = 0; i < 3; ++i)
   {
      experiment_1();
   }
   print_num();
   return 0;
}
namespace exp_
{
   int num = 1;
   int sub = 2;
   void exam(void);
   struct denver
   {
      double price;
      char *name;

   };
   namespace sub_experiment
   {
      int sub_num = 545;
      int vitality = -1;
      void space(void);//function prototype.
   }
}

void example(void)
{
   using namespace exp_::sub_experiment;
   //a variable declared inside a function has no linkage, automatic storage duration, 
   //funct scope
   unsigned int doughnuts = 14;
   fprintf(stdout, "\n%d, ", doughnuts);//14
   //we can have another block:
   {
      unsigned int doughnuts = 12;
      fprintf(stdout, "%d, ", doughnuts);//12, redeclaring the var 
      //overwrites it for that scope.
      static int num_3 = 3;//static storage duration + block scope + no linkage
   }
   fprintf(stdout, "%d, ", doughnuts);//14

}
void experiment_1(void)
{
   static int n = 1;//it's defined al
   fprintf(stdout, "The value of the n is: %d \n" , n);
   ++n;
}
//in order to share funcs and so on among the files, a header file inclusion is sufficient
//, however with vars:
extern unsigned int value;//the value is defined elsewhere, before using it, we define it in this file
//so instead of writing std::cout we can write:
using std::cout;
//now for each object inside the declarative region of that statement, a cout can be used 
//instead of std::cout