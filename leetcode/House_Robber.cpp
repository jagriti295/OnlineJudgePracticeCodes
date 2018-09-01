class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        int a = nums[0],b = max(nums[0],nums[1]),c;  //a - cur, b - prev
        int ans = 0;
        for(int i=2;i<n;i++){
            c = max(a + nums[i],b);
            //cout<<a<<" "<<b<<" "<<c<<endl;
            a = b;
            b = c;
        }
        return c;
    }
};
