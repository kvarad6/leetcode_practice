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
    ListNode* sortList(ListNode* head) {
        //------------ Approach 1 ------------//
        // bruite force
        // Old LL -> Array -> Sort -> New LL
        // TC: O(NlogN)
        // SC: O(N)

        //base case
        if(head==NULL){
            return NULL;
        }

        vector<int> arr;

        //storing all the ll elements in a vector
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        //sorting it
        sort(arr.begin(), arr.end());

        //storing sorted elements from the vector to new ll.
        //creating a new node with arr[0] as its value
        ListNode* node = new ListNode(arr[0]);
        head = node;
        ListNode* newTemp = head;
        for(int i=1;i<arr.size();i++){
            ListNode* newNode = new ListNode(arr[i]);
            newTemp->next = newNode;
            newTemp = newTemp->next;
        }
        return head;
    }
    

    ListNode* sortList(ListNode* head) {
        //------------ Approach 2 ------------//
        
        // Middle of LL (using Fast-Slow) -> Sort (first half) -> Sort (second half) -> Merge Two sorted lists

        //base case
        if(head == NULL || head ->next == NULL)
            return head;

        ListNode *temp = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergeList(l1, l2);
    }

    ListNode* mergeList(ListNode* list1, ListNode* list2){
        //base cases..
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        //temp variables pointing to current LLs..

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        //creating a new node and assigning it to new LL..

        ListNode* dummyNode = new ListNode(-1);
        ListNode* l3 = dummyNode;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                l3->next = l1;
                l1 = l1->next;
            }
            else{
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }

        //Fill out the remaining nodes in new LL..

        while(l1!=NULL){
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
        }

        while(l2!=NULL){
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }

        return dummyNode->next;
    }
};
