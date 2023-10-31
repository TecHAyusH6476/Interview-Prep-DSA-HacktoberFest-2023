#include <iostream>

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);
        
        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

int main() {
    using namespace std;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = interpolationSearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
