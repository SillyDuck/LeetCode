#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = l1->val + l2->val;
        int tmp;
        if(sum > 9) tmp = 1;
        else tmp = 0;
        ListNode* l3 = new ListNode(sum);
        ListNode* ans = l3;
        while(l1->next != NULL){
            l1 = l1->next;
            l2 = l2->next;
            sum = l1->val + l2->val + tmp;
            if(sum > 9) tmp = 1;
            else tmp = 0;
            l3 -> next = new ListNode(sum);
            l3 = l3 -> next;
        }
        return ans; 
    }
};

int main(){

    Solution aaa;
}
