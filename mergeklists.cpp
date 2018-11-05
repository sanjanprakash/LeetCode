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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *mv;
        ListNode *ans = new ListNode(0);
        ListNode *temp,*curr = ans;
        vector<ListNode*> arr;
        int i, count = 0, nulls = 0;
        for (i = 0; i < k; i++) {
            if (lists[i] == NULL)
                nulls++;
            else
                arr.push_back(lists[i]);
        }
        k -= nulls;
        if (k == 0)
            return NULL;
        for (i = k/2 - 1; i >= 0; i--)
            Heapify(arr,i,k);
        while (k != 0) {
            if (count == 0) {
                temp = Min(arr,k);
                if (temp == NULL)
                    break;
                ans = temp;
                if (temp->next != NULL) {
                    Insert(arr,temp->next,k);
                }
                curr = ans;
            }
            else {
                temp = Min(arr,k);
                if (temp == NULL)
                    break;
                curr->next = temp;
                curr = curr->next;
                if (temp->next != NULL) {
                    Insert(arr,temp->next,k);
                }
            }
            count++;
        }
        return ans;
    }
    void Heapify(vector<ListNode*> &arr, int i, int n) {
        int left = 2*i + 1;
        int right = left + 1;
        int smallest = i;
        if (left < n) {
            if (arr[smallest]->val > arr[left]->val)
                smallest = left;
        }
        if (right < n) {
            if (arr[smallest]->val > arr[right]->val)
                smallest = right;
        }
        if (smallest != i) {
            swap(arr[i],arr[smallest]);
            Heapify(arr,smallest,n);
        }
    }
    ListNode* Min(vector<ListNode*> &arr, int &n) {
        if (n == 0)
            return NULL;
        ListNode *ans = arr[0];
        arr[0] = arr[n-1];
        n--;
        Heapify(arr,0,n);
        return ans;
    }
    void Insert(vector<ListNode*> &arr, ListNode *neo, int &n) {
        arr[n] = neo;
        int i = n;
        while (i != 0 && arr[(i-1)/2]->val > arr[i]->val) {
            swap(arr[(i-1)/2],arr[i]);
            i = (i-1)/2;
        }
        n++;
    }
};
