// Quick sort in C

#include <stdio.h>

// Function to swap position of elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {

    // Select the pivot element
    int pivot = array[high];
    int i = (low - 1);

    // Put the elements smaller than pivot on the left 
    // and greater than pivot on the right of pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}


// Function to print eklements of an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("   %3d", array[i]);
    }
    printf("\n");
}

void _quickSort(int array[], int low, int high) {
    if (low < high) {

        // Select pivot position and put all the elements smaller 
        // than pivot on left and greater than pivot on right
        int pi = partition(array, low, high);

        // Sort the elements on the left of pivot
        _quickSort(array, low, pi - 1);

        // Sort the elements on the right of pivot
        _quickSort(array, pi + 1, high);
    }
}

void quickSort(int array[], int length)
{
    _quickSort(array, 0, length - 1);
}

#define MAX_QUEUE 0x400
void _quickSortCircle(int array[], int low, int high, int length) {
    int queue[MAX_QUEUE], i, queue_start, queue_end, middle;
    int end;
    for (i = 0; i < MAX_QUEUE; i++)
    {
        queue[i] = -1;
    }
    queue_start = (0 % MAX_QUEUE);
    queue_end = queue_start;
    queue[queue_end] = low;
    queue_end = (queue_end + 1) % MAX_QUEUE;
    queue[queue_end] = high;
    queue_end = (queue_end + 1) % MAX_QUEUE;

    while (queue_end != queue_start)
    {
        if (queue[queue_start] < queue[queue_start + 1])
        {
            middle = partition(array, queue[queue_start], queue[queue_start + 1]);

            end = 0;
            for (i = 0; i < length; i++)
            {
                if (i == queue[queue_start] && i == middle)
                {
                    end = 1;
                    printf(" [{%3d", array[i]);
                }
                else if (i == queue[queue_start])
                {
                    printf(" [ %3d", array[i]);
                }
                else if (i == middle)
                {
                    end = 1;
                    printf("  {%3d", array[i]);
                }
                else if (i == queue[queue_start + 1] + 1 && end == 1)
                {
                    end = 0;
                    printf("}] %3d", array[i]);
                }
                else if (i == queue[queue_start + 1] + 1)
                {
                    printf(" ] %3d", array[i]);
                }
                else if (end == 1)
                {
                    end = 0;
                    printf("}  %3d", array[i]);
                }
                else
                {
                    printf("   %3d", array[i]);
                }
            }
            if (i == queue[queue_start + 1] + 1 && end == 1)
            {
                end = 0;
                printf("}]");
            }
            else if (end == 1)
            {
                end = 0;
                printf("}");
            }
            else if (i == queue[queue_start + 1] + 1)
            {
                printf(" ]", array[i]);
            }

            printf("\n");
            queue[queue_end] = queue[queue_start];
            queue_end = (queue_end + 1) % MAX_QUEUE;
            queue[queue_end] = middle - 1;
            queue_end = (queue_end + 1) % MAX_QUEUE;
            queue[queue_end] = middle + 1;
            queue_end = (queue_end + 1) % MAX_QUEUE;
            queue[queue_end] = queue[queue_start + 1];
            queue_end = (queue_end + 1) % MAX_QUEUE;

        }
        queue_start = (queue_start + 2) % MAX_QUEUE;

    }
}
void quickSortCircle(int array[], int length)
{
    _quickSortCircle(array, 0, length - 1, length);
}


// Driver code
int main() {
    int data[] = { 5,4,3,2,1,9,8,7,6 };
    int n = sizeof(data) / sizeof(data[0]);
    quickSortCircle(data, n);
    /*quickSort(data, n);
    printArray(data, n);*/
}