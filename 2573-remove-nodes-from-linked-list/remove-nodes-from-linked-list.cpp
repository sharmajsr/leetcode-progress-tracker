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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev= NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        cout<<"Prev : "<<prev->val<<endl;
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* reversedLL = reverseLL(head);
        ListNode* t1 = reversedLL;
        ListNode *dummyNode = new ListNode();
        dummyNode->next = reversedLL;
        // while(t1!=NULL){
        //     cout<<t1->val<<" ";
        //     t1 = t1->next;
        // }

        while(reversedLL and reversedLL->next){
            if(reversedLL->next and reversedLL->val > reversedLL->next->val){
                // cout<<reversedLL->val<<" "<<reversedLL->next->val<<endl;
                ListNode* tempHead = reversedLL;
                while(tempHead->next and reversedLL->val > tempHead->next->val ){
                    // cout<<"temp : "<<reversedLL->val<<" "<<tempHead->next->val<<endl;
                    tempHead = tempHead->next;
                }

                reversedLL->next = tempHead->next;
                reversedLL = reversedLL->next;
            }else{
                reversedLL = reversedLL->next;
            }
        }
        return reverseLL(dummyNode->next);
    }
};