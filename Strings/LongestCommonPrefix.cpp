string mymethod(vector<string> &strs){
         string ans="";
        int i=0;
        for(int i=0;i<strs[0].size();i++){
            int ch=strs[0][i];
            int j;
            for( j=1;j<strs.size();j++){
                if(i<strs[j].size() && strs[j][i]==ch){
                    continue;
                }
                else{
                    return ans;
                }
            }
           if(j==strs.size()){
               ans.push_back(ch);
           }
        }
        return ans;
}
    string longestCommonPrefix(vector<string>& strs) {
   return mymethod(strs);
    }
