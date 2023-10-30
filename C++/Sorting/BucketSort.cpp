#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(float arr[], int size) {
    const int n = size;
    std::vector<float> buckets[n];

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    using namespace std;

    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
