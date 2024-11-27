#include <iostream>
using namespace std;
struct Athlete
{
    int speed;
};
void bubbleSort(Athlete athletes[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (athletes[j].speed > athletes[j + 1].speed)
            {
                Athlete temp = athletes[j];
                athletes[j] = athletes[j + 1];
                athletes[j + 1] = temp;
            }
        }
    }
}

int main() {

    Athlete athletes[] = {{12}, {23}, {15}, {18}, {30}, {11}};
    int size = sizeof(athletes) / sizeof(athletes[0]);


    bubbleSort(athletes, size);


    int minDiff = INT_MAX;
    int team[3] = {0};


    for (int i = 0; i < size - 2; i++) {
        int diff = (athletes[i + 2].speed - athletes[i].speed);
        if (diff < minDiff)
        {
            minDiff = diff;
            team[0] = athletes[i].speed;
            team[1] = athletes[i + 1].speed;
            team[2] = athletes[i + 2].speed;
        }
    }


    cout << "The relay team speeds with minimal difference are: ";
    for (int i = 0; i < 3; i++)
    {
        cout << team[i] << " ";
    }
    cout << endl;


    cout << "The minimum difference between the speeds is: " << minDiff << endl;


    cout << "Sorted speeds of all athletes: ";
    for (int i = 0; i < size; i++)
    {
        cout << athletes[i].speed << " ";
    }
    cout << endl;

    return 0;
}
