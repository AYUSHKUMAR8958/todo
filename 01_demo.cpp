#include <iostream>
#include <string>
using namespace std;

int main() {
    //int x;
    //cin >> x;
    //cout << "Hey " << x<<endl;
   // cout<<"helo"<<endl;
    string st = "aayush";
    string str;
    //getline(cin,str);
    //cout<<str;
    int len=st.size();
    st[len-1]='p';
    cout<<st[len-1];
    return 0;
}
