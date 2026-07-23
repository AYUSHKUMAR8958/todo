class Solution {
public:
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
    return prime;
}

    vector<int> closestPrimes(int left, int right) {
        vector<int>prime = prime_no(right);
        vector<int>closePrime;
        vector<int>firstPrime;
        for(int i = left;i<=right;i++){
            if(prime[i]){
                 closePrime.push_back(i);   
            }         
        }
        if(closePrime.size()<2){
                for(int i=0;i<2;i++ ){
                     firstPrime.push_back(-1);
                }
         }else{
           for (int i =0; i<2;i++){
            firstPrime.push_back(closePrime[i]);
               }
         }
        return firstPrime;
    }
    
};