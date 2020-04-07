class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto pre_head = new ListNode(0);
        auto t = pre_head;

        ListNode **p = nullptr;

        auto size = lists.size();

        int minimum;
        bool found;

        while (true) {
            minimum = 2147483647;
            found = false;
            p = nullptr;

            for (int i = 0; i < size; ++i) {
                if (lists[i] != nullptr)
                {
                    if (lists[i]->val < minimum) {
                        minimum = lists[i]->val;
                        p = &lists[i];
                        found = true;
                    }
                }
            }

            if (!found) {
                break;
            } else {
                t->next = (*p);
                t = t->next;
                (*p) = (*p)->next;
                t->next = nullptr;
            }
        }

        return pre_head->next;
    }
};
