#include <iostream>
#include "stocks.h"
#include "stacks.h"
int main(void)
{
   // {
   //    // a small implementation of the Stock class:
   //    Stock cat;
   //    //use flat-point notation:
   //    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
   //    std::cout.precision(3);
   //    cat.show();
   //    cat.buy(15, 18.125);
   //    cat.show();
   //    cat.buy(40000, 40.125);
   //    Stock cow("Milking_Co", 12400, 1.24);//the same as Stock cow = Stock("Milking_Co..")
   //    cow.show();
   //    cow.sell(3000, 5000.0);
   //    cow.show();
   //    cat = cow;
   //    // std::cout << "Bye.!!!";
   //    const Stock james = Stock("Lanisters", 50000, 34.323);
   //    james.show();//an error, the func show doesn't promise to change the 
   //    //original object, so the const object can't be used with it, => the new syntax 
   //    //must be devised to control if the function changes the values of the object it is called on:
   //    //void show(void) const;
   //    Stock top = james.compare(cow);
   //    std::cout << "This company is bigger: ";
   //    top.show();
   // }
   Stack new_stack = Stack();
   new_stack.push(324.32);
   new_stack.show();
   new_stack.push(232);
   new_stack.push(12);
   new_stack.show();
   new_stack.pop(324.32);
   new_stack.show();
   #define STKS 10
   const Stock stocks[STKS] = {
      Stock("NanoSmart", 12, 20.0),
      Stock("Boffo Objects", 200, 2.0),
      Stock("Monolithic Obelisks", 130, 3.25),
      Stock("Fleep Enterprises", 60, 6.5)
   };
   //define + initialize 10 stocks -> find the highest total value:
   //to keep track of the result:
   const Stock *highest_t_value = &stocks[0];
   for(int i = 1; i < STKS; ++i)
   {
      highest_t_value = &highest_t_value->compare(stocks[i]);//flaw: each time two 
      //adjacent stocks are compared, instead of comparing the stock with the highest
      //value with the current stock
   }
   //print the stock with the highest total value:
   highest_t_value->show();//to show the highest value, again if we have a pointer 
   // to a class, and wanna use a member func of that class, we should use "->" notation
   //classlike enums:
   // enum size = {SMALL, MEDIUM, LARGE};
   // enum ice_cream_size = {SMALL, MEDIUM, LARGE};
   //the problem arises with the members of the enums, to avoid it: 
   enum class size {SMALL, MEDIUM, LARGE};
   enum class ice_cream_size {SMALL, MEDIUM, LARGE};
   size house = size::MEDIUM;
   ice_cream_size ice_cream_i_want = ice_cream_size::SMALL;
   //the scope of the enum will be defined
   return 0;
}
