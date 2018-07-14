class Solution {
public:
    int nextGreaterElement(int n) {
        int arr[15],i,j,rem,ind=0;
        //long long nt = n;
        while(n>0){
            rem = n%10;
            n = n/10;
            arr[ind++] = rem;
        }
        for(i=1;i<ind;i++){
            for(j=0;j<i;j++){
                if(arr[i]<arr[j])   break;
            }
            if(j<i) break;
            
        }
        if(i==ind)  return -1;
        int mn = 11,idx;
        //sort(arr,arr+i,greater<int>());
        for(j=0;j<i;j++){
            if(arr[j]>arr[i] && mn>arr[j]){
                mn=min(mn,arr[j]);
                idx=j;
            }   
        }
        swap(arr[i],arr[idx]);
        sort(arr,arr+i,greater<int>());
        n=0;
        for(i=ind-1;i>0;i--){
            n = n*10 + arr[i];
        }
        int lim = pow(2,31) + 1;
        rem = lim%10;
        int div = lim/10;
        //cout<<n<<" "<<lim<<" "<<div<<endl;
        if(div<n || (div==n && rem<arr[0]) )   return -1;
        //if(n>lim)   return -1;
        n = n*10+arr[0];
        return n;
    }
};
