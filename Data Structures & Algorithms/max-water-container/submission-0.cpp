    class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int mini=h[0];
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mini=min(h[i],h[j]);
                maxi=max(maxi,mini*(j-i));
            }
        }
        return maxi;

    }
};
