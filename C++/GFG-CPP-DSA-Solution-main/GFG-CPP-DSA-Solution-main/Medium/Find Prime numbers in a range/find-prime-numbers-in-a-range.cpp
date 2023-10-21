//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int>ans;
        vector<int>primes(N+2,0);
        primes[0] = primes[1] = 1;
        for(int i=2;i*i<=N;i++){
            if(primes[i]==0){
                for(int j=i*i;j<=N;j+=i)
                    primes[j] = 1;
            }
        }
        
        for(int i=M;i<=N;i++){
            if(primes[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends