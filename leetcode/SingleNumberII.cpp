class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),i,j;
        int x=1,sum=0,res=0;
        for(i=0;i<32;i++){
            sum = 0;
            x = 1<<i;
            for(j=0;j<n;j++){
                if(nums[j] & x) sum++;
            }
            if(sum%3)  res = res | x; 
        }
        return res;
    }
};
