#include <string_view>

// Turn off stream synchronization for ultra-fast judging I/O
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(std::string_view s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            // Skip non-alphanumeric from right
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }
            
            // Normalize and compare
            if (normalize(s[left]) != normalize(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }

private:
    // streamlined logical evaluation
    inline bool isAlphanumeric(const char c) const {
        return (c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9');
    }
    
    // Uses bitwise operations to flatten uppercase down to lowercase 
    inline char normalize(const char c) const {
        if (c >= 'A' && c <= 'Z') {
            return c | 32; // Flips the 5th bit to make it lowercase instantly
        }
        return c;
    }
};