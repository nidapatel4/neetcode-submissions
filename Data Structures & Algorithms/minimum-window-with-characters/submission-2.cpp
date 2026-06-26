class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window;
        unordered_map<char,int> need;
        for(char ch:t){
            need[ch]++;
        }
        int formed=0;
        int required=need.size();
        int left=0;
        int start=0;
        int minLen=INT_MAX;

        for(int right=0;right<s.length();right++){
            window[s[right]]++;

            if(window[s[right]]==need[s[right]]){
                formed++;
            }
            while(formed==required){
                if(right-left+1<minLen)
                {
                    minLen=right-left+1;
                    start=left;
                }
                window[s[left]]--;
                if(window[s[left]]<need[s[left]]){
                    formed--;
                }
                left++;
            }
            
        }
        if(minLen==INT_MAX)
            return "";
            return s.substr(start,minLen);
    }
};
