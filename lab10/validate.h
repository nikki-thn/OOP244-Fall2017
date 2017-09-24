#ifndef ICT_VALIDATE_H
#define ICT_VALIDATE_H

namespace ict {
	template <class T>
	bool validate(T min, T max, T testArr[], int numElement, bool arr[]){
		bool isValid = false;

		cout << "min " << min << "max " << max << endl;
		for (int i = 0; i < numElement; i++) {
			if (testArr[i] <= max && testArr[i] >= min) {
				cout << "test "<< testArr[i] << endl;
				isValid = true;
				arr[i] = true;
			}
			else {
				arr[i] = false;
			}
		}

		return isValid;
	}

}
#endif // !VALIDATE_H
