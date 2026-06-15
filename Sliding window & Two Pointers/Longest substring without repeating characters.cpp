class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        int maxSize = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> stt;
        while (r < n) {
            if (stt.find(s[r]) == stt.end()){
                stt.insert(s[r]);
                maxSize = max(maxSize, r-l+1);
                r++;
                }
      else {
                
              
                stt.erase(s[l]);
               l++;
            }
        }
        
        return maxSize;
    }
};