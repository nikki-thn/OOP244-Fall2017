#ifndef ICT_VALIDATE_H
#define ICT_VALIDATE_H

#include "Car.h"
#include "Displayable.h"
#include "Employee.h"
#include "Student.h"

namespace ict {

	template <class T>
	bool validate(T& min, T& max, T* arr, int arrSize, bool* boolArr) {

		bool isValid = false;
		bool isTrue = true;

		for (int i = 0; i < arrSize; i++) {

			if (arr[i] >= min  && arr[i] <= max) {
				
				isValid = true;
				boolArr[i] = isValid;
			}
			else if (arr[i] <= min || arr[i] >= max) {
				isValid = false;
				boolArr[i] = isValid;
			}
		}
			for (int j = 0; j < arrSize; j++) {
				if (boolArr[j] != true) {
					isTrue = false;
				}
		}
		
		return isTrue;
	};
}
#endif
