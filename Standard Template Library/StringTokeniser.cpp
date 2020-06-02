
//char *stroke(char *s, char *delimiters)
//return token on each subsequent call
//on first call function shoud be passed with string argument for 's'
//on subsequent calls we should pass the string argument as null
//maintain state of string internally using static array


#include "iostream"
#include <cstring>
#include <algorithm>

using namespace std;



char *mySTRTOK(char *str, char deli) {

	static char *input = NULL;

	if (str != NULL) input = str;


	//Base Case
	if (input == NULL) return NULL;

	char *output = new char[strlen(input) + 1];

	int i = 0;

	for (; input[i] != '\0'; i++) {

		if (input[i] != deli) {
			output[i] = input[i];
		}
		else {
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}

	}

	output[i] = '\0';
	input = NULL;
	return output;


}



int main() {

	char arr[100] = "Today is rainy day";


	/*char *ptr = strtok(arr, " " );

	cout << ptr << endl;

	while (ptr != NULL) {
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}*/


	cout << "Tokens using myStrTok Are: " << endl;

	char *ptr = mySTRTOK(arr, ' ' );

	cout << ptr << endl;

	while (ptr != NULL) {
		ptr = mySTRTOK(NULL, ' ');
		cout << ptr << endl;
	}


	return 0;
}