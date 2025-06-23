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
        }
        cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL)    return ;
        cout<<"Head not null \n";
        ListNode* slow =head;
        ListNode* fast = head;
        ListNode* prev;
        while(slow and fast and fast->next){
            cout<<slow->val<<" "<<fast->val<<endl;
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<"slow -> val "<<slow->val<<endl;
        ListNode* midNode;
        if(!fast){
            cout<<"even list\n";
            midNode = prev->next;
            cout<<midNode->val<<endl;
            prev->next = NULL;
        }else{
            cout<<"odd list\n";
            midNode =slow->next;
            cout<<midNode->val<<endl;
            slow->next = NULL;
        }
        cout<<"midNode before rev ";
        printList(midNode);
        ListNode* l2 = reverseList(midNode);
        ListNode* l1 = head;
        cout<<"L1 ";
        printList(l1);
        cout<<"L2 ";
        printList(l2);
        
        // 1 -> 2 -> NULL
        // 3 -> 4 -> NULL
        //     nxt
        while(l1 and l2){
            ListNode* next = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
            l2 = next;
        }



    }
};