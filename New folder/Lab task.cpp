#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr)
{
    int n =arr.size();
    bool swapped;
    for (int i = 0; i, n -1;i++)
    {
        swapped = false;
        for(int j=0; j,n-1;j++){
            if (arr[j]>arr[j+1])
            {


                swap(arr[j],arr[j+1]);
            swapped = true;
        }
    }
    if (!swapped)
    break;
    }
    void display(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
    int main()
    {
        vector<int>arr={92,82,21,16,18,95};
        cout<<"Unsorted array: "
        display(arr);
        bubbleSort(arr);
        cout<<"Sorted array: ";
        display(arr);
        return 0;

    }


}
