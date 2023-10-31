#include <iostream>

int sentinelLinearSearch(int arr[], int size, int target) {
    int last = arr[size - 1];
    arr[size - 1] = target; // Set the last element as the sentinel

    int i = 0;
    while (arr[i] != target)
        i++;

    arr[size - 1] = last; // Restore the original last element

    if (i < size - 1 || arr[size - 1] == target)
        return i;
    else
        return -1;
}

int main() {
    using namespace std;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = sentinelLinearSearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
