
class Solution {
public:
    ListNode* fun(ListNode* head1,ListNode* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        ListNode* ans;
        if(head1->val<=head2->val){
            ans=head1;
            ans->next=fun(head1->next,head2);
        }
        else{
            ans=head2;
            ans->next=fun(head1,head2->next);
        }
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return fun(l1,l2);
    }
};
