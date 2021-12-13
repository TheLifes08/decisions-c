#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparator(const void* x1, const void* x2) {
	const int* v1 = (const int*)x1;
    const int* v2 = (const int*)x2;
    
    if (*v1 > *v2) {
        return 1;
    } else if (*v1 < *v2) {
        return -1;
    } else {
        return 0;    
    }
}

int main() {
	int array[1000];

	for (int i = 0; i < 1000; i++) {
		scanf("%d", &(array[i]));
	}

	qsort(array, 1000, sizeof(int), comparator);

	clock_t time1 = clock();
    
    int value = 0;
	int* element = bsearch(&value, array, 1000, sizeof(int), comparator);

	clock_t time2 = clock();

	if (element != NULL) {
		printf("exists\n");
	} else {
		printf("doesn't exist\n");
	}

	printf("%f\n", (time2 - time1) / CLOCKS_PER_SEC);

	time1 = clock();
    
    element = NULL;
	for (int i = 0; i < 1000; i++) {
		if (array[i] == 0) {
			element = array + i;
			break;
		}
	}

	time2 = clock();

	if (element != NULL) {
		printf("exists\n");
	} else {
		printf("doesn't exist\n");
	}

	printf("%f\n", (time2 - time1) / CLOCKS_PER_SEC);

	return 0;
}
