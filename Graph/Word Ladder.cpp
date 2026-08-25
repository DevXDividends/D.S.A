// TC: O(N² × L) SC: O(N²)
class Solution {
public:
    int diff(string& node1, string& node2) {
        int diff = 0;
        for (int i = 0; i < node1.size(); i++) {
            if (node1[i] != node2[i])
                diff++;
        }
        return diff;
    }
    void prepareGraph(vector<string>& wordList,
                      unordered_map<string, vector<string>>& adj) {
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                if (j != i && diff(wordList[i], wordList[j]) == 1)
                    adj[wordList[i]].push_back(wordList[j]);
            }
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        bool exists = false;
        for (auto n : wordList) {
            if (n == endWord) {
                exists = true;
                break;
            }
        }
        if (!exists)
            return 0;

        unordered_map<string, vector<string>> adj;
        wordList.emplace_back(beginWord);
        prepareGraph(wordList, adj);

        int dist = 1;

        queue<string> q;
        unordered_set<string> vis;

        q.push(beginWord);
        vis.insert(beginWord);

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string node = q.front();
                q.pop();
                if (node == endWord)
                    return dist;
                for (auto n : adj[node]) {
                    if (!vis.count(n)) {
                        q.push(n);
                        vis.insert(n);
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};
