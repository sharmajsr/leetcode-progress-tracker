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
    void reorderList(ListNode* head) {
        ListNode* newNode = head;
        ListNode* node = head;
        ListNode* duplicateNode = head;
        while(node->next && node->next->next){
            duplicateNode = duplicateNode->next;
            node = node->next->next;
        }
        cout<<duplicateNode->val<<endl;
        while(newNode->next && newNode->next->next){
            ListNode* midNode = duplicateNode;
            while(midNode->next && midNode->next->next){
                midNode = midNode->next;
            }
            // cout<<"midnode - > "<<midNode->val<<endl;
            ListNode* temp = newNode->next;
            
            newNode->next = midNode->next;
            cout<<newNode->next->val<<endl;
            // cout<<newNode->val<<" "<<newNode->next->val;//<<" "<<newNode->next->val<<endl;
            newNode->next->next = temp;
            newNode = newNode->next->next;
            midNode->next = NULL;
        }
    }
};