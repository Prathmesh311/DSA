class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; // End word is not in the word list, can't transform.
        }

        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                string currentWord = q.front();
                q.pop();

                if (currentWord == endWord) {
                    return ladderLength; // Transformation found.
                }

                // Try all possible one-letter transformations.
                for (int j = 0; j < currentWord.size(); j++) {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;

                        currentWord[j] = c;

                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Mark visited word.
                        }

                        currentWord[j] = originalChar; // Reset for the next transformation.
                    }
                }
            }
            ladderLength++;
        }

        return 0; // No transformation sequence found.
    }

};
