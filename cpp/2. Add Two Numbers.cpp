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
		ListNode* l3 = nullptr, *pHeadNode = nullptr;
		int flag = 0;
		while (l1 && l2)
		{
			int sum = l1->val + l2->val + flag;
			flag = (sum) / 10;
			ListNode* pTempNode = new ListNode(sum % 10);
			if (l3){
				l3->next = pTempNode;
				l3 = l3->next;
			}
			else
				pHeadNode = l3 = pTempNode;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* pResNode = l1 ? l1 : l2;
		while (pResNode){
			int sum = pResNode->val + flag;
			flag = sum / 10;
			ListNode* pTempNode = new ListNode(sum % 10);
			l3->next = pTempNode;
			l3 = l3->next;
			pResNode = pResNode->next;
		}
		if (flag)
			l3->next = new ListNode(flag);
		return pHeadNode;
	}
};
