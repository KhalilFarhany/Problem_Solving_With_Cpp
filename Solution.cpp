#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
 };

class Solution{
  public:
  //problem 1: Find duplicates in an array
    vector<int> duplicates(long long arr[], int n) {
        sort(arr,arr+n);
        vector<int> result;

        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1] && find(result.begin(),result.end(),arr[i])==result.end())
                result.push_back(arr[i]);
        }

        if(result.size()==0)
           result.push_back(-1);

        return result;
    }

//Problem 2: Merge the two lists into one sorted list
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* tmp1=list1;
        ListNode* tmp2=list1;
        while(tmp1->next != NULL) {
            tmp1=tmp1->next;
        }
        tmp1->next=list2;

        for(tmp1=list1 ; tmp1!=NULL ; tmp1=tmp1->next) {
            for(tmp2=tmp1->next ; tmp2!=NULL ; tmp2=tmp2->next) {
                if(tmp2->val < tmp1->val) {
                    int num=tmp1->val;
                    tmp1->val=tmp2->val;
                    tmp2->val=num;
                }
            }
        }
        return list1;
    }


//Problem 3: find missing number in array
  public:
    int missingNumber(vector<int>& array, int n) {
        int sum=(n * (n+1))/2;
        for(int i=0;i<array.size();i++) {
            sum-=array[i];
        }
        return sum;
    }



//Problem 4: Given a roman numeral, convert
  public:
    int romanToInt(string s) {
        int number;
        int sum=0;
        for(int i=s.length()-1;i>=0;i--) {
            switch(s[i]) {
                case 'I' :
                    number=1;
                    break;
                case 'V' :
                    number=5;
                    break;
                case 'X' :
                    number=10;
                    break;
                case 'L' :
                    number=50;
                    break;
                case 'C' :
                    number=100;
                    break;
                case 'D' :
                    number=500;
                    break;
                case 'M' :
                    number=1000;
                    break;
            }
            if((s[i]== 'X' || s[i]=='V') && i>0 && s[i-1]=='I')
            {
                number-=1;
                i--;
            }
            else if((s[i]== 'C' || s[i]=='L') && i>0 && s[i-1]=='X')
            {
                number-=10;
                i--;
            }
            else if((s[i]== 'D' || s[i]=='M') && i>0 && s[i-1]=='C')
            {
                number-=100;
                i--;
            }
            sum+=number;
        }
        return sum;
    }


//Problem 5: Given an integer target,return true if target is in matrix
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++) {
           for(int j=0;j<matrix[i].size();j++) {
               if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

//Problem 6: remove the duplicates such that each unique element appears only once and return sorted
public:
    void removeDuplicates(vector<int>&nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
    }


/*Problem 7: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/
public:
    int count(ListNode* head) {
        int count=0;
        while(head != NULL) {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* N=NULL;
        ListNode* tmp=head;
        ListNode* newHead=tmp;
        vector<ListNode*>v;

        while(tmp!= NULL) {
            int kTmp=k;
            if(count(tmp)>=k){
                while(kTmp-- && tmp !=NULL) {
                    newHead=tmp;
                    tmp=tmp->next;
                    newHead->next=N;
                    N=newHead;
                }
                v.push_back(newHead);
                N=NULL;
            }
            else{
                 v.push_back(tmp);
                 break;
            }  
        }
       

        for(int i=0;i<v.size()-1;i++) {
            tmp=v[i];
            while(tmp->next != NULL) {
                tmp=tmp->next;
            }
            tmp->next=v[i+1];
        }
        return v[0];
}


//Problem 8: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
        vector <int> v=nums1;
        for(int i=0;i<nums2.size();i++) {
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        if(v.size()%2==0)
        {
            return((double)(v[v.size()/2]+v[v.size()/2 - 1])/2);
        }
        else return v[v.size()/2];
};

};

