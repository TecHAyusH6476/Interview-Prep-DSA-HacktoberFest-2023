//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
    if(B != 0)
        return gcd(B,A%B);
        
    else
        return A;
 
	} 
};


//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends