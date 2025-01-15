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
    ListNode* getReverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev= head;
            head =next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // 1. find middle of ll
        // 2. reverse the second part
        // 3. merge

        ListNode* temp=head;
        ListNode* prev;
        ListNode* head1=head;
        while(temp and temp->next){
            prev = head1;
            head1 = head1->next;
            temp= temp->next->next;
        }
        if(temp){
            prev =head1;
            head1 = head1->next;
        }
        prev->next = NULL;
        // printLL(head);
        // printLL(head1);
        ListNode* reversedList = getReverseList(head1);
        // printLL(reversedList);
        while(head and reversedList){
            ListNode* next1 = head->next;
            ListNode* next2 = reversedList->next;
            // cout<<head->val<<" "<<reversedList->val<<" ";
            // if(next1)   cout<<next1->val<<" ";
            // else if (next2)   cout<<next2->val<<" ";
            // cout<<endl;
            reversedList->next = next1;
            head->next = reversedList;
            head= next1;
            reversedList = next2;
        }
        // if(reversedList !=NULL ){
        //     cout<<"reverse : "<<reversedList->val<<endl;
        //     head->next = reversedList;
        //     reversedList->next= NULL;
        // }
        
    }
};