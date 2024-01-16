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




};

