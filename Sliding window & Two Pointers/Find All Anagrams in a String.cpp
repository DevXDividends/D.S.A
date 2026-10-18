// TC:O(S + K) SC:O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length())
            return {};

        vector<int> targetFreq(26, 0);
        vector<int> windowFreq(26, 0);
        vector<int> ans;

        int k = p.length();
        for (int i = 0; i < k; i++) {
            targetFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }

        if (targetFreq == windowFreq)
            ans.emplace_back(0);

        for (int i = k; i < s.length(); i++) {
            windowFreq[s[i] - 'a']++; // expand window

            windowFreq[s[i - k] - 'a']--; // shrink from left

            if (windowFreq == targetFreq)
                ans.emplace_back(i - k + 1);
        }
        return ans;
    }
};
