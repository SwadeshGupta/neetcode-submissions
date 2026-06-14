#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Map to store: { Sorted_String -> List_of_Original_Anagrams }
        std::unordered_map<std::string, std::vector<std::string>> anagram_groups;
        
        for (const std::string& s : strs) {
            std::string key = s; 
            std::sort(key.begin(), key.end()); // Sorting makes anagrams identical
            
            // Group the original string under its sorted key
            anagram_groups[key].push_back(s);
        }
        
        // Extract groups from the map into our final result format
        std::vector<std::vector<std::string>> result;
        result.reserve(anagram_groups.size()); // Optimization: reserve memory upfront
        
        for (auto& pair : anagram_groups) {
            result.push_back(std::move(pair.second)); // std::move avoids copying data
        }
        
        return result;
    }
};