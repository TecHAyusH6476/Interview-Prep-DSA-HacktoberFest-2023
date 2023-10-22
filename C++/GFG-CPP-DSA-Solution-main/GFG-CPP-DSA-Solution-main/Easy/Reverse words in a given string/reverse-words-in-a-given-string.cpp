//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string>vec ;
        string str = "";
         
         
        for(int i=0 ; i<S.size()   ; i++)
        {
            if(S[i] =='.')
            {
                vec.push_back(str) ;
                str="";
            }
            else{
            str += S[i] ;
            }
        }
           S=str ;
        reverse(vec.begin() , vec.end()) ;
        for(int i= 0; i<vec.size() ; i++)
        {
            str += "." + vec[i] ;
        }
        return str ;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends