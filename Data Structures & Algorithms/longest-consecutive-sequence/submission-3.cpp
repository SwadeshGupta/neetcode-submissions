class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=count;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                continue;
            }
            if(nums[i-1]==(nums[i]-1)){
                ++count;
                ans=max(count,ans);
            }else{
                count=1;
                continue;
            }
        }
        return ans;
    }
};
