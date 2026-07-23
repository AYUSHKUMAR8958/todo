#include <iostream>
#include <string>
using namespace std;

void bubbleSortStrings(string arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            // Compare strings
            if (arr[j] > arr[j + 1])
            {
                // Swap
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    string arr[n];

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSortStrings(arr, n);

    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}