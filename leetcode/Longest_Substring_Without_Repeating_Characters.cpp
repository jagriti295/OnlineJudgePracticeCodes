class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(),mlen=0,len=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                mlen = max(mlen,len);
                int k = i-len;
                while(k<m[s[i]]){
                    m.erase(s[k++]);
                }
                m[s[i]]=i;
                len = m.size();
            }
            else{
                m[s[i]]=i;
                len++;
            }
        }
        mlen = max(mlen,len);
        return mlen;
    }
};
