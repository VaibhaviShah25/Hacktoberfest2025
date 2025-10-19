class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        
        // Try each starting position
        for(int i = 0; i < n; i++){
            unordered_map<char, int> freq;
            
            // Extend from position i
            for(int j = i; j < n; j++){
                freq[s[j]]++;  // Add current character
                
                // Check if all frequencies are equal
                int firstFreq = freq.begin()->second;
                bool balanced = true;
                
                for(auto& p : freq){
                    if(p.second != firstFreq){
                        balanced = false;
                        break;
                    }
                }
                
                if(balanced){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};
