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
        //using given linked lists space
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        int carry=0;
        while(tmp1!=NULL || tmp2!=NULL){
            tmp1->val += tmp2->val + carry;
            if(tmp1->val>9){
                tmp1->val%=10;
                tmp2->val%=10;
                carry=1;
            }
            else {
                carry=0;
            }
            if(tmp2->next==NULL && tmp1->next == NULL && carry==1){
                ListNode* no = new ListNode(0);
                tmp1->next = no;
            }
            if(tmp1->next==NULL && tmp2->next != NULL){
                ListNode* no = new ListNode(0);
                tmp1->next = no;
            }
            if(tmp2->next==NULL && tmp1->next != NULL){
                ListNode* no = new ListNode(0);
                tmp2->next = no;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        
        return l1;
    }
};