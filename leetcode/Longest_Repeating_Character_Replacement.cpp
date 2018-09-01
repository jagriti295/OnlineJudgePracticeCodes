class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char c = 'A';c<='Z';c++){
            ans = max(ans,maxInterval(s,k,c));
        }
        return ans;
    }
    int maxInterval(string s,int k,int c){
        int l,r,n = s.length(),count=0,res=0;
        for(l=0,r=0;r<n;r++){
            if(s[r]!=c){
                count++;
            }
            while(count>k){
                if(s[l++]!=c)   count--;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
