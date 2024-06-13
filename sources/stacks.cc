#include "stacks.h"
#include <iostream>
//implement the funcs:
Stack::Stack(void)
{
   is_full = false;
   is_empty = true;
   current_index = 0;
}
Stack::~Stack()
{
   std::cout << "Destructing an object.";
}
bool Stack::push(const double value)
{
   if(is_full)
      return false;
   else
   {
      array[current_index++] = value;
      if(current_index == 0)
         is_empty = false;
      if(current_index == MAX_SIZE)
         is_full = true;
      return true;
   }
}
bool Stack::pop(const double value)
{
   if(current_index == 0)
      return false;
   for(size_t i = 0; i < static_cast<size_t>(current_index);++i)
   {
      if(array[i] == value)
      {
         for(++i; i < static_cast<size_t>(current_index);++i)//increment the i by 1, pointing it to the next element
         {
            array[i - 1] = array[i];//shift the rest of the array by one
         }
         current_index--;
         if(is_full) 
            is_full = false;
         if(current_index == 0)
            is_empty = 0;
         return true;//stop iterating anyway;
      }
   }
   return false;
}
void Stack::show(void) const
{
   printf("The value of the array: [");
   for(size_t i = 0; i < static_cast<size_t>(current_index); ++i)
   {
      std::cout << array[i] << ", ";
   }
   printf("]\n");
}

