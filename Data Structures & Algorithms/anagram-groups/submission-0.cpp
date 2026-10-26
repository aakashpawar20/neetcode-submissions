#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            string key = s;

            sort(key.begin(), key.end());

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};