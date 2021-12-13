#include "menu.h"

void menu(int action, int array[100], int arraySize) {
	int answer = 0;
	
	switch (action) {
		case 0:
			answer = index_first_negative(array, arraySize);
			break;
		case 1:
			answer = index_last_negative(array, arraySize);
			break;
		case 2:
			answer = sum_between_negative(array, arraySize);
			break;
		case 3:
			answer = sum_before_and_after_negative(array, arraySize);
			break;
        default:
            answer = -1;
	}
	
	if (answer == -1) {
		printf("Данные некорректны\n");
	} else {
		printf("%d\n", answer);
	}
}