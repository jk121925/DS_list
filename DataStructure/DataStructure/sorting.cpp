#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count) {
	int i = 0; 
	for (i = 0; i < count; i++) {
		printf("%d ", value[i]);
	}
	printf("\n");
}


//sectionSort has O(n^2) time complexity ->comparing part
//sectionSort has O(n) time complexity -> change part
//this sorting function is (Best, Avg, Worst) = (O(n^2),O(n^2),O(n^2)) = O(n^2)
// ** Too slow and cannot satisfy safity
void selectionSrot(int value[], int count) {
	int i = 0, j = 0;
	int min = 0, temp = 0;

	for (i = 0; i < count - 1; i++) {
		min = i;
		for (j = i + 1; j < count; j++) {
			if (value[min] > value[j]) {
				min = j;
			}
		}
		temp = value[i];
		value[i] = value[min];
		value[min] = temp;

		printf("Step-%d,", i + 1);
		printArray(value, count);
	}
}


void bubbleSort(int value[], int count) {
	int i = 0, j = 0;
	int temp = 0;

	for (i = count - 1; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			printf("%d, %d\n", j,value[j-1]);
			if (value[j - 1] > value[j]) {
				temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
		}
		printf("Step-%d, ",count - i);
		printArray(value, count);
	}
}


int main(int argc, char *argv[]) {
	int values[] = { 80,50,70,10,60,20,40,30 };

	printf("Before Sort\n");
	printArray(values, 8);

	bubbleSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	return 0;
}