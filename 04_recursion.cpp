#include<iostream>
using namespace std;

/*void recur(int a,int b){
       if(a<b){
              return;  //base case ,, imp in every recursive func
       }
       cout<<a<<endl;
       recur(a-1,b);
};
void recur(int a,int b){
       if(a>b){
              return;
       }
       cout<<a<<endl;
       recur(a+1,b);
};


//this is BACKTRACKING
void recur(int i,int n){          1 To N    
       if(i<1){
              return;
       }
       recur(i-1,n);        first this func executes
       cout<<i<<endl; 
};*/


/*void recur(int i,int n){       N To 1
       if(i>n){
              return;
       }
       recur(i+1,n);
       cout<<i<<endl;
};*/





// void printNumbers(int i,int n) {
//         if(i>n) return;
//         cout<<n-(i-1)<<endl;
//         printNumbers(i+1,n);
//     }

// void printName(int i,int n) {
//         if(i>n) return;
//         cout<<"AAYUSH"<<endl;
//         printName(i+1,n);
//     }





// int TotalSum(int i,int n){
//        if(i>n){
//               return 0;
//        }
//        return i + TotalSum ((i+1),n);
// }1

// void TotalSum(int i,int sum){     
//        if(i<0){
//               cout<<sum<<endl;
//               return;
//        }
//        TotalSum ((i-1),sum+i);   
// }


//FACTORIAL

// int fact(int n){
//        if(n==0||n==1){
//               return 1;
//        }
//        return n * fact(n-1);
// }


void printArray(int arr[], int n)
{
    cout << "The reversed array is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[],int n ){
       int s = 0;
       int e = n - 1;
       while(s<e){
              swap(arr[s], arr[e]);
              s++;
              e--;
       } 
       printArray(arr, n); 
}

// void reverseArrayRec(int arr[], int s, int e){
//        if(s>=e) return;
//        swap(arr[s], arr[e]);
//        reverseArrayRec(arr, s+1, e-1);  TWO POINTER APPROACH
// }

void reverseArrayRec(int arr[], int i, int n){
       if(i>=n/2) return;
       swap(arr[i], arr[n-i-1]);
       reverseArrayRec(arr, i+1, n);
}


//valid palindrome
bool palindrome(string s, int i, int n){
       if (i>=n/2)  return true;
       if(s[i]!=s[n-i-1]) return false;
       return palindrome(s, i + 1, n);
}
int main() {
       // int n;
       // cout<<"enter the nos ";
       // cin>>n;

       // int arr[] = {1, 2, 3, 4, 5};
       // int n = sizeof(arr) / sizeof(arr[0]);
       // reverseArrayRec(arr, 0, n);
       // for (int i = 0; i < n; i++)
       // {
       //        cout << arr[i] << " ";
       // }

       // printNumbers(1,n);

       int value = palindrome("nikn", 0, 4);
       cout << value << endl;
       return 0;
}
