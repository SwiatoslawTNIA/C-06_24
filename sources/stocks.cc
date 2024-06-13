#include "stocks.h"//the class declaration
#include "cstring"
#include "iostream"
//the implementation for the STOCK class:
Stock::~Stock()
{
   std::cout << "Destructing the object.\n";
}
//constructors:
Stock::Stock(void)
{
   strcpy(company, "no_name");
   shares = 0;
   share_val = 0.0;
   total_val = 0.0;
}
Stock::Stock(const char *co, long shares_number, double price)
{
   strcpy(company, co);
   if(shares_number < 0)
   {
      std::cerr << "Number of shares can't be negative" << ". The number of shares set to 0.";
      shares = 0;
   }
   if(price < 0)
   {
      std::cerr << "Price can't be negative. Price set to zero.";
      price = 0;
   }
   shares = shares_number;
   share_val = price;
   set_tot();
}

// void Stock::acquire(const char *company_name, long shares_number, double price)
// {
//    using namespace std;
//    strcpy(company, company_name);
//    company[strlen(company_name)] = '\0';//set the end to the string
//    if(shares_number < 0)
//    {
//       cout << "Number of shares can not be negative";
//       shares = 0;
//    }
//    else 
//       shares = shares_number;
//    share_val = price;
//    set_tot();//to 
// }
void Stock::buy(long number, double price)
{
   using namespace std;
   if(number < 0)
   {
      cout << "Can not purchase a negative number of shares."
      << "Transaction is aborted.";
   }
   else
   {
      shares += number;
      share_val = price;
      set_tot();//update the total value
   }
}
void Stock::sell(long number, double price)
{
   using namespace std;
   if(number < 0)
   {
      cout << "Number of shares sold can't be negative." << " Transaction is aborted." << endl;
   }
   else if(number > shares)
   {
      cout << "The number of shares currently on your balance is insufficient." << endl;
   }
   else
   {
      shares -= number;
      share_val = price;
      set_tot();
   }
}
void Stock::update(double price)
{
   share_val = price;
   set_tot();
}

void Stock::show(void) const //the const afterward means that we promise, that no value of the 
//object passed to show func will be altered.
   {
      std::cout << "Company: " << company
      << " Shares: " << shares << '\n'
      << " Share Price: $" << share_val
      << " Total Worth: $" << total_val << '\n';
   }

/*
Now we want to compare two objects, let's name the func compare:
it should take a ref to one object, to optimize the speed + return a ref :
Stock & compare(Stock & stock1);
we wouldn't change any of the stocks, so :
const Stock & compare(const Stock & stock1);
we promise, that we wouldn't change the object that uses the method:
const Stock & compare(const Stock & stock1) const;
definition: const Stock & Stock::compare(const Stock & stock1) const;

*/
const Stock & Stock::compare(const Stock & stock1) const
{
   if(stock1.total_val > total_val)
      return stock1;
   else
      return *this; //???, how to wer refer to the object, the method was called with? -> this:
   //essentially each private to the object var used inside the func is defined as :
   //this->total_val; this->shares_val; this->shares, etc..., it is the full form 
}

