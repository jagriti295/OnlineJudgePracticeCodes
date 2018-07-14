class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)    return 0;
        int nextMax,prevMax;
        vector<int> left(n),right(n);
        left[0]=-1;
        nextMax=0;
        right[n-1]=n;
        prevMax=n-1;
        int sum=0;
        for(int i=1,j=n-2;i<n;i++,j--){
            left[i]=(height[nextMax]>height[i]?nextMax:-1);
            nextMax=(height[i]>height[nextMax]?i:nextMax);
            right[j]=(height[prevMax]>height[j]?prevMax:n);
            prevMax=(height[j]>height[prevMax]?j:prevMax);
        }
        for(int i=0;i<n;i++){
            if(left[i]==-1 || right[i]==n)  continue;
            sum+=min(height[right[i]],height[left[i]])-height[i];
        }
        return sum;
    }
};
