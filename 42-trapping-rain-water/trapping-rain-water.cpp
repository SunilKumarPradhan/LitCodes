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

/*
Iss function ka naam hai trap jo ek array ke andar trapped rainwater ka total volume calculate karta hai.

- Function ka logic:
  1. Har index ke left aur right ka maximum height dhoondhna padega, kyunki trapped water min(leftMax, rightMax) - height[i] se calculate hota hai.
  2. `getLeftMax()` function se har index ka left se maximum height milega.
  3. `getRightMax()` function se har index ka right se maximum height milega.
  4. Har index pe trapped water calculate karke total sum mein add karenge.

Process:
- Pehle, input array ke size ko check karenge. Agar size 0 ya 1 hai to return 0.
- `getLeftMax()` call karenge jo left se maximum values ka ek array dega.
- `getRightMax()` call karenge jo right se maximum values ka ek array dega.
- Ek loop chalega jo min(leftMax[i], rightMax[i]) - height[i] calculate karega.
- Ye values ko sum mein add karke final result return karenge.

Example:
- Input: [0,1,0,2,1,0,1,3,2,1,2,1]

Step 1: getLeftMax():
[0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]

Step 2: getRightMax():
[3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]

Step 3: Trapped Water Calculation:
min(leftMax[i], rightMax[i]) - height[i]
[0,0,1,0,1,2,1,0,0,1,0,0]

Three Iterations:
- Iteration 1: i = 1, Water trapped = 0
- Iteration 2: i = 2, Water trapped = 1
- Iteration 3: i = 5, Water trapped = 2

Dry Run:
1. Input Array: [0,1,0,2,1,0,1,3,2,1,2,1]
2. LeftMax & RightMax calculate hoga
3. Har index pe trapped water add hoga

Output:
Total trapped water = 6
*/
