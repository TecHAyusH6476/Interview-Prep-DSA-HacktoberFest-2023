package Stacks_And_Queues;

import java.util.Stack;

// this problem is a second version of NGE-I 

public class NextGreaterElement_II {

    public int[] nextGreaterElements(int[] arr) {
        
      int n = arr.length; Stack<Integer> s= new Stack<>(); int ans[] = new int[n];
	    
	    for(int i = 2*n-1;i>-1;i--){
	        
	        while(!s.isEmpty() && s.peek()<= arr[i%n]) s.pop();
	        
	        if(s.isEmpty()) ans[i%n] = -1;
	        else ans[i%n] = s.peek();
	        
	        s.push(arr[i%n]);
	    }
	    
	    return ans;
    }
    
}
