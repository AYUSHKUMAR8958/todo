#include<iostream>
using namespace std;

//STL ---> STANDARD TEMPORARY LIBRARY 

// Pairs ---> under Utilities library
void explainPair() {
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second<<endl;

    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << p2.first << " " << p2.second.second << " " << p2.second.first<<endl;

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} };

    cout << arr[1].second<<endl;
}






//VECTORS. ----

void explainVector() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    vector<int> v{10,12,23,26,30}; // store 10 12 23 26 30
    vector<pair<int, int>> vec;
    v.push_back({1, 2});
    v.emplace_back(1, 2);

    vector<int> v(5, 100); // 100 100 100 100 100 

    vector<int> v(5); // 0 0 0 0 0

    vector<int> v1(5, 20); 
    vector<int> v2(v1);

    vector<int>::iterator it = v.begin();


it++;
cout << *(it) << " ";

it = it + 2;
cout << *(it) << " ";

vector<int>::iterator it = v.end();
vector<int>::iterator it = v.rend();
vector<int>::iterator it = v.rbegin();

cout << v[0] << " " << v.at(0);
cout << v.back() << " ";

for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
}

for (auto it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
}
}

//imp. for print 
for (auto it : v)
    cout << it << " ";

// Erase function
// {10, 20, 12, 23}
v.erase(v.begin() + 1);
// {10, 12, 23}

v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 35} [start, end]

// Insert function
vector<int> v(2, 100);  // {100, 100}
v.insert(v.begin(), 300);  // {300, 100, 100}
v.insert(v.begin() + 1, 2, 10);  // {300, 10, 10, 100, 100}

vector<int> copy(2, 50);  // {50, 50}
v.insert(v.begin(), copy.begin(), copy.end());  // {50, 50, 300, 10, 10, 100, 100}

cout << v.size();  // 7

// {10, 20}
v.pop_back();  // {10}

// v1 -> {10, 20}
// v2 -> {30, 40}
v1.swap(v2);  // v1 -> {30, 40}, v2 -> {10, 20}

v.clear();  // erases the entire vector

cout << v.empty();






// LIST 
void explainlist(){
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);

    ls_emplace_back();{2,4};
    //rest function are same as vectors
    //begin,end,rbegin,rend, clear,insert, size , swap

}




//DEQUE

void explainDeque() {
    deque<int> dq;
    dq.push_back(1);        // {1}
    dq.emplace_back(2);     // {1, 2}
    dq.push_front(4);       // {4, 1, 2}
    dq.emplace_front(3);    // {3, 4, 1, 2}

    dq.pop_back();          // {3, 4, 1}
    dq.pop_front();         // {4, 1}

    dq.back();
    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}




// STACK

void explainStack() {                      //LIFO
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {2, 1}
    st.push(3);    // {3, 2, 1}
    st.push(3);    // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // prints 5  "** st[2] is invalid **"

    st.pop(); // st looks like {3, 3, 2, 1}

    cout << st.top();  // 3
    cout << st.size(); // 4
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

//QUEUE

void explainQueue() {                  // FIFO
    queue<int> q;
    q.push(1);        // {1}
    q.push(2);        // {1, 2}
    q.emplace(4);     // {1, 2, 4}

    q.back() += 5;    // last element 4 becomes 9

    cout << q.back();   // prints 9
    // Queue now: {1, 2, 9}

    cout << q.front();  // prints 1
    q.pop();            // removes front -> {2, 9}

    cout << q.front();  // prints 2

    // size, swap, empty functions same as stack
}





//PRIORITY QUEUE


void explainPQ() {
    priority_queue<int> pq;

    pq.push(5);      // {5}
    pq.push(2);      // {5, 2}
    pq.push(8);      // {8, 5, 2}
    pq.emplace(10);  // {10, 8, 5, 2}

    cout << pq.top();  // prints 10
    pq.pop();          // removes 10 -> {8, 5, 2}

    cout << pq.top();  // prints 8

    // size, swap, empty functions same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq2; // for decending order
    pq2.push(5);      // {5}
    pq2.push(2);      // {2, 5}
    pq2.push(8);      // {2, 5, 8}
    pq2.emplace(10);  // {2, 5, 8, 10}

    cout << pq2.top();  // prints 2
}

//SET
void explainSet() {
    set<int> st;
    st.insert(1);   // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);   // {1, 2}
    st.insert(4);   // {1, 2, 4}
    st.insert(3);   // {1, 2, 3, 4}

    // Functionality of insert in vector can be used also, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), empty(), and swap() are same as above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3);   // points to 3

    // {1, 2, 3, 4, 5}
    auto it2 = st.find(6);  // points to st.end()

    // {1, 2, 3, 4, 5}
    st.erase(5);            // erases 5, takes logarithmic time

    int cnt = st.count(1);

    auto it3 = st.find(3);
    st.erase(it);          // erases element at iterator position

        auto it = st.find(3);
    st.erase(it);  // erases element at iterator, takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);  // after erase -> {1, 4, 5}  [first, last)

    // lower_bound() and upper_bound() function works in the same way as in vector
    auto it3 = st.lower_bound(2);
    auto it4 = st.upper_bound(3);

}



//MULTI SET


void explainMultiSet() {
    // Everything is same as set
    // only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1);  // {1}
    ms.insert(1);  // {1, 1}
    ms.insert(1);  // {1, 1, 1}

    ms.erase(1);  // all 1's erased

    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1) + 2);

    // rest all functions same as set
}


//UNORDERED SET

void explainUSet() {
    unordered_set<int> st;

    // lower_bound and upper_bound function
    // does not work, rest all functions are same
    // as above, it does not store in any
    // particular order, it has a better complexity
    // than set in most cases, except some when collision happens
}



//MAP



void explainMap() {
    map<int, int> mpp;

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({2, 4});
    mpp[{2, 3}] = 10; // This line is invalid for map<int,int> (works for map<pair<int,int>,int>)

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1] << endl;  //2
    cout << mpp[5] << endl;  //0

    auto it = mpp.find(3);
    cout << (it->second) << endl;  //1

    auto it2 = mpp.find(5);  
    if (it2 == mpp.end()) {
        cout << "Key not found" << endl;
    }
     auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
}



//MULTIMAP

void explainmultimap(){
    //everything is same as map, only it can store multiple keys.    (1,2)
    //only mpp[key] cannot use here                                  (1,3)
}

//UNORDERED MAP

void unorderedmap(){
    //same as map --> not sorted 
}


bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second()<p2.second()) return true;
    else if(p1.second()==p2.second()){
        if(p1.first()>p2.second()) return true;
    }
    return false;
}

void explainExtra() {
    sort(a, a + n);
    sort(v.begin(), v.end());

    sort(a+2, a+4);

    sort(a+n, a+n, greater<int>());

    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending

    sort(a, a+n, comp);

    // {4,1}, {2,1}, {1,2};

    int num = 7;
    int cnt = __builtin_popcount(num); // to get the no of 1s in the binary form of the no.

    long long num = 165786578687;
    int cnt = __builtin_popcountll(num); // for long long no

    string s = "123";
    sort(s.begin(),s.end());

    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    int maxi = *max_element(a,a+n);
}

int main(){
        explainExtra();
}
