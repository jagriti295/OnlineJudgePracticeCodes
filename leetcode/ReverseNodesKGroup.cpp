/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1)    return head;
        int cnt=0;
        ListNode *thead=NULL,*pthead=NULL,*root=head,*next=NULL;
        for(;head;head = next){
            cnt++;
            next = head->next;
            if(cnt%k==1){
                pthead = thead;
                thead = head;
            }
            if(!(cnt%k)){
                reverse(thead,1,k);
                if(cnt==k)  root = head;
                if(pthead)
                    pthead->next = head;
            }
        }
        if(cnt%k && pthead)    pthead->next = thead;
        return root;
    }
    void reverse(ListNode* node,int K,int k){
        if(K==k)    return;
        if(node->next){
            reverse(node->next,++K,k);
            node->next->next = node;
            node->next = NULL;
        }
    }
};
