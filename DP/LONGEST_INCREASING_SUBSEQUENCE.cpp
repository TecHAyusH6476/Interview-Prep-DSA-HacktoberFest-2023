class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[prev]<arr[i]&&1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }if(dp[i]>maxi)
        maxi=dp[i];
        }
        return maxi;
    }
};
