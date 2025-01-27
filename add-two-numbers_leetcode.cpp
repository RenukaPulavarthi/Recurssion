//https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* head=NULL;
    ListNode* temp=NULL;
    int carry=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL && carry==0){
            return head;
        }
        if(l1==NULL && l2==NULL){
            temp->next=new ListNode(carry);
            return head;
        }
        if(l1==NULL){
            int z=(l2->val+carry);
            carry=z/10;
            temp->next=new ListNode(z%10);
            temp=temp->next;
            return addTwoNumbers(l1,l2->next);
        }
        if(l2==NULL){
            int z=(l1->val+carry);
            carry=z/10;
            temp->next=new ListNode(z%10);
            temp=temp->next;
            return addTwoNumbers(l1->next,l2);
        }
        if(head==NULL){
            head=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            temp=head;
        }
        else{
           
            temp->next=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            temp=temp->next;
        }
        return addTwoNumbers(l1->next,l2->next);
    }
};
