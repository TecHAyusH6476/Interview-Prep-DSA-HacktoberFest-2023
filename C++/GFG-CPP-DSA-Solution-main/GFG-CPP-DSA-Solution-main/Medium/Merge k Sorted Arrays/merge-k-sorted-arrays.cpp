//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


// using min heap implemented by STL priority_Queue and in O(N*K log K) time and O(k) space

class node{
    public:
    int data;
    int row;
    int col;
    
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class comp{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:

    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue <node*,vector<node*>,comp> minHeap;
        // minHeap of K nodes
        for (int i=0; i<K; i++){
            node* temp = new node(arr[i][0], i, 0);
            minHeap.push(temp);// log K
        }// KlogK
        
        vector <int> sorted;
        while (!minHeap.empty()){
            
            node* curr = minHeap.top();
            sorted.push_back(curr->data);
            
            minHeap.pop();
            
            int row = curr->row;
            int col = curr->col;
            
            if (col+1 < arr[row].size()){
                minHeap.push(new node(arr[row][col+1], row, col+1));
            }
            
        }
        return sorted;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends