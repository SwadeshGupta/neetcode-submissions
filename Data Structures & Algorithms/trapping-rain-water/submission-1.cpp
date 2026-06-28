// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int>leftmax;
//         vector<int>rightmax;
//         int ans=0;
//         for(int i=0;i<n;i++){
//             int leftmaxi=*max_element(height.begin(),height.begin()+i+1);
//             int rightmaxi=*max_element(height.begin()+i,height.end());
//             leftmax.push_back(leftmaxi);
//             rightmax.push_back(rightmaxi);

//         }
        
//         for(int i=0;i<n;i++){
//             ans+=min(rightmax[i],leftmax[i])-height[i];
//         }
//         return ans;

//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;

        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};