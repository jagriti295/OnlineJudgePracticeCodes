/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    ListNode* head1=NULL;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* node = head;
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        head1=head;
        TreeNode* root = sortedListToBSTUtil(0,count-1);
        return root;
    }
    
    TreeNode* sortedListToBSTUtil(int start,int end){
        if(start>end)   return NULL;
        TreeNode* treenode = new TreeNode(1e9);
        int mid=(start+end)/2;
        treenode->left = sortedListToBSTUtil(start,mid-1);
        treenode->val = head1->val;
        //cout<<head1->val<<" ";
        head1 = head1->next;
        treenode->right = sortedListToBSTUtil(mid+1,end);
        return treenode;
    }
};
