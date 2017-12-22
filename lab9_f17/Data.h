// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>

namespace sict {

	const int LARGEST_NUMBER = 1000000000; // for min
	const int SMALLEST_NUMBER = 0; // for max
	const int COLUMN_WIDTH = 15; //output width

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n) {
		T largest = data[0];
		for (int i = 0; i < n; i++) {
			if (data[i + 1] > data[i]) largest = data[i];
		}
		return largest;
	}


	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T* data, int n) {
		T smallest = data[0];

		for (int i = 0; i < n; i++) {
			if (data[i + 1] < data[i]) smallest = data[i];
		}
		return smallest;
	}


	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T* data, int n) {
		T total = 0;
		for (int i = 0; i < n; i++) {
			total = total + data[i];
		}
		return total;
	}

	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		double avg = 0;
		for (int i = 0; i < n; i++) {
			avg = avg + data[i]; //get total first
		}
		avg /= n; //divide toal / n to get average
		return avg;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		
		bool success = false;
		T temp = 0;

		for (int i = 0; i < n; i++) {

			if (!input.fail()) {
				input.ignore();
				input >> temp;
				data[i] = temp;
				success = true;
			}
		}
		return success;
	}

	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(COLUMN_WIDTH);
		std::cout.setf(ios::right);
		std::cout << name;
		std::cout.unsetf(ios::right);
		
		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH);
			std::cout.setf(ios::right);
			std::cout << data[i];
			std::cout.unsetf(ios::right);
		}
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);

}

#endif