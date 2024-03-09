#include <stdio.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void printSwaps(int swaps[], int size);

int main() {
    int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    printf("Bubble Sort for array1:\n");
    bubbleSort(array1, n1);

    printf("\nBubble Sort for array2:\n");
    bubbleSort(array2, n2);

    int array3[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int array4[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

    printf("\nSelection Sort for array1:\n");
    selectionSort(array3, n1);

    printf("\nSelection Sort for array2:\n");
    selectionSort(array4, n2);

    return 0;
}

void bubbleSort(int arr[], int n) {
    int totalSwaps = 0;
    int swaps[n];
    for (int i = 0; i < n; i++) {
        swaps[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[j]++;
                swaps[j + 1]++;
                temp = swaps[j];
                swaps[j]  = swaps[j+1];
                swaps[j+1] = temp;
                totalSwaps += 2;
            }

        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[i]);
    }
    printf("total # of swaps: %d\n", totalSwaps / 2);
}

void selectionSort(int arr[], int n) {
  int totalSwaps = 0;
  int swaps[n];
  for (int i = 0; i < n; i++) {
    swaps[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      swaps[min_idx]++;
      swaps[i]++;
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
      temp = swaps[min_idx];
      swaps[min_idx] = swaps[i];
      swaps[i] = temp;
      totalSwaps += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swaps[i]);
  }
  printf("total # of swaps: %d\n", totalSwaps / 2);
}

