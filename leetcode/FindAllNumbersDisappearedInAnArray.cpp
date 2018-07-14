class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n,0), res;
        for(int i=0;i<n;i++){
            int val = abs(nums[i])-1;
            //cout<<"****"<<val<<" "<<nums[val]<<endl;
            if(nums[val]>0){
                //tmp[val] = -nums[val];
                nums[val] = -nums[val];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)   res.push_back(i+1);
            //cout<<nums[i]<<endl;
        }
        return res;
    }
};
