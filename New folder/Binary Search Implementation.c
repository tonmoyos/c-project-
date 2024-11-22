#include <stdio.h>


using namespace std;


int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


void displayArray(const vector<int>& arr) {
    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {45, 67, 23, 67, 88, 99, 100};
    int target;


    sort(arr.begin(), arr.end());


    displayArray(arr);

    cout << "Enter the number to search: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Number " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Number " << target << " not found in the array." << endl;
    }

    return 0;
}

