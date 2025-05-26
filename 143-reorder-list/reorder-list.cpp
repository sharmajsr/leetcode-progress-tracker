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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        while(head!=NULL){
            next = head->next;
            head->next =prev;
            prev = head;
            head= next;
        }
        return prev;
    }
    void printList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;

        }cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next)  return ;
        ListNode* dummyNode = new ListNode();
        dummyNode->next =head;
        ListNode* slow =head;
        ListNode* fast = head;
        ListNode* prev;
        while(slow and fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* midNode ;
        if(!fast){
            midNode = reverseList(prev);
            // printList(midNode);
            prev->next =NULL;
        }else{
            midNode = reverseList(prev->next->next);
            // printList(midNode);
            prev->next->next = NULL;
        }
        while(head && midNode){
            ListNode* temp = midNode->next;
            midNode->next = head->next;
            head->next = midNode;
            head=head->next->next;
            midNode = temp;
        }
        // return dummyNode->next;

    }
};