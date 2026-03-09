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
        ListNode* temp = head;
        vector<ListNode*> nodesArray;
        while(temp != NULL)
        {
            nodesArray.push_back(temp);
            temp = temp -> next;
        }

        int i = 0, j = nodesArray.size() - 1;
        while(i < j)
        {
            nodesArray[i] -> next = nodesArray[j];
            i++;
            if(i == j) break;
            nodesArray[j] -> next = nodesArray[i];
            j--;
        }
        nodesArray[i] -> next = NULL;

    }
};