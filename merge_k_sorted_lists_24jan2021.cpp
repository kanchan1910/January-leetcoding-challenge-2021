
class Solution {
public:
    ListNode *merge(ListNode* h1,ListNode* h2)
    {
        if(h1 == NULL && h2 == NULL)
        {
            return NULL;
        }
        if(h1 == NULL)
        {
            return h2;
        }
        if(h2 == NULL)
        {
            return h1;
        }
        ListNode* ans = NULL;
        if(h1->val <= h2->val)
        {
            ans = h1;
            ans->next = merge(h1->next, h2);
        }
        else{
            ans = h2;
            ans->next = merge(h1,h2->next);
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        if(n == 0)
        {
           return NULL;
        }
        ListNode* ans = NULL;
        for(int i = 0 ; i < n ; i++)
        {
            ans = merge(ans , lists[i]);
        }
       return ans;
    }
};

// OR


class Solution {
public:
    ListNode *merge(ListNode* h1,ListNode* h2)
    {
        if(h1 == NULL && h2 == NULL)
        {
            return NULL;
        }
        if(h1 == NULL)
        {
            return h2;
        }
        if(h2 == NULL)
        {
            return h1;
        }
        ListNode* ans = NULL;
        if(h1->val <= h2->val)
        {
            ans = h1;
            ans->next = merge(h1->next, h2);
        }
        else{
            ans = h2;
            ans->next = merge(h1,h2->next);
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
          if(n == 0)
          {
              return NULL;
          }
     while(lists.size() > 1)
     {
        lists.push_back(merge(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
     }
      return lists[0]; // lists.front() can also be used
    }
};

/*begin() and end() function return an iterator(like a pointer) initialized to the first or the last element of the container that can be used to iterate through the collection, while front() and back() function just return a reference to the first or the last element of the container.*/


