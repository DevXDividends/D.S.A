// brute force TC:O(n^2) SC:O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxSub = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            int maxfreq = 0;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                maxfreq = max(maxfreq, mpp[s[j]]);
                int charReplaced = (j - i + 1) - maxfreq;
                if (charReplaced <= k)
                    maxSub = max(maxSub, j - i + 1);
                else
                    break;
            }
        }
        return maxSub;
    }
};
// optimal TC:O(n) SC:O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxSub = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        while (r < n) {
            mpp[s[r]]++;
            maxLen = max(maxLen, mpp[s[r]]);
            int charToReplace = (r - l + 1) - maxLen;
            if (charToReplace > k) {
                mpp[s[l]]--;
                l++;
            }
            if (charToReplace <= k)
                maxSub = max(maxSub, r - l + 1);
            r++;
        }
        return maxSub;
    }
};
