#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the separator '#'
            while (s[j] != '#') {
                j++;
            }

            // Read the length of the string
            int len = stoi(s.substr(i, j - i));

            // Extract exactly 'len' characters
            string str = s.substr(j + 1, len);
            result.push_back(str);

            // Move to the beginning of the next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};