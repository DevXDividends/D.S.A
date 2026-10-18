// TC:O(S + K) SC:O(1) 
class Solution {
	public:
	int search(string &pat, string &txt) {
		// code here
		if (txt.length()
			< pat.length())return - 1;
		vector<int> targetFreq(26, 0);
		vector<int> windowFreq(26, 0);
		
		int cnt = 0;
		
		int k = pat.length();
		
		for (int i = 0; i<k; i++) {
			targetFreq[pat[i]-'a']++;
			windowFreq[txt[i]-'a']++;
		}
		
		if (targetFreq == windowFreq)
			cnt++;
		
		for (int i = k; i<txt.length(); i++) {
			windowFreq[txt[i]-'a']++;
			windowFreq[txt[i - k]-'a']--;
			if (windowFreq == targetFreq)cnt++;
		}
		return cnt;
	}
};
