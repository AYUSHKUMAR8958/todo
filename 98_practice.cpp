#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;
/*int main (){
       vector<int> v{10,12,23,26,30};
       //v.erase(v.begin() + 2, v.begin() + 4);
       //int first = v[0];
       cout<< v[0]<<endl;
       vector<int> v1(5, 20); 
       vector<int>::iterator it = v1.begin();
it++;
cout << *(it) << " ";

it = it + 2;
cout << *(it) << " "<<endl;

       cout<< v1[0]<<endl;
       cout<< v1[1]<<endl;
       cout<< v1[2]<<endl;
       cout<< v1[3]<<endl;
       cout<< v1[4]<<endl;
       return 0;
       
}

int amstrong(int n ){
       if(n<=0) return 0;
       int ans = 0;
       while(n!=0){
              int d = n%10;
              ans = ans + (d*d*d);
              n= n/10;
       }
       return ans;
}*/
// check prime
 /*bool prime(int n){
       if (n<2) return 0;
       for(int i = 2 ;i <n ; i++ ){
              if (n%i==0)return 0;
       }
       return 1;
}
*/



int gcd(int a , int b){
       while(a>0&&b>0){
              if(a>b) a = a%b;
              else b = b%a;
       }
       if(a==0) return b;
       return a;
}


/*double powerExponentiation(int x, int n){
       int m = n;
       if(n<0) n= n*(-1);
  double ans = 1;
while(n>0){
       int m = n;
       if(n<0){
              n = n*-1;
       }
       if(n%2==1){
              ans = ans * x;
              n = n-1;
       }
       else {
              n = n/2;
              x = x*x;
       }
}
if (m<0) ans = 1/ans;
return ans;
}

/*int main(){
       double  a,b;
       cout<<"enter the no "<<endl;
       cin>>a>>b;
       int c = powerExponentiation(a,b);
       cout<<c;
        
       return 0;
}
*/
/*(int prime_factor(int n){
   vector<int> imp;
    for(int i= ;i*i<=n;i++){
        if(n%i==0){
            imp.push_back(i);
            while (n%i==0)
               n = n/i;         
        }
    }
    if(n!=1) imp.push_back(n);
    for (auto it : imp)
    cout << it << " ";

    return 0;
}
*/
/*int divisors(int n){
       vector<int>v;
       // 6*6 = 36
       // sqrt() takes more time because it  calls everytime in the loop  that increases the TC

       for(int i= 1;i*i<=n;i++){
        if(n%i==0){
              //cout<<i<<" "<<endl;
              v.push_back(i);
              if(n/i!=i){
                    v.push_back(n/i);
              }
        }
       }
       sort(v.begin(),v.end());
       for(auto i : v){
              cout<<i<<endl;
 }
 return 0;
}
bool prime(int n){
        int cnt = 0;
for(int i= 1;i*i<=n;i++){

        if(n%i==0){
              //cout<<i<<" "<<endl;
              cnt++;
              if(n/i!=i){
                   cnt++;
              }
        }
        if(cnt>2) break;
       }
       if(cnt==2) return true;
       else return false;
    }

    void NnumbersSum(int n,int sum){
	    if(n<1) {
           cout<<sum;
           return;
       }
        
         NnumbersSum(n-1,sum+n);
    }
   
int main(){
       int n;
       cout<<"enter the no"<<endl;
       cin>>n;
       //cout<<"enter m";
       //cin>>n;
        NnumbersSum(n,0);
  
       return 0;

}

int main() {
    map<int, int> numbers = {
        {1, 100},
        {2, 200},
        {3, 300}
    };

  cout<<numbers[2]<<endl;
  return 0 ;
}

void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}
 void reverse(int arr[], int n){
       int s = 0;
       int e = n-1;
       while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
       }
       printArray(arr, n);
    }
int main(){
       int arr[] = {1,2,3,4,5,6,7};
       int n = 7;
       reverse(arr,n);
       //printArray(arr, n);
       return 0;
    }
   
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
            }
            else if(nums1[i]<nums2[j]){
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }

// bubble sort by recursion
void bubble_sort(int arr[], int n) {
       if(n<=0) return;
        for (int j = 0; j <n; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];  //swap(arr[j],arr[j+1])
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        bubble_sort(arr, n-1);
    }
*/
void insertionSort(int arr[],int i,int n) {
        // code here
       if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertionSort(arr, i + 1, n);
}


void bubble_Sort(int arr[],int n){
       if(n<=0) return;
       for(int j =0;j<n-1;j++){
         if(arr[j]>arr[j+1]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
         }
         
       }
       bubble_Sort(arr,n-1);
}

int main(){
       int arr[] = {3,5,1,7,8,2};
       int n = 6;
//       bubble_Sort(arr,n);
//        for(int i = 0;i<n;i++){
//               cout<<arr[i]<<" ";
//        }

       gcd(4, 6);
       return 0;
}
    
