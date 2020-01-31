#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if((l1 == nullptr && l2 == nullptr) || l2 == nullptr) {
            return l1;
        }
        if(l1 == nullptr) {
            return l2;
        }
        ListNode *l = nullptr;
        if(l1->val <= l2->val) {
            l = l1;
            l1 = l1->next;
        }
        else {
            l = l2;
            l2 = l2->next;
        }
        ListNode *p = l;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr) {
            p->next = l1;
        }
        if(l2 != nullptr) {
            p->next = l2;
        }
        return l;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
