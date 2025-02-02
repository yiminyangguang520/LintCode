// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy = ListNode(std::numeric_limits<int>::min());
        dummy.next = head;
        ListNode *cur = head, *cur_dummy = &dummy;
        int length = 0;

        while (cur) {
            ListNode *next_cur = cur->next;
            length = (length + 1) % k;

            if (length == 0) {
                ListNode *next_dummy = cur_dummy->next;
                reverse(&cur_dummy, cur->next);
                cur_dummy = next_dummy;
            }
            cur = next_cur;
        }
        return dummy.next;
    }

    void reverse(ListNode **begin, const ListNode *end) {
        ListNode *first = (*begin)->next;
        ListNode *cur = first->next;

        while (cur != end) {
            first->next = cur->next;
            cur->next = (*begin)->next;
            (*begin)->next = cur;
            cur = first->next;
        }
    }
};
