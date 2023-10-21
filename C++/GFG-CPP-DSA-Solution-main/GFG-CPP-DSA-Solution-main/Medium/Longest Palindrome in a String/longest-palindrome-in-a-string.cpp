//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   string longestPalin(string S) {
    if (S.empty()) {
        return "";
    }

    string longest = "";

    for (int i = 0; i < S.length(); i++) {
        // For odd-length palindromes
        string palindrome1 = expandAroundCenter(S, i, i);
        if (palindrome1.length() > longest.length()) {
            longest = palindrome1;
        }

        // For even-length palindromes
        string palindrome2 = expandAroundCenter(S, i, i + 1);
        if (palindrome2.length() > longest.length()) {
            longest = palindrome2;
        }
    }

    return longest;
}

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends