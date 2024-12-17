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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int, ListNode*>,vector< pair<int, ListNode*> >,greater<pair<int, ListNode*>> > nodes;
        
        for(auto node: lists){
            while(node != NULL){
                nodes.push({node->val,node});
                node=node->next;
            }
        }
        ListNode* dummyNode = new ListNode();
        ListNode* head =dummyNode;
        while(!nodes.empty()){
            auto top = nodes.top();
            // cout<<top.first<<endl;
            nodes.pop();
            dummyNode->next =  top.second;
            dummyNode = dummyNode->next;
        }
        return head->next;
    }
};