#include <iostream>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
      int smallest_index = i;
      for (int j = i+1; j < size; j++) {
          if (arr[j] < arr[smallest_index]) { smallest_index = j; }
      }
      int temp = arr[i];
      arr[i] = arr[smallest_index];
      arr[smallest_index] = temp;
    }
}


int findMedian(int arr[], int size) {
  selectionSort(arr,size);
  if (size % 2 == 0) {
      return arr[size/2];
  } else {
      return arr[size/2 - 1];
}
}

int main() {
  int arr1[6] = {5,6,3,4,8,1}; //[1,3,4,5,6,8]
  int arr2[7] = {5,3,8,9,1,4,7}; //[1,3,4,5,7,8,9]
  std::cout << findMedian(arr1,6) << std::endl << findMedian(arr2,7) << std::endl;
}