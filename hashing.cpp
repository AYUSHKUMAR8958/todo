#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cout << "enter n : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
 //pre compute
    map <int, int> mpp;             // int hash[n] = {0};
    for (int i = 0; i < n;i++){
        mpp[arr[i]]++;            // hash[arr[i]]++;
    }

    // int q;
    // cin >> q;


    while(n--){
        int number;
        cin >> number;

        //fetch
        cout << mpp[number];

    }
        return 0;
}
