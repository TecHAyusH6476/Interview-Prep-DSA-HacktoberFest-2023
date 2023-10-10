package Stacks_And_Queues;

import java.util.Stack;

public class NextGreaterElement
{
    
    public static int[] nextLargerElement(int[] arr, int n)
    { 
        
        Stack<Integer> s = new Stack<>();
        int ans[] = new int[n];
        
        for(int i = n-1;i>-1;i--){
            
            while(!s.isEmpty() && s.peek()<=arr[i]) s.pop();
            
            if(s.isEmpty()) ans[i] = -1;
            else ans[i] = s.peek();
            
            s.push(arr[i]);
        }
        
        return ans;
    } 
}