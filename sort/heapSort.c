// Heap Sort in C

#include <stdio.h>

#define DEBUG

// Print an array
void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

// Function to swap the the position of two elements
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
#ifdef DEBUG
		printArray(arr, n);
#endif
	}

	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}


// Driver code
int main() {
	int arr[] = { 6, 1, 5, 9, 8, 4, 7 };
	int n = sizeof(arr) / sizeof(int);

	heapSort(arr, n);

	printf("Sorted array is \n");
	printArray(arr, n);
}