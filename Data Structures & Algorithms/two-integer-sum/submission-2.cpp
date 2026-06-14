class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& arr, int target) {
        // Map to store: {number_value, its_index}
        std::unordered_map<int, int> num_map; 
        
        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            
            // Check if the complement already exists in our map
            if (num_map.find(complement) != num_map.end()) {
                // If found, return the index of the complement and the current index
                return {num_map[complement], i};
            }
            
            // If not found, insert the current number and its index into the map
            num_map[arr[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though the problem guarantees one)
        return {};
    }
};