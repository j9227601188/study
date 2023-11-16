#include "Header.h"
//#include "w_w_11.cpp"

void write_arr(const std::string& file_name, const int* arr, const int size) {
	std::fstream fs;

	fs.open(file_name, std::fstream::out);
	if (fs.is_open() ) {
		fs << size << '\n';

		for (int i = 0; i < size; i++) {
			fs << arr[i] << ' ';
		}
		fs << '\n';
		fs.close();
	}
};

void read_arr(const std::string& file_name, int*& arr, int& size) {
	std::fstream fs;

	fs.open(file_name, std::fstream::in);
	if (fs.is_open()) {
		fs >> size;	// читаем размер массива
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			fs >> arr[i];	// читаем из файла разделительные символы - пробел и перенос строки
		}
		fs.close();
	}
};

void w_w_11_6_fstream() {
	//https://en.cppreference.com/w/cpp/io/basic_fstream/open
	{
		//std::string file_name = "C://test/file_name.txt";
		//std::fstream fs;

		//fs.open(file_name);
		//// проверяем что файл успешно открыт
		//if (fs.is_open()) {
		//	// производим действия с файлом
		//	std::cout << "file_name.txt is open\n";

		//	fs.close();
		//}
	}

	std::string file_name = "array_data.txt";
	int size = 100;
	//std::cin >> size;
	int* rand_arr = new int[size];

	srand(time(nullptr));	// используем текущее время, чтобы сгенерировать рандомные значения
	int left_border = 0;
	int range_len = 1000; // правая граница = range_len + left_border
	for (int i = 0; i < size; i++) {
		rand_arr[i] = left_border + rand() % range_len;	//генерируем число в указанном диапазоне и записываем в массив
	}

	write_arr(file_name, rand_arr, size); // записываем массив в файл
	
	int* array_from_file = nullptr;
	int n = 0;
	read_arr(file_name, array_from_file, n); // читаем массив из файла
	
	auto start = std::chrono::high_resolution_clock::now(); // сохраняем время начала работы алгоритма
	quick_sort(array_from_file, 0, n-1); // запускаем сортировку
	auto finish = std::chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " sec" << '\n'; // вычисляем продолжительность работы в сек. и выводим на экран
	
	//look(array_from_file, n);
	
	delete[] rand_arr;
	delete[] array_from_file;
};
