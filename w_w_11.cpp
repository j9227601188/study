#include "Header.h"

#define SIZE_ARR 100
#define BIT_depth_of_numbers 10000

void randomaizer(int* arr, int size)
{
	std::cout << "	call is randomaizer:\n";
	static int for_randomaizer{ 0 };
	srand(time(NULL) + for_randomaizer);
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % BIT_depth_of_numbers;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	for_randomaizer++;
}
void look(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

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
	std::cout << "	call is count_sort:";
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
void count_sort(int* arr, int n, int exp)
{
	int* output = new int[n];
	int count[10] = { 0 }; // выделяем память под массив частот размером 10, 
	//так как используем 10-чную систему счисления

	// вычисление разряда элемента arr[i] выполняет выражение 
	// (arr[i] / exp) % 10
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;  // вычисляем значение разряда и считаем его частоту

	for (int i = 1; i < 10; i++)    //копим частоты
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {                          //ну ок
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)     //фиксируем результат
		arr[i] = output[i];

	delete[] output; //чистим за собой
}

void radix_sort(int* arr, int size)
{
	std::cout << "	call is radix_sort:\n";

	int m = get_max(arr, size); // находим максимальное число
	// выполняем сортировку массива, пока не дойдем до старшего разряда наибольшего числа 

	for (int exp = 1; (m / exp) > 0; exp *= 10)
		count_sort(arr, size, exp);

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	
	std::cout << "\n";
}

//bucket_sort
struct bucket {
	int count; // количество элементов в корзине
	int* data; // массив элементов корзины
};

int getExp(int value) {
	int exp = 1;

	while (value > 10)
	{
		value /= 10;
		exp *= 10;
	}

	return exp;
};

void countSort(int* arr, int n)
{
	if (!n)
		return;
	int* output = new int[n];
	int max = get_max(arr, n);
	int* count = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[arr[i]]++;  // подсчитываем  частоту повторения элементов

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];  // вычисляем накопленные суммы

	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];  // устанавливаем элемент на корректное место 
		count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	for (int i = 0; i < n; i++) {
	}
	delete[] output;
	delete[] count;
};

void bucket_sort(int* arr, int n)
{
	std::cout << "	call is bucket_sort:\n";

	struct bucket buckets[10];
	// вычисляем значение экспоненты
	int exp = getExp(get_max(arr, n));

	for (int i = 0; i < 10; i++)
	{
		buckets[i].count = 0;
		buckets[i].data = new int[n];
	}
	for (int i = 0; i < n; i++) {
		int bi = arr[i] / exp; // вычисляем индекс корзины
		buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
	}

	// здесь реализуйте шаг 4 описанный в алгоритме
	int ptr_ind__arr = 0;

	for (int i = 0; i < 10; i++) {
		//сортировка в корзинах
		countSort(buckets[i].data, buckets[i].count);

		//сборка массива
		int q = 0;
		while (buckets[i].count) {
			arr[ptr_ind__arr] = buckets[i].data[q];
			std::cout << arr[ptr_ind__arr] << " ";
			ptr_ind__arr++;
			buckets[i].count--;
			q++;
		}
	}

	std::cout << "\n";
};

//Bubble sort

void swap(int& a, int& b) {
	int boofer = a;
	a = b;
	b = boofer;
};

void bubble_sort(int* arr, int size) {

	std::cout << "	call is bubble_sort:\n";

	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	look(arr, size);
	std::cout << "\n";
}

//Merge sort - WARNING
void merge_for_merge_sort(int* arr, int l, int m, int r) {
	int l_size_arr = m - l + 1;
	int r_size_arr = r - m;

	int* l_arr = new int[l_size_arr];
	int* r_arr = new int[r_size_arr];

	for (int i = 0; i < l_size_arr; i++) {
		l_arr[i] = arr[l + i];
	}
	for (int i = 0; i < r_size_arr; i++) {
		r_arr[i] = arr[m +1 + i];
	}

	int i = 0, j = 0, k = l; //indexes
	while (i < l_size_arr && j < r_size_arr) {
		if (l_arr[i] <= r_arr[j]) {
			arr[k++] = l_arr[i++];	//or arr[k++] = l_arr[i++];
			//i++;
			//k++;
		}
		else {
			arr[k++] = r_arr[j++];
			//j++;
			//k++;
		}
	}
	while (i < l_size_arr) {
		arr[k++] = l_arr[i++];
	}
	while (j < r_size_arr) {
		arr[k++] = r_arr[j++];
	}

	delete[]l_arr;
	delete[]r_arr;
};

void merge_sort(int* arr, int l, int r) {
	if (l >= r)
		return;

	int m = (l + r - 1) / 2;
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);
	merge_for_merge_sort(arr, l, m, r);
};

//Insertion sort
void insertion_sort(int* arr, int size) {

}
//go
void w_w_11()
{
	int* int_arr = new int[SIZE_ARR];
	randomaizer(int_arr, SIZE_ARR);
	
	//count_sort(int_arr, SIZE_ARR);
	//randomaizer(int_arr, SIZE_ARR);

	//radix_sort(int_arr, SIZE_ARR);
	//randomaizer(int_arr, SIZE_ARR);

	//bucket_sort(int_arr, SIZE_ARR);
	//randomaizer(int_arr, SIZE_ARR);

	//bubble_sort(int_arr, SIZE_ARR);

	std::cout << "	merge_sort its run: \n";
	merge_sort(int_arr, 0, SIZE_ARR - 1);
	look(int_arr, SIZE_ARR);

	//insertion_sort(int_arr, SIZE_ARR);
		
	delete[] int_arr;	
}
