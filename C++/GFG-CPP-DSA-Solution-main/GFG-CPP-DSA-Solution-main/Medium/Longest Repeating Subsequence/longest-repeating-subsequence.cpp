//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string &str){
		    int n = str.size();
		    string txt(str.begin(),str.end());
		    vector<int> prev(n+1),curr(n+1);
		    for(int i = 1; i <= n; i++){
		        for(int j = 1; j <= n; j++){
		            if(str[i-1] == txt[j-1] && i != j){
		                curr[j] = 1 + prev[j-1];
		            }
		            else{
		                curr[j] = max(prev[j],curr[j-1]);
		            }
		        }
		        prev = curr;
		    }
		    return prev[n];
		}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends