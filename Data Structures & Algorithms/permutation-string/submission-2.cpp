class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int k=s1.length();
        if(k>s2.length()){
            return false;
        }
        for(char ch:s1){
            freq1[ch-'a']++;
        }
        for(int i=0;i<k;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2){
            return true;
        }
        int left=0;
        for(int right=k;right<s2.length();right++){
            freq2[s2[right]-'a']++;
            freq2[s2[left]-'a']--;
            left++;
            if(freq1==freq2){
                return true;
            }
        }
        return false;
    }
};
