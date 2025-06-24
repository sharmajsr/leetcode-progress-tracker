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

// carry = 1
//  9 ,0 , 0 , 1 ,
//  1, 9,  9,  9
//  0  0  0  1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0 ;
        ListNode* dummyNode = new ListNode(0);
        ListNode* returnNode = dummyNode;
        while(l1 != NULL and l2 != NULL){
            int sum = l1->val + l2->val + carry ;
            l1 = l1->next;
            l2 = l2->next;
            if(sum > 9 ){
                sum = sum%10 ;
                carry = 1 ;
            }else{
                carry = 0; 
            }
            ListNode* newNode = new ListNode(sum);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
        }
        while(l1!=NULL){
            int sum = l1->val + carry;
            l1 = l1->next;
            if(sum > 9 ){
                sum = sum%10;
                carry =1;
            }else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
        }

        while(l2!=NULL){
            int sum = l2->val +carry;
            l2 = l2->next;
            if(sum > 9 ){
                sum = sum%10;
                carry =1;
            }else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            dummyNode->next = newNode;
           dummyNode = dummyNode->next;
        }
        if(carry == 1){
            ListNode* newNode = new ListNode(carry);
            dummyNode->next = newNode;
            dummyNode= dummyNode->next;
        }

        return returnNode->next;
    }
};
//  carry = 1
//  [9,9,9,9,9,9,9]
//  [9,9,9,9]
//   8,9,9,9,0,0,0,1


// carry = 1
//  9 ,0 , 0 , 1 ,
//  1, 9,  9,  9
//  0  0   0   1  1

// 9991 + 1009
// 11000