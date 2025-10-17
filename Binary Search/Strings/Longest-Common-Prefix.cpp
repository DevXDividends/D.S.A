class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            bool hasPrefix=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]==ch){
                    hasPrefix=true;
                }else{
                    hasPrefix=false;
                    break;
                }
            }
            if(hasPrefix){
            ans+=ch;
        }else{break;}
        }
        return ans;
    }
};
