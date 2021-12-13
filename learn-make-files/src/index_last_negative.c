#include "index_last_negative.h"

int index_last_negative(int* array, int arraySize) {
	for (int i = arraySize - 1; i >= 0; i--)
		if (array[i] < 0)
			return i;
	
	return -1;
}