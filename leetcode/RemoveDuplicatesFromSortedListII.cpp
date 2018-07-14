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
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    tmp=head->next;
                    head->next = head->next->next;
                    delete(tmp);
                }
                //if(!head->next) break;
                if(!prev){
                    tmp = head;
                    head = head->next;
                    root=head;
                    delete(tmp);
                }
                else{
                    tmp = head;
                    head = head->next;
                    prev->next = head;
                    delete(tmp);
                }
                //head = prev->next;
            }
            else{
                prev=head;
                head = head->next;
            }
            
        }
        return root;
    }
};
