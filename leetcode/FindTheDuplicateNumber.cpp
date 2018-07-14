class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(),i;
        for(i=0;i<n;i++){
            int val = abs(nums[i])-1;
            if(nums[val]>0){
                nums[val] = -nums[val];
            }
            else    return val+1;
        }
    }
};
