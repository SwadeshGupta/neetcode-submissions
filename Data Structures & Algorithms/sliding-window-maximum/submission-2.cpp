class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans;
        int i=0;
        while(i<=n-k){
            ans.push_back(*max_element(nums.begin()+i,nums.begin()+k+i));
            i++;
        }
        return ans;
    }
};