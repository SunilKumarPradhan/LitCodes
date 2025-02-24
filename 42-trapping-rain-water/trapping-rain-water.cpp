class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    vector<int> getLeftMax(vector<int>& height, int n){
            vector<int> LeftMax(n);

            LeftMax[0]=height[0];

            for(int i=1;i<n;i++){
                LeftMax[i]=max(LeftMax[i-1],height[i]);
            }
            return LeftMax;
        }

        vector<int> getRightMax(vector<int>& height, int n){
            vector<int> RightMax(n);

            RightMax[n-1]=height[n-1];

            for(int i=n-2;i>=0;i--){
                RightMax[i]=max(RightMax[i+1],height[i]);
            }
            return RightMax;
        }

    int trap(vector<int>& height) {
        int n=height.size();
        if (n < 3) return 0; // At least 3 bars are needed to trap water

        int sum=0;
        vector<int> LeftMax=getLeftMax(height,n);
        vector<int> RightMax=getRightMax(height,n);
        
        for(int i=0;i<n;i++){
            sum+=min(LeftMax[i],RightMax[i])-height[i];
        }
        return sum;
        
    }
};
