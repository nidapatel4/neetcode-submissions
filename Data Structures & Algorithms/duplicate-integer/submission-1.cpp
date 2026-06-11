#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for (int num : nums) {

            // Check if number already exists
            if (seen.find(num) != seen.end()) {
                return true;
            }

            // Store current number
            seen.insert(num);
        }

        return false;
    }
};