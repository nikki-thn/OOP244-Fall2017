#ifndef ICT_VALIDATE_H
#define ICT_VALIDATE_H

namespace ict {
	template <class T>
	bool validate(T min, T max, T testArr[], int numElement, bool arr[]){
		bool isValid = false;

		for (int i = 0; i < numElement; i++) {
			if (testArr[i] <= max && testArr[i] >= min) {
				isValid = true;
				arr[i] = !isValid;
			}

		}

		return isValid;
	}

}
#endif // !VALIDATE_H
