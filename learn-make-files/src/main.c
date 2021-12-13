#include "menu.h"

int main() {
	int array[100] = { 0 }, arraySize = 0, action = 0;
	char nextSymbol = ' ';

	scanf("%d", &action);

	do {
		scanf("%d%c", &array[arraySize], &nextSymbol);
		arraySize++;
	} while (nextSymbol != '\n');
    
	menu(action, array, arraySize);
	
	return 0;
}