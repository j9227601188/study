#include "Header.h"

#define TEST_BASE_SIZE_BYTES 2'147'483'648			// 2 Gb
#define TEST_BASE_NAME "test_array_1Mb.txt"				// E:\cpp\study\test_array.txt

void generating_array_v1() {
	std::cout << "generating_array run:\n";

	//#include <fstream> cppreference.com/w/cpp/io/basic_fstream/open
	std::fstream tmp_fs_obj;
	tmp_fs_obj.open(TEST_BASE_NAME, std::fstream::out); // out = write; in = read; binary = binary mod !!!!!!!

	if (tmp_fs_obj.is_open() ) {
		std::cout << "tmp_fs_obj is open (+) \n";

		uint64_t size_test_array{ /*TEST_BASE_SIZE_BYTES / 4*/ 262'137 }; //536'870'912 integer [100-999] + ' ' = 2 Gb in .txt
		tmp_fs_obj << size_test_array << '\n';
		srand(time(nullptr));
		for (size_t i{ 0 }; i < size_test_array; ++i) {
			//std::cout << (i+1) << " is " << size_test_array << '\n';
			tmp_fs_obj << 100 + rand() % 900 << ' ';
		}
		tmp_fs_obj << '\n';
		tmp_fs_obj.close();

		std::cout << "tmp_fs_obj is close (+) \n";
	}

};

void h_w_11() {
	std::cout << "Func h_w_11() run:\n";

	//generating_array_v1();

	int* sort_arr = nullptr;
	int size_sort_array = 0;

	read_arr(TEST_BASE_NAME, sort_arr, size_sort_array);
	quick_sort(sort_arr, 0, size_sort_array-1);
	//look(sort_arr, size_sort_array);
	write_arr("sort_array_1Mb.txt", sort_arr, size_sort_array);

	delete[] sort_arr;
};