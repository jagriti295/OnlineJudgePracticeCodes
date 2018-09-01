#define mp make_pair
#define f first
#define s second
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)  return 0;
        if(!(n%2))  return 1 + integerReplacement(n/2);
        else{
            //if(n==INT_MAX)  return 1 + integerReplacement(n-1);
            return 2 + min(integerReplacement(n/2),integerReplacement(n/2+1));
        }
    }
};
