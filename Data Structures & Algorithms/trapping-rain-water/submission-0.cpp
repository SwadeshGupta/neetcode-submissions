class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax;
        vector<int>rightmax;
        int ans=0;
        for(int i=0;i<n;i++){
            int leftmaxi=*max_element(height.begin(),height.begin()+i+1);
            int rightmaxi=*max_element(height.begin()+i,height.end());
            leftmax.push_back(leftmaxi);
            rightmax.push_back(rightmaxi);

        }
        
        for(int i=0;i<n;i++){
            ans+=min(rightmax[i],leftmax[i])-height[i];
        }
        return ans;

    }
};