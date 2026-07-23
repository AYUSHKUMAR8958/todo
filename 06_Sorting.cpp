#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
       for (int i = 0; i <= n - 2; i++)
       {
              int mini = i;
              for (int j = i; j <= n - 1; j++)
              {
                     if (arr[j] < arr[mini])
                     {
                            mini = j;
                     }
              }
              int temp = arr[mini]; // swap(arr[i],arr[mini])
              arr[mini] = arr[i];
              arr[i] = temp;
       }
}

void bubble_sort(int arr[], int n)
{
       for (int i = n - 1; i >= 0; i--)
       {
              for (int j = 0; j <= i - 1; j++)
              {
                     if (arr[j] > arr[j + 1])
                     {
                            int temp = arr[j + 1]; // swap(arr[j],arr[j+1])
                            arr[j + 1] = arr[j];
                            arr[j] = temp;
                     }
              }
       }
}

// bubble sort by recursion
void bubble_sort(int arr[], int n)
{
       if (n <= 0)
              return;
       for (int j = 0; j < n; j++)
       {
              if (arr[j] > arr[j + 1])
              {
                     int temp = arr[j + 1]; // swap(arr[j],arr[j+1])
                     arr[j + 1] = arr[j];
                     arr[j] = temp;
              }
       }
       bubble_sort(arr, n - 1);
}

void insertionSort(vector<int> &arr)
{
       // code here
       int n = arr.size();
       for (int i = 1; i < n; i++)
       {
              int temp = arr[i];
              int j = i - 1;
              for (j = i - 1; j >= 0; j--)
              {
                     if (arr[j] > temp)
                     {
                            arr[j + 1] = arr[j];
                     }
                     else
                            break;
              }
              arr[j + 1] = temp;
       }
}

void insertionSort(int arr[], int n)
{
       for (int i = 1; i < n; i++)
       {
              // if(i==n) return;
              int j = i;
              while (j > 0 && arr[j - 1] > arr[j])
              {
                     int temp = arr[j - 1]; // swap(arr[j-1],arr[j])
                     arr[j - 1] = arr[j];
                     arr[j] = temp;
                     j--;
              }
       }
}

void insertionSort(int arr[], int i, int n){

       if (i == n)  return;
       int j = i;
       while (j > 0 && arr[j - 1] > arr[j])
       {
              int temp = arr[j - 1]; // swap(arr[j-1],arr[j])
              arr[j - 1] = arr[j];
              arr[j] = temp;
              j--;
       }

       insertionSort(arr, i + 1, n);
}



int main()
{
       int n;
       cout << "enter the element" << endl;
       cin >> n;
       int arr[n];
       for (int i = 0; i < n; i++)
              cin >> arr[i];

       // You can call any sort here
       // selection_sort(arr, n);
       insertionSort(arr, n);

       for (int i = 0; i < n; i++)
              cout << arr[i] << " ";
       cout << endl;
}