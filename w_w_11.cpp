#include "Header.h"

#define SIZE_ARR 100

void randomaizer(int* arr, int size)
{
	std::cout << "call is randomaizer:\n";
	static int for_randomaizer{ 0 };
	srand(time(NULL) + for_randomaizer);
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	for_randomaizer++;
}

auto randon_array(int size) //bead
{
	std::shared_ptr<int> int_array = std::make_shared<int>(size);
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{	
		/*int_array[i] = rand() % 100;
		std::cout << int_array[i] << " ";*/
	}
	return int_array;
};

int get_max(int* arr, int size) //good
{
	int max = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void count_sort(int* arr, int size)
{
	std::cout << "call is count_sort:";
	int max = get_max(arr, size);
	int* count_arr = new int[max + 1];
	for (int i = 0; i < max + 1; ++i)
		count_arr[i] = 0;

	int* new_arr = new int[size];
	for (int i = 0; i < size; ++i)
		new_arr[i] = 0;

	for (int i = 0; i < size; ++i)
		count_arr[arr[i]]++;

	for (int i = 1; i < max + 1; i++)
		count_arr[i] += count_arr[i - 1];

	for (int i = 0; i < size; i++)
	{
		new_arr[count_arr[arr[i]] - 1] = arr[i];
		count_arr[arr[i]]--;
	}
	std::cout << "\n";

	for (int i = 0; i < size; i++)
	{
		arr[i] = new_arr[i];
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	delete[] new_arr;
	delete[] count_arr;
}

void radix_sort()
{

}

void w_w_11()
{
	int* int_arr = new int[SIZE_ARR];
	randomaizer(int_arr, SIZE_ARR);
	
	count_sort(int_arr, SIZE_ARR);
	randomaizer(int_arr, SIZE_ARR);



		
	delete[] int_arr;	





}
