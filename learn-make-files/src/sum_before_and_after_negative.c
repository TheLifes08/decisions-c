#include "sum_before_and_after_negative.h"

int sum_before_and_after_negative(int* array, int arraySize) {
	int sum = 0;
	int begin = index_first_negative(array, arraySize);
	int end = index_last_negative(array, arraySize);
	
	if (begin == -1 || end == -1)
		return -1;
	
	for (int i = 0; i < begin; i++)
		sum += abs(array[i]);
	
	for (int i = end; i < arraySize; i++)
		sum += abs(array[i]);
	
	return sum;
}