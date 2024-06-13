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
double cube(const double &entity);
const char *new_string(const char *old_str, int str_length);
const char *addString(const char *old_string, const char *string_to_add);
int main(void)
{
  using namespace std;
//   cout << "Everything works alright.";
//   example();
	// double side = 3.0l;
	// double *p = &side;
	// double &ref = side;//create a ref
	// cout << "\n" << cube(side);
	// cout << "\n" << cube(*p);
	// cout << "\n" << cube(ref);
	// cout << "\n" << cube(3.0);
	// //rvalue:
	// double && rvalue = sqrt(26.34);
	// cout << "\nThe result: " << rvalue;
	// const char *s = "What a wonderful day.";
	// const char *new_s = new_string(s, 10);
	// puts(new_s);
	// //second arr:
	// const char *s_2 = "A second example of a string";
	// const char *s_2_new = new_string(s_2, 12);
	// puts(s_2_new);
	// delete []s_2_new;
	// delete []new_s;
	char str1[] = "A first string.";
	const char *str2 = " This one should go afterwards";
	const char *tog = addString(str1, str2);
	puts(tog); 
	cout << "The length of the string: " << strlen(tog) << "\n";
	free((void *)tog);
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
//the const &: 
double cube(const double &entity)
{
	return entity * entity * entity;
}
//the func should return a new string with the str_length elements of the old string
const char *new_string(const char *old_str, int str_length = 1)
{
	using namespace std;
	if(old_str == nullptr)
		return NULL;
	//it's not empty:
	char *new_str = new char[str_length + 1];
	if(new_str == nullptr)
	{
		perror("Unable to allocate memory. Exiting... ");
		exit(EXIT_FAILURE);
	}
	 int i = 0;//register is not allowed
	for(; i < str_length && old_str[i];++i)//provided that the user selects more chars than there 
	//is in an array
	{
		new_str[i] = old_str[i];
	}
	new_str[i] = '\0';
	return new_str;
}
const char *addString(const char *old_string, const char *string_to_add)
{
	if(old_string == nullptr)
		return NULL;
	else if(string_to_add == nullptr)
		return old_string;
	//allocate the memory for the new string:
	size_t total_string_length = 0;
	while(old_string[total_string_length])
		++total_string_length;
	unsigned int temp = 0;
	while(string_to_add[temp++])
		++total_string_length;
	
	//allocate memory:
	char *new_string = (char *)malloc(sizeof(char)*(total_string_length + 1));
	if(new_string == nullptr)
	{
		perror("Unable to allocate memory.");
		exit(EXIT_FAILURE);
	}
	size_t new_arr_index = 0, old_arr_index = 0;
	while(old_string[old_arr_index])
	{
		new_string[new_arr_index++] = old_string[old_arr_index++];
	}
	old_arr_index = 0;
	while(string_to_add[old_arr_index])
	{
		new_string[new_arr_index++] = string_to_add[old_arr_index++];
	}
	new_string[new_arr_index] = '\0';//terminate the new string;
	return new_string;
}


