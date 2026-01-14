/ TC:O(N∗2 ^N) SC:O(n)
class Solution {
public: 
    void findAll(int ind,string &s,vector<string>& path,vector<vector<string>> &res){
        if(ind == s.size()){
            res.emplace_back(path);
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.emplace_back(s.substr(ind,i-ind+1));
                findAll(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        findAll(0,s,path,res);
        return res;
    }
};
