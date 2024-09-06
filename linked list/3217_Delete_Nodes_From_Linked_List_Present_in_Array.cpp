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
//----------- Approach 1 | unordered_map<int, int> -----------//
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //creating a hashmap and inserting array elements into it
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        //edge cases
        if(head==NULL || head->next==NULL){
            return head;
        }
        /*the following test case is not valid:
            nums = [1]
            head = [1]
            As, in the constraints, it's mentioned that:
            "The input is generated such that there is at least one node in the linked list that has a value not present in nums."
        */

        //case where we are deleting the current head and upadting the same till we remove all the heads that are the part of the nums array
        while(mpp.find(head->val)!=mpp.end()){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }

        //to keep the track of previous node
        ListNode* prev = head;
        ListNode* curr;
        if (head != NULL) {
            curr = head->next;
        } else {
            curr = NULL;
        }

        //transverse the linkedlist, check of current node's value present in array, if yes, remove
        while(curr!=NULL){
            if(mpp.find(curr->val)!=mpp.end()){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

//--------- Approach 2 | unordered_map<int, bool> ----------//


//--------- Appraoch 3 | unordered_set<int> ----------//

