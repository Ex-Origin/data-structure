#include <stdio.h>
#include <assert.h>

// Function to get the largest element from an array
int getMax(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

#define MAX_STACK 0x400
// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
	int output[MAX_STACK];
	int count[MAX_STACK];
	int max = (array[0] / place) % 10;
	assert(MAX_STACK >= size + 1);
	assert(MAX_STACK >= max + 1);

	for (int i = 1; i < size; i++) {
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	// Calculate cummulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
	// Get maximum element
	int max = getMax(array, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

// Driver code
int main() {
	int array[] = { 121, 432, 564, 23, 1, 45, 788 };
	int n = sizeof(array) / sizeof(int);
	radixsort(array, n);
	printArray(array, n);
	return 0;
}