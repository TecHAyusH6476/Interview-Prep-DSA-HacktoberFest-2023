//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int len = str.size() ;
        int start = 0 ;
        int end = len-1 ;
        while(start < end )
        {
            char temp = str[start] ;
            str[start] = str[end] ;
            str[end] = temp ;
            start++;
            end-- ; 
        }
        return str ;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends