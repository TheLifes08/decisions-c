#include "sum_between_negative.h"

int sum_between_negative(int* array, int arraySize) {
	int sum = 0;
	int begin = index_first_negative(array, arraySize);
	int end = index_last_negative(array, arraySize);
	
	if (begin == -1 || end == -1)
		return -1;
	
	for (int i = begin; i < end; i++)
		sum += abs(array[i]);
	
	return sum;
}