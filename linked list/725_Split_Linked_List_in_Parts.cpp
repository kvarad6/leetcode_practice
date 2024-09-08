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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);
        int N = 0;
        //finding size of linkedlist
        ListNode* temp = head;
        while(temp!=NULL){
            N++;
            temp = temp->next;
        }
        //N-> total nodes in a linkedlist
        //k-> parts
        //every part has N/k elements
        //first N%k parts have an extra one
        int elements = N/k;
        int extra = N%k;

        // ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        for(int i=0;i<k;i++){
            result[i] = curr;
            // Handle case where current part is empty
            if(curr == nullptr) continue;

            for(int count=1;count<=elements+(extra>0 ? 1 : 0)&& curr!=nullptr; count++){
                prev = curr;
                curr = curr->next;
            }
            // Only set prev->next to nullptr if prev is not nullptr
            if(prev != nullptr) {
                prev->next = nullptr;
            }
            extra--;
        }
        return result;
    }
};
