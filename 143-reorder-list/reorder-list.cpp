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
    ListNode* reverse(ListNode *head){
        ListNode* prev = NULL;
        ListNode* next;
        while(head){
            next = head->next;
            head->next= prev;
            prev = head;
            head = next;
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
        ListNode *slow = head , *fast = head, *prevSlow = head;
        while(slow and fast and fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<"After slow and fast\n";
        ListNode* mid;
        if(!fast){
            mid = slow;
            prevSlow->next = NULL;
        }
        else{
            mid = slow->next;
            slow->next = NULL;
        }     
        ListNode* rever = reverse(mid);
        // printList(head);
        // printList(rever);
        // cout<<"After reversing\n";
        while(head and rever){
            ListNode* headNext = head->next;
            head->next = rever;
            rever=rever->next;
            head->next->next = headNext;
            head=headNext;
            
        }
        

    }
};