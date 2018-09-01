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
        int c1 = 0, c2 = 0;
        ListNode* h1 = l1,*h2 = l2;
        while(l1){
            c1++;
            l1 = l1->next;
        }
        while(l2){
            c2++;
            l2 = l2->next;
        }
        if(c1<c2){
            //swap(l1,l2);
            swap(c1,c2);
            swap(h1,h2);
        }
        l1 = h1, l2 = h2;
        for(int i=0;i<c1-c2;i++){
            l1 = l1->next;
        }
        ListNode* head = NULL;
        int carry = addTwoNumbersPartI(l1,l2,head);
        addTwoNumbersPartII(h1,c1-c2,carry,head,0);
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }
    
    int addTwoNumbersPartI(ListNode* l1, ListNode* l2, ListNode*& head){
        if(l1 == NULL)  return 0;
        int carry = addTwoNumbersPartI(l1->next,l2->next,head);
        ListNode* node = new ListNode((l1->val+l2->val+carry)%10);
        node->next = head;
        head = node;
        return (l1->val+l2->val+carry)/10;
    }
    
    void addTwoNumbersPartII(ListNode* h1,int len,int& carry,ListNode*& head,int i){
        if(i == len)    return;
        addTwoNumbersPartII(h1->next,len,carry,head,i+1);
        ListNode* node = new ListNode((h1->val+carry)%10);
        node->next = head;
        head = node;
        carry = (h1->val+carry)/10;
    }
};
