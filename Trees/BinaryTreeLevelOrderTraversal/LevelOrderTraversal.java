package BinaryTreeLevelOrderTraversal;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List; 

public class LevelOrderTraversal {
        public List<List<Integer>> levelOrder(TreeNode root) {
            if(root == null) return new ArrayList<>();
            LinkedList<TreeNode> que = new LinkedList<>();
            que.addLast(root);
            List<List<Integer>> ans = new ArrayList<>();
            while(que.size() != 0) {
                int size = que.size();
                List<Integer> smallAns = new ArrayList<>();
                
                while(size-- > 0) {
                    TreeNode rNode = que.removeFirst();
                    smallAns.add(rNode.val);
                    
                    if(rNode.left != null) que.addLast(rNode.left);
                    if(rNode.right != null) que.addLast(rNode.right);
                }
                ans.add(smallAns);
            }
            return ans;
        }
}
