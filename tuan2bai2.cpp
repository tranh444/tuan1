#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const int n = s.length();
        const int maxLength = getMaxLength(wordDict);
        const unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
        vector<vector<string>> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > maxLength)
                    break;
                string word = s.substr(j, i - j);
                if (dp[j].size() > 0 && wordSet.count(word)) {
                    if (j == 0)
                        dp[i].push_back(word);
                    else {
                        for (const string& prev : dp[j]) {
                            dp[i].push_back(prev + " " + word);
                        }
                    }
                }
            }
        }

        return dp[n];
    }

private:
    int getMaxLength(const vector<string>& wordDict) {
        return max_element(begin(wordDict), end(wordDict),
                           [](const auto& a, const auto& b) {
                               return a.length() < b.length();
                           })
            ->length();
    }
};

int main() {
    Solution solution;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> result = solution.wordBreak(s, wordDict);
    cout << "[" << endl;
    for (const string& str : result) {
        cout << "  \"" << str << "\"," << endl;
    }
    cout << "]" << endl;

    return 0;
}

