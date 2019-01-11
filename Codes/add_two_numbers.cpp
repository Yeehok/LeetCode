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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *root = new ListNode(0);
		ListNode *p = root;
		ListNode *q = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			if (p->next == NULL)
			{
				q = new ListNode(0);
				p->next = q;
				q = NULL;
			}

			p = p->next;

			if (l1 != NULL)
			{
				p->val += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				p->val += l2->val;
				l2 = l2->next;
			}
			
			if (p->val >= 10)
			{
				q = new ListNode(p->val / 10);
				p->next = q;
				p->val %= 10;
				q = NULL;
			}
		}

		q = root;
		root = root->next;
		delete q;
		q = NULL;
		return root;
	}
};
