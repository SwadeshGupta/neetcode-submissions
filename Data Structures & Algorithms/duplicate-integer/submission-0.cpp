class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        unordered_set<int> s;

        for(int x : arr) {
            if(s.count(x))
                return true;
            s.insert(x);
        }

        return false;
    }
};