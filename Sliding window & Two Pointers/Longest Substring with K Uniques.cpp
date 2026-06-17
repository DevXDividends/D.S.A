// brute force TC:O(n^2) SC:O(n)
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        int n = s.length();
        if(k>n)return -1;
        int maxLen =-1;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()==k){
                    maxLen = max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
};
// better TC:O(2n) SC:O(n)
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        int n = s.length();
        if(k>n)return -1;
        int maxLen =-1;
        int l = 0,r = 0;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() == k)
                maxLen = max(maxLen,r - l +1);
            r++;
        }
        return maxLen;
    }
};
// optimised TC:O(n) SC:O(n) 
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        int n = s.length();
        if(k>n)return -1;
        int maxLen =-1;
        int l = 0,r = 0;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() == k)
                maxLen = max(maxLen,r - l +1);
            r++;
        }
        return maxLen;
    }
};
