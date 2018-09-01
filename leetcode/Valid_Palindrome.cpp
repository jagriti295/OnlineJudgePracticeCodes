class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<=j){
            while(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57))   i++;
            while(!(s[j]>=65 && s[j]<=90) && !(s[j]>=97 && s[j]<=122) && !(s[j]>=48 && s[j]<=57))   j--;
            if(i<=j && tolower(s[i])!=tolower(s[j]))    return false;
            if(i<=j && tolower(s[i])==tolower(s[j]))  i++,j--;
        }
        return true;
    }
};
