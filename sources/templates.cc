#include "templates.h"
void swap_double(double &a, double &b);
void swap_int(int &a, int &b);
void convert(void);
//a generic template:
template <class my_own_type>
void swap_generic(my_own_type &x, my_own_type &y);

template <class T_1, class T_2>
void add_some(T_1 x, T_2 y);

template <class T_1, typename T_2>
auto add_some_better(T_1 x, T_2 y) -> decltype(x + y);
int main(void)
{
   using namespace std;
   fprintf(stdout, "The revision of templates:\n\n");
   // //trying out the template:
   // unsigned long a = 4, b = 33;
   // cout << "a: " << a << ", b: " << b; 
   // swap_generic<unsigned long>(a, b);
   // cout << "\nAfter swapping: " << " a: " << a << ", b: " << b << endl;
   // float num_1 = 3.13123;
   // double num_2 = 4231.123123;
   // add_some(num_1, num_2);//the resulting type is double (d)
   // cout << "\nThe value";
   convert();
   return 0;
}
void swap_double(double &a, double &b)
{
   double temp = a;
   a = b;
   b = temp;
}
void swap_int(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}
template <class my_own_type>//the typename keyword passes here too.
void swap_generic(my_own_type &x, my_own_type &y)
{
   my_own_type temp = x;
   x = y;
   y = temp;
}
//if multiple types are present in the template:
template< class T_1, class T_2>
void add_some(T_1 x, T_2 y)
{
   using namespace std;
   //to construct a common type:
   decltype(x + y) result = x + y;
   cout << "The type of the addition: " << typeid(result).name() << endl;
}
//what if we wanted to return the value of two vars right away, we can't do that, because in the 
//template the return vars have not been defined yet, so a new syntax may be used:
//auto func_name(...) -> return_type;
template <class T_1, class T_2>
auto add_some_better(T_1 x, T_2 y) -> decltype(x + y)//decltype defines the return value 
{
   return x + y;
}
//exercise_3: <works>
void convert(void)
{
   using namespace std;
   bool done = false;
   while(!done)
   {
      cout << "\nEnter a string (q to quit): ";
      char arr[121];//the max length is 120;
      cin.getline(arr, 121);
      
      if(arr[0] == 'q' && arr[1] == '\0')
      {
         done = true;
         continue;
      }
      cout << "\n";
      for(int i = 0; arr[i] != '\0';++i)
      {//before giving the value to toupper, we should ensure, that that char is of type char:
         cout << static_cast<char>(toupper(static_cast<unsigned char>arr[i]));
      }
   }
}