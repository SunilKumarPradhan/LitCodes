class Solution {
public:
Solution() {  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    // if array is sorted
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int i=nums[0];
    //     int j=nums[nums.size()-1];

    //     if((i+j)=target){
    //         return {i,j}
    //     }
    //     j--;
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i=0; i<nums.size();i++){
            int diff = target - nums[i];

            if(mp.count(diff)){
                return {mp[diff],i};
            }

            mp[nums[i]]=i; // nums ke ith index mein jo number hai , usse rakhenge and usske index ko rakhenge
        }

        return {}; // kuch nahi toh ye return karna hoga
    }
};

/*
Iss function ka naam hai `twoSum` aur yeh ek array ke andar do numbers dhundh kar unke indices return karta hai jo `target` ka sum banate hain.

- Function ka logic:
  1. Ek unordered_map `numMap` use karte hain jo pehle se dekhe gaye numbers aur unke indices store karega.
  2. Loop chalayenge har element ke liye aur dekhenge ki `target - nums[i]` map mein hai ya nahi.
  3. Agar `complement` mil gaya toh return karenge dono indices.
  4. Agar nahi mila toh `nums[i]` ko `numMap` mein daalenge future reference ke liye.

Process:
- Pehle, har element ke liye check karenge ki target se subtract karne ke baad jo value bachi hai, woh pehle aayi thi ya nahi.
- Agar aayi thi toh dono indices return karenge.
- Nahi toh map mein current number daal denge.

Example:
- Agar `nums = {2, 7, 11, 15}` aur `target = 18` hai:

    Index    ->  0   1   2   3
    Values   ->  2   7   11  15

    Target = 18

then

    Step 1: `numMap` empty hai.
    Step 2: `2` ko `numMap` mein daal diya. (`numMap = {2: 0}`)
    Step 3: `7` ko `numMap` mein daal diya. (`numMap = {2: 0, 7: 1}`)
    Step 4: `11` ka complement `18 - 11 = 7` hai jo pehle se `numMap` mein hai.
    Step 5: `7` ka index `1` hai, aur current index `2` hai.
    Step 6: Return `{1, 2}`.

Three Iterations:

1. `i = 0, nums[i] = 2`
    - `complement = 18 - 2 = 16`
    - `16` `numMap` mein nahi hai → `numMap = {2: 0}`

2. `i = 1, nums[i] = 7`
    - `complement = 18 - 7 = 11`
    - `11` `numMap` mein nahi hai → `numMap = {2: 0, 7: 1}`

3. `i = 2, nums[i] = 11`
    - `complement = 18 - 11 = 7`
    - `7` `numMap` mein hai! (`numMap[7] = 1`)
    - `return {1, 2}`

Dry Run:

| Step | i | nums[i] | complement | numMap (Before)   | Found in Map? | numMap (After) | Output |
|------|---|--------|------------|------------------|---------------|---------------|--------|
| 1    | 0 | 2      | 16         | {}               | ❌             | {2: 0}        | -      |
| 2    | 1 | 7      | 11         | {2: 0}           | ❌             | {2: 0, 7: 1}  | -      |
| 3    | 2 | 11     | 7          | {2: 0, 7: 1}     | ✅             | -             | {1, 2} |

Output:
1,2
*/

// it has many types of variations like : 3 sum ,4 sum , k sum etc.