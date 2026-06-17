// brute force TC:O(n^3) SC:O(n) 
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (k > n)
            return 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                bool flag = true;
                for (auto it : mpp) {
                    if (it.second < k)
                        flag = false;
                }
                if (flag)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
