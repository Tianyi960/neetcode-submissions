class Solution {
public:
    bool oneDiff(string a, string b) {
    int diff = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;

            if (diff > 1) {
                return false;
            }
        }
    }

    return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        vector<bool> visited(wordList.size(), false);

        q.push({beginWord, 1});

        while (!q.empty()) {

            string cur = q.front().first;
            int count = q.front().second;
            q.pop();

            if (cur == endWord) {
                return count;
            }

            for (int i = 0; i < wordList.size(); i++) {

                if (!visited[i] && oneDiff(cur, wordList[i])) {

                    visited[i] = true;

                    q.push({wordList[i], count + 1});
                }
            }
        }

        return 0;
    }
};
