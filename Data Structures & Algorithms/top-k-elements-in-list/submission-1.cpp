#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Counted frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Stored numbers and frequencies in a vector
        vector<pair<int, int>> elements;

        for (auto& entry : freq) {
            elements.push_back({entry.first, entry.second});
        }

        // Sorted by frequency in descending order
        sort(elements.begin(), elements.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });

        // Return the k most frequent numbers
        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(elements[i].first);
        }

        return result;
    }
};