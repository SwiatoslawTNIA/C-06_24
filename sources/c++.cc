//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
void example(void);
void swap(int & n_1, int & n_2);
void swap_2(int *n_1, int *n_2);
int main(void)
{
  using namespace std;
  cout << "Everything works alright.";
  example();
  return 0;
}
void example(void)
{
	int num_1 = 1, num_2 = 2;

	std::cout << "\nThe result: " << "num_1: " << num_1 << ", num_2: " << num_2;
	swap(num_1, num_2);
	std::cout << "\nThe result: " << "num_1: " << num_1 << ", num_2: " << num_2;
	std::cout << "\nNow using the swap_2 function(with a pointer): ";
	std::cout << "\nThe result: " << "num_1: " << num_1 << ", num_2: " << num_2;
	swap_2(&num_1, &num_2);
	std::cout << "\nThe result: " << "num_1: " << num_1 << ", num_2: " << num_2;
	
}
void swap(int & n_1, int & n_2)
{
	int temp = n_2;
	n_2 = n_1;
	n_1 = temp;
}
//the same version as above:
void swap_2(int *n_1, int *n_2)
{
	int temp = *n_1;
	*n_1 = *n_2;
	*n_2 = temp;
}