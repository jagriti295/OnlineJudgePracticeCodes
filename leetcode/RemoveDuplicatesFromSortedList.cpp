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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL,*root=head,*tmp=NULL;
        for(;head;prev=head,head = head->next){
            if(!prev || !head)  continue;
            while(prev->val == head->val){
                tmp = head;
                head = head->next;
                delete(tmp);
                prev->next = head;
                if(!head)   break;
            }
            if(!head)   break;
        }
        return root;
    }
};
