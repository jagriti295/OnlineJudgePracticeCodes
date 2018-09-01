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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL,*node=NULL,*tail=NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            node = new ListNode((l1->val+l2->val+carry)%10);
            if(head == NULL)    tail = head = node;
            else{
                tail->next = node;
                tail = node;
            }
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            node = new ListNode((l1->val+carry)%10);
            if(head == NULL)    tail = head = node;
            else{
                tail->next = node;
                tail = node;
            }
            carry = (l1->val+carry)/10;
            l1 = l1->next;
        }
        while(l2){
            node = new ListNode((l2->val+carry)%10);
            if(head == NULL)    tail = head = node;
            else{
                tail->next = node;
                tail = node;
            }
            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }
        if(carry){
            node = new ListNode(carry);
            tail->next = node;
            tail = node;
        }
        return head;
    }
};
