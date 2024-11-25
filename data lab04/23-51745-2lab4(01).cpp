// NAME : TANMAY ROY RONY
//  ID  : 23-51745-2

#include <iostream>
#include <vector>
using namespace std;


void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        shifts++;
    }
}

int main() {
    vector<int> numbers = {92, 82, 21, 16, 18, 95, 25, 10};
    int comparisons, shifts;

    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;


    insertionSort(numbers, comparisons, shifts);


    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;


    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total shifts: " << shifts << endl;

    return 0;
}
