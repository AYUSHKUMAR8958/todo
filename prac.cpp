#include <iostream>
using namespace std;

// int reverse(int n ){
//     int ans = 0;
//     int count = 0;
//     int digit;
//     int original = n;
//     while (n != 0)
//     {
//         ans = ans * 10 + n%10;
//         n = n / 10;
//         count++;
//     }
//     if(ans == original){
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int amstrong(int n)
// {
//     int ams = 0;
//     int org = n;
//     while (n != 0)
//     {
//         int d = n % 10;
//         ams = ams + (d * d * d);
//         n = n / 10;
//     }
//     if(ams == org){
//         cout << ams;
//         cout << endl;
//         return 1;
        
//     }
//     else{
//         cout << ams;
//         cout << endl;
//         return 0;
//     }
// }


// int divisors(int n)
// {
//     vector<int> v;
//     // 6*6 = 36
//     // sqrt() takes more time because it  calls everytime in the loop  that increases the TC

//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             // cout<<i<<" "<<endl;
//             v.push_back(i);
//             if (n / i != i)
//             {
//                 v.push_back(n / i);
//             }
//         }
//     }
    // sort(v.begin(), v.end());
    // for (auto it : v)
    //     cout << it << " ";
    // return 0;
//}

// vector<int> prime_factor(int n)
// {
//     vector<int> imp;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             imp.push_back(i);
//             while (n % i == 0){ // to remove all occurence of that prime factor
//                 n = n / i;
//             }
//         }
//     }
//     if (n != 1)
//         imp.push_back(n); // always last value add the last value when n is prime and greater than 1

//     sort(imp.begin(), imp.end());
//     for (auto it : imp)
//         cout << it << " ";
//         return imp;   
// }

vector<int> prime_no(int n){

    vector<int> prime(n+1,1);
    vector<int> ans;

    prime[0]=prime[1]=0;

    for(int i=2;i*i<=n;i++){
        if(prime[i]){    // if(prime[i]) means the value is not zero
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i]){
            ans.push_back(i);
        }
    }

    return ans;   // ✅ REQUIRED
}

// 8
    

    // int n;
    // cout << "enter the no : ";
    // cin >> n;
    // int rev = reverse(n);
    // cout << rev;
    // int ams = amstrong(n);
    // cout << ams;
    //  divisors(n);

//   int p = prime_no(n);

//    cout << p;
   
// vector<int> p = prime_no(n);

   // for(int x : p){
   //     cout << x << " ";
   // }

//    string rem = "";
//    while(n!=1){
//        int dig = n % 2;
//        rem = rem + to_string(dig);
//        n = n / 2;
//    }
//    rem = rem + "1";
//    string rev = reverse(rem);
//    cout << rev;
//    cout << endl;

int main()
{
    string bin = "100111";
int x = bin.size();
int ans = 0;
int pow = 1;

// LEFT to RIGHT is simpler — no reversal needed
for (int i = x - 1; i >= 0; i--) {
    if (bin[i] == '1')
        ans += pow;
    pow *= 2;
}

cout << ans;  // should print 4
}
      