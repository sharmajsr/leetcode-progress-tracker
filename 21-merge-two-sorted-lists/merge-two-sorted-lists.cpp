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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode= new ListNode(0);
        ListNode* ansNode = dummyNode;
        while(list1 and list2){
            if(list1->val > list2->val ){
                dummyNode->next = new ListNode(list2->val);
                list2 =list2->next;
                dummyNode = dummyNode->next;
            }else{
                dummyNode->next = new ListNode(list1->val);
                list1 =list1->next;
                dummyNode = dummyNode->next;
            }
        }
        while(list1){
            dummyNode->next = new ListNode(list1->val);
                list1 =list1->next;
                dummyNode = dummyNode->next;
        }
        while(list2){
            dummyNode->next = new ListNode(list2->val);
                list2 =list2->next;
                dummyNode = dummyNode->next;
        }
        return ansNode->next;
    }
};