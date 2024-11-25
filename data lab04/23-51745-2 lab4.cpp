//NAME : TANMAY ROY RONY
// ID  : 23-51745-2

#include <iostream>
#include <vector>
using namespace std;


void selectionSort(vector<int>& arr, int& comparisons, int& exchanges) {
    int n = arr.size();
    comparisons = 0;
    exchanges = 0;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;


        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            exchanges++;
        }
    }
}

int main() {
    vector<int> numbers = {92, 82, 21, 16, 18, 18, 95, 25, 10};
    int comparisons, exchanges;

    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;


    selectionSort(numbers, comparisons, exchanges);


    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;


    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total exchanges: " << exchanges << endl;

    return 0;
}
