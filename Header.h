#pragma once
#include <iostream>
#include <algorithm>	//for TimSort w_w_11.cpp
#include <string>		//for w_w_11_6_fstream
#include <fstream>		//for w_w_11_6_fstream
#include <cstdlib>		//w_w_11_6_fstream
#include <ctime>		//w_w_11_6_fstream
#include <chrono>		// для получения времени w_w_11_6_fstream

void quick_sort(int* arr, int low, int high);	//w_w_11.cpp

void look(int*& arr, int& size);				//w_w_11.cpp ! size-1

void read_arr(const std::string& file_name, int*& arr, int& size);		//w_w_11_6_fstream

void write_arr(const std::string& file_name, const int* arr, const int size);		//w_w_11_6_fstream

void w_w_11();

void w_w_11_6_fstream();

void h_w_11();

void w_w_12();


