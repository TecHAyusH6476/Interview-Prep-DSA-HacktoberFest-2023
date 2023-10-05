/**
██████╗░██╗░░░██╗██████╗░██████╗░██╗██╗░░██╗  ██████╗░░█████╗░████████╗███████╗██╗░░░░░
██╔══██╗██║░░░██║██╔══██╗██╔══██╗██║██║░██╔╝  ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██║░░░░░
██████╔╝██║░░░██║██║░░██║██████╔╝██║█████═╝░  ██████╔╝███████║░░░██║░░░█████╗░░██║░░░░░
██╔══██╗██║░░░██║██║░░██║██╔══██╗██║██╔═██╗░  ██╔═══╝░██╔══██║░░░██║░░░██╔══╝░░██║░░░░░
██║░░██║╚██████╔╝██████╔╝██║░░██║██║██║░╚██╗  ██║░░░░░██║░░██║░░░██║░░░███████╗███████╗
╚═╝░░╚═╝░╚═════╝░╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚══════╝
Author:Rudrik Patel
Topic: 349. Intersection of Two Arrays
link: https://leetcode.com/problems/intersection-of-two-arrays/
*/

/*
    Naive Solution
    -->Time complexity: O(n*m)
    RUNS FOR SORTED OR UNSORTED ARRAY
*/  

void intersection(int a[],int b[],int m,int n){
    for(int i = 0;i<m;i++){
        if(i>0 && a[i] == a[i-1]){
            continue;
        }
        for(int j = 0;j<n;j++){
            if(a[i]==b[j]){
                cout<<a[i] << " ";
                break;
            }
        }
    }
}


/*
    Efficient Solution
    -->Time complexity: O(m+n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

