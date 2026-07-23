
/// check palindrome for no

//optimal approach
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Negative numbers and multiples of 10 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        long long reversed = 0;
        int original = x;

        while (x != 0)
        {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }

        return reversed == original;
    }
};


// check palindrome

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int reversed = 0;

    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return x == reversed || x == reversed / 10;
}



// 2nd approach

#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int reversed = 0;

    while (n != 0)
    {
        int digit = n % 10;
        n /= 10;

        // Check for overflow/underflow before multiplying by 10
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
        {
            cout << "Overflow! Reversed number exceeds INT_MAX." << endl;
            return 0;
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
        {
            cout << "Underflow! Reversed number is less than INT_MIN." << endl;
            return 0;
        }

        reversed = reversed * 10 + digit;
    }

    cout << "Reversed number: " << reversed << endl;
    return 0;
}

// in most optimal approach

int reverse(int x)
{
    long r = 0;
    while (x != 0)
    {
        r = r * 10 + x % 10;
        x = x / 10;
    }
    if (r > INT_MAX || r < INT_MIN)
        return 0;
    return int(r);
}

//Amstrong no

int amstrong(int n)
{
    if (n <= 0)
        return 0;
    int ans = 0;
    while (n != 0)
    {
        int d = n % 10;
        ans = ans + (d * d * d);
        n = n / 10;
    }
    return ans;
}


//Prime No


//bruteForce approach
bool prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    else return 1;
}

//optimal approach
bool prime(int n)
{
    int cnt = 0 for (int i = 1; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            // cout<<i<<" "<<endl;
            cnt++;
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
        if (cnt > 2)
            break;
    }
    if (cnt == 2)
        return 1;
    else
        return 0;
}



int divisors(int n)
{
    vector<int> v;
    // 6*6 = 36
    // sqrt() takes more time because it  calls everytime in the loop  that increases the TC

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // cout<<i<<" "<<endl;
            v.push_back(i);
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}

// GCD OR HCF // Euclidean Algorithm
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0){
        return b;
    }
    return a;
}

// prime factors of a no
vector<int> prime_factor(int n)
{
    vector<int> imp;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            imp.push_back(i);
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n != 1)
        imp.push_back(n);
    return imp;
    /*for (auto it : imp)
    cout << it << " ";

    return 0; for printing vector*/
}


// remove all occurence

string removeOccurrences(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}   



// valid palindrome
bool isPalindrome(string s)
{

    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}



// BINARY SEARCH

int search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // mid declared once per loop

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}


// intersection
vector<int> intersection(vector<int> &a, vector<int> &b)
{
    set<int> s(a.begin(), a.end()); // store elements of a
    vector<int> result;

    for (int x : b)
    {
        if (s.find(x) != s.end())
        { // if x is found in set
            result.push_back(x);
            s.erase(x); // remove to avoid duplicates
        }
    }

    return result;
}



//Intersection of two vectors 

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return ans;
}
