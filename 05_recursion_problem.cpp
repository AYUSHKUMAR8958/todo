//#include<bits/stdc++.h>
#include<iostream>
#include <utility>
using namespace std;

/* PARAMETRIZED RECURSION

void NnumbersSum(int n,int sum){
	    if(n<1) {
           cout<<sum;
           return;
       }
        
         NnumbersSum(n-1,sum+n);
    }

    // FUNCTIONAL RECURSION 
int NnumbersSum(int n){
	    if(n==0) {
              return 0;
       }
        
        return n + NnumbersSum(n-1);
    }



    // factorial of n
    int fact(int n){
	    if(n==1) {
              return 1;
       }
        return n * fact(n-1);  // T.C = O(N).  S.C = O(N)
    }*/
    

// reverse an array
void rev(int i,int arr[],int n){
       if(i>n/2) return ;
       swap(arr[i],arr[n-i-1]);
       rev(i+1,arr,n);
}

int main(){
       int n;
       cout<<"enter the no "<<endl;
       cin>>n;
       int arr[n];
       for(int i=0 ; i<n; i++) cin<<arr[i];
       rev(0,arr,n);
       for(int i=0 ; i<n; i++) cout<<arr[i]<<" ";
       //cout<<"enter m";
       //cin>>n;
       //NnumbersSum(n);
       //cout<<"sum "<<NnumbersSum(n)<<endl;

       //fact(n);
       //cout<<"factorial "<<fact(n);
       return 0;

}