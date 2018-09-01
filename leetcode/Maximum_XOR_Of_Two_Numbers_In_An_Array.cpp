struct TrieNode{
    TrieNode* next[2];
    TrieNode(): next({NULL}) {}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = buildTrie(nums);
        /*printTrie(root);
        cout<<endl;*/
        int res = maxXor(root,nums);
        /*for(int i=31;i>=0;i--){
            cout<<(res>>i & 1);
        }
        cout<<endl;*/
        return res;
    }
    
    int maxXor(TrieNode* root, vector<int>& nums){
        TrieNode* node = root;
        int mx = 0, res = 0, p;
        for(int i=0;i<nums.size();i++){
            node = root;
            //cout<<"number: "<<nums[i]<<endl;
            for(int j=31;j>=0;j--){
                p = (nums[i]>>j) & 1;   //kid
                //cout<<" p "<<p<<endl;
                //cout<<" j "<<j<<" trying "<<(p^1)<<endl;
                if(node->next[p^1] == NULL){
                    res = res<<1;
                    node = node->next[p];
                    //cout<<" Added 0 "<<endl;
                }
                else{
                    res = res<<1 | 1;
                    node = node->next[p^1];
                    //cout<<" Added 1 "<<endl;
                }
            }
            //cout<<"res: "<<res<<endl;
            mx = max(mx,res);
        }
        return mx;
    }
    
    void printTrie(TrieNode* root){
        if(root == NULL)    return;
        if(root->next[0] != NULL)   cout<<"0 ";
        if(root->next[1] != NULL)   cout<<"1 ";
        printTrie(root->next[0]);
        printTrie(root->next[1]);
    }
    
    TrieNode* buildTrie(vector<int>& nums) {
        TrieNode* node=NULL;
        TrieNode* root = new TrieNode();
        for(int i=0;i<nums.size();i++){
            node = root;
            for(int j=31;j>=0;j--){
                if(node->next[nums[i]>>j & 1] == NULL){
                    node->next[nums[i]>>j & 1] = new TrieNode();
                }
                node = node->next[nums[i]>>j & 1];
            }
        }
        return root;
    }
};
