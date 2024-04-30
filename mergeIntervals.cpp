#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals) {
    vector<pair<int, int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++) {
        int lastInAns = mergedIntervals.back().second;
        if(lastInAns >= intervals[i].first) {
            mergedIntervals.back().second = lastInAns > intervals[i].second ? lastInAns : intervals[i].second;
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    return mergedIntervals;
}

bool checkOverlap(vector<int> v1, vector<int> v2) {
    if(v1[1] < v2[0] || v2[1] < v1[0]) {
        return false;
    }
    return true;
}

vector<int> returnOverlappingVec(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    ans.push_back(min(v1[0], v2[0]));
    ans.push_back(max(v1[1], v2[1]));
    return ans;
}

vector<vector<int>> InsertInterval(vector<vector<int>> existingIntervals, vector<int> newInterval)
{
    vector<vector<int>> ans;
    int n = existingIntervals.size();
    int i = 0;
    while(i<n && existingIntervals[i][1]<newInterval[0]) {
        ans.push_back(existingIntervals[i]);
        i++;
    }
    while(i<n && checkOverlap(existingIntervals[i], newInterval)) {
        newInterval = returnOverlappingVec(existingIntervals[i], newInterval);
        i++;
    }
    ans.push_back(newInterval);
    while(i<n) {
        ans.push_back(existingIntervals[i]);
        i++;
    }
    return ans;
}

bool comparePairs(pair<char, int> p1, pair<char, int> p2) {
    return p1.second > p2.second;
}

struct node
{
    int data;
    node* next;
    node(int x) {
        data = x;
        next = NULL;
    }
};

void traverseLL(node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* mergeKLists(vector<node*> &lists) {
    priority_queue<pair<int, node*>, vector<pair<int, node*>>, greater<pair<int, node*>>> pq;
    for(int i=0; i<lists.size(); i++) {
        if(lists[i] != NULL) {
            pq.push({lists[i]->data, lists[i]});
        }
    }
    node* head = new node(0);
    node* temp = head;
    while(!pq.empty()) {
        pair<int, node*> p = pq.top();
        pq.pop();
        temp->next = p.second;
        temp = temp->next;
        if(p.second->next != NULL) {
            pq.push({p.second->next->data, p.second->next});
        }
    }
    return head->next;
}

node* merge2ll(node* l1, node* l2) {
    node* head = new node(INT_MIN);
    node* ans = head;
    while(l1 && l2) {
       if(l1->data < l2->data) {
           head->next = l1;
           l1 = l1->next;
       } else {
           head->next = l2;
           l2 = l2->next;
       }
    }
    if(l1) head->next = l1;
    if(l2) head->next = l2;
    return ans->next;
}

int main() {
    cout<<"Hello From Hrithik \n";
    // vector<pair<int, int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}, {17,20}};
    // vector<pair<int, int>> mergedIntervals = mergeIntervals(intervals);
    // for(auto i: mergedIntervals) {
    //     cout<<"["<<i.first<<", "<<i.second<<"] ";
    // }
    // cout<<endl;
    // vector<vector<int>> existingIntervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    // vector<int> newInterval = {4, 9};
    // vector<vector<int>> ans = InsertInterval(existingIntervals, newInterval);
    // for(auto i: ans) {
    //     cout<<"["<<i[0]<<", "<<i[1]<<"] ";
    // }
    // cout<<endl;
    // vector<node*> lists;
    node* head1 = new node(1);
    head1->next = new node(4);
    head1->next->next = new node(5);
    node* head2 = new node(1);
    head2->next = new node(3);
    head2->next->next = new node(4);
    head2->next->next->next = new node(7);
    // node* head3 = new node(2);
    // head3->next = new node(6);
    // head3->next->next = new node(8);
    // lists.push_back(head1);
    // lists.push_back(head2);
    // lists.push_back(head3);
    // node* head = mergeKLists(lists);
    node* head = merge2ll(head1, head2);
    traverseLL(head);
    return 0;
}