// TC:O(n^2) SC:O(ans)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            string currStr = "";
            for (int j = i; j < n; j++) {
                
                currStr += s[j];
                if (j - i + 1 == 10) {
                    freq[currStr]++;
                    if (freq[currStr] == 2 )
                        ans.emplace_back(currStr);
                } else
                    continue;
            }
        }
        return ans;
    }
};
// TC:O(n) SC:O(n) 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        unordered_map<string, int> freq;
        int l = 0, r = 0;
        while (r < n) {
            if (r - l + 1 < 10)
                r++;
            if (r - l + 1 == 10) {
                string str = s.substr(l, r - l + 1);
                freq[str]++;
                if (freq[str] == 2)
                    ans.emplace_back(str);
                l++;
                r++;
            }
        }
        return ans;
    }
};
