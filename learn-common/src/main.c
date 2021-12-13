#include <stdio.h>
#include <stdlib.h>

int getFirstNegativeNumberIndex(int* array, int arraySize) {
	for (int i = 0; i < arraySize; i++)
		if (array[i] < 0)
			return i;
	
	return -1;
}

int getLastNegativeNumberIndex(int* array, int arraySize) {
	for (int i = arraySize - 1; i >= 0; i--)
		if (array[i] < 0)
			return i;
	
	return -1;
}

int getSumBetweenNegativeNumbers(int* array, int arraySize) {
	int sum = 0;
	int begin = getFirstNegativeNumberIndex(array, arraySize);
	int end = getLastNegativeNumberIndex(array, arraySize);
	
	if (begin == -1 || end == -1)
		return -1;
	
	for (int i = begin; i < end; i++)
		sum += abs(array[i]);
	
	return sum;
}

int getSumBeforeAndAfterNegativeNumbers(int* array, int arraySize) {
	int sum = 0;
	int begin = getFirstNegativeNumberIndex(array, arraySize);
	int end = getLastNegativeNumberIndex(array, arraySize);
	
	if (begin == -1 || end == -1)
		return -1;
	
	for (int i = 0; i < begin; i++)
		sum += abs(array[i]);
	
	for (int i = end; i < arraySize; i++)
		sum += abs(array[i]);
	
	return sum;
}

int main() {
	int array[100] = { 0 }, arraySize = 0, action = 0, answer = 0;
	char nextSymbol = ' ';

	scanf("%d", &action);

	do {
		int value;
	
		scanf("%d", &value);
		scanf("%c", &nextSymbol);
		
		array[arraySize] = value;	
		arraySize++;
		
	} while (nextSymbol != '\n');
    
	switch (action) {
		case 0:
			answer = getFirstNegativeNumberIndex(array, arraySize);
			break;
		case 1:
			answer = getLastNegativeNumberIndex(array, arraySize);
			break;
		case 2:
			answer = getSumBetweenNegativeNumbers(array, arraySize);
			break;
		case 3:
			answer = getSumBeforeAndAfterNegativeNumbers(array, arraySize);
			break;
        default:
            answer = -1;
	}
	
	if (answer == -1) {
		printf("Данные некорректны");
	} else {
		printf("%d", answer);
	}
	
	return 0;
}
