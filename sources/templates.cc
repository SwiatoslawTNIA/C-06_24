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
//exercise 4:
template <class new_type>
new_type maxn(new_type arr[], const unsigned int arr_length);

//specialization:
template <> 
const char *maxn<const char *>(const char* arr_of_pointers[], const unsigned int num_of_pointers);
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
   // convert();
   //exercise 7:
   double arr[] = {34.324, 2234.234, -23.123};
   int arr_2[] = {23, -11, -12};
   cout << "maxn on arr: " << maxn(arr, 3);
   cout << "\nmaxn on arr_2: " << maxn(arr_2, 3);
   //trying to use specialization for the const char *s[] type:
   const char *arr_3[] = {
      "Jam", "Basketball", "Jolly", "Jenifer Natali", "Joseph MOurne"
   };
   const char *longest_string = maxn(arr_3, 5);
   cout << "\nThe longest string is: ";
   puts(longest_string);
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
         cout << static_cast<char>(toupper(static_cast<unsigned char>(arr[i])));
      }
   }
}
template <class new_type>
new_type maxn(new_type arr[], const unsigned int arr_length)
{
   new_type largest_element = arr[0];
   for(unsigned int i = 1; i < arr_length;++i)
   {
      if(largest_element < arr[i])
         largest_element = arr[i];
   }
   return largest_element;
}
template <> 
const char * maxn<const char *>(const char* arr_of_pointers[], const unsigned int num_of_pointers)
{
   unsigned long int max_length = 0, current_length = 0;
   const char *longest_string = NULL;
   if (*arr_of_pointers == NULL)
      return NULL;
   for(unsigned int i = 0; i < num_of_pointers;++i)//move through each of the pointers
   {
      for(int j = 0; arr_of_pointers[i][j] != '\0'; ++j, current_length++)
         ;//calculate the length of the current string
      if(max_length < current_length)
      {
         max_length = current_length;
         longest_string = arr_of_pointers[i];//set the pointer to point to the current string
      }
   }  
   return longest_string;
}