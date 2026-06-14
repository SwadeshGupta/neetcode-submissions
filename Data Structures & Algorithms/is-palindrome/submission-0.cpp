class Solution {
public:
    void makeAlphanumeric(std::string& s) {
        int writeIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                s[writeIndex] = c;
                writeIndex++;
            } 
            else if (c >= 'A' && c <= 'Z') {
                s[writeIndex] = c + 32;
                writeIndex++;
            }
        }
        s.resize(writeIndex);
    }

    bool isPalindrome(std::string s) {
        // 1. Clean the string first using your function
        makeAlphanumeric(s);
        
        // 2. Use a single loop with two pointers to check if it's a palindrome
        int left = 0;
        int right = s.length() - 1; // Corrected: valid indices stop at length - 1
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false; // Found a mismatch, not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // Checked everything, it matches perfectly!
    }
};