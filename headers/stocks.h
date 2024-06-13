#ifndef STOCKS_
#define STOCKS_
class Stock
{
private:
   char company[50];
   long shares;
   double share_val;
   double total_val;
   void set_tot(){total_val = share_val * shares;}
public:
   //a constructor:
   Stock(void);
   Stock(const char * co, long number_of_shares, double price);
   //a destructor:
   ~Stock(void);//must have no args, no return value and no decl type
   void acquire(const  char * co, long n, double pr);
   void buy(long num, double price);
   void sell(long num, double price);
   void update(double price);
   void show(void) const;
   //compare two stocks:
   const Stock & compare(const Stock & stock1) const;
};
#endif
//all the funcs defined inside of the class are of type inline, so it would be equivalent to:
//void set_tot(void);//the declaration inside of the class

//inline void Stock::set_tot(void){...};


