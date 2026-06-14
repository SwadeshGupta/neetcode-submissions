#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }
            
            // Compare characters by converting uppercase to lowercase on the fly
            if (toLowerCase(s[left]) != toLowerCase(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }

private:
    // Faster ASCII boundaries check
    inline bool isAlphanumeric(char c) const {
        return (c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9');
    }
    
    // Quick custom lowercase conversion
    inline char toLowerCase(char c) const {
        if (c >= 'A' && c <= 'Z') {
            return c + 32; 
        }
        return c;
    }
};