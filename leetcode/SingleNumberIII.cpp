class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0,i,a=0,b=0,bset;
        for(i=0;i<nums.size();i++)  xr=xr^nums[i];
        bset = xr & (-xr);
        for(i=0;i<nums.size();i++){
            if(bset & nums[i])  a = a^nums[i];
            else    b = b^nums[i];
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
