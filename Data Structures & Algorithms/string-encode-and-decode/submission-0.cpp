#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Encode a list of strings into one string
    string encode(vector<string>& strs) {

        string encoded = "";

        for (string str : strs) {

            encoded += to_string(str.length());

            encoded += '#';

            encoded += str;
        }

        return encoded;
    }

    // Decode the encoded string back into a list of strings
    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while (i < s.length()) {

            int j = i;

            // Find the '#'
            while (s[j] != '#') {
                j++;
            }

            // Extract length
            int len = stoi(s.substr(i, j - i));

            // Extract actual string
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // Move to next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};