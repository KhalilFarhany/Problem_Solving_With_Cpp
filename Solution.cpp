#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
 };

//Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
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
    int missingNumber(vector<int>& array, int n) {
        int sum=(n * (n+1))/2;
        for(int i=0;i<array.size();i++) {
            sum-=array[i];
        }
        return sum;
    }



//Problem 4: Given a roman numeral, convert
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++) {
           for(int j=0;j<matrix[i].size();j++) {
               if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

//Problem 6: remove the duplicates such that each unique element appears only once and return sorted
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

//Problem 9: reverse Integer
    int reverse(int x) {
            long res=0;
            while(x != 0) {
                res = res * 10;
                res+=x%10;
                x/=10;
            }
            
            if(res>INT_MAX || res <INT_MIN) return 0;
            return res;
        }

//Problem 10: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    int isValid(string str) {
            stack <char> st ;
            int i=0;
            while(i<str.length()) {
                if(str[i] == '{' || str[i] == '[' || str[i]=='(') 
                    st.push(str[i]);
                else if(!st.empty()) {
                    char top=st.top();
                    if((top=='{' && str[i]=='}') || (top=='[' && str[i]==']') || (top=='(' && str[i]==')'))
                        st.pop();
                    else 
                        return false;
                }
                else return false;
                i++;
            }
            if(st.empty())
                return true;
            return false;
    }

//Problem 11: Remove Nth Node From End of List
    int countNode(ListNode* head) {
        int count=0;
        while(head != NULL ) {
            count++;
            head=head->next;
        }
        return count;
    } 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        n=countNode(head)-n;
        int i=0;
        while(i<n && curr!=NULL) {
            prev=curr;
            curr=curr->next;
            i++;
        }
        if(curr!=NULL) {
            if(prev==NULL) 
                head=head->next;
            else 
                prev->next=curr->next;  
            delete curr;
        }
        return head;
    } 

//Problem 12:  swap every two adjacent nodes and return its head
    ListNode* swapPairs(ListNode* head) {
      ListNode* tmp=head;
      while(tmp!=NULL && tmp->next !=NULL) {
          int val=tmp->val;
          tmp->val=tmp->next->val;
          tmp->next->val=val;
          tmp=tmp->next->next;
      }  
      return head;
    }

//Problem 13:  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++) {
            int j=0;
            int k=i;
            while(haystack[i] == needle[j] && j<needle.length() && i<haystack.length()) {
                 j++;
                 i++;
            }
            if(j>=needle.length()) 
                 return i-needle.length();
            i=k;
        }
        return -1;
    }

//Problem 14: Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal substring consisting of non-space characters only. 
int lengthOfLastWord(string s) {
        bool isFirst=true;
        int i=s.length()-1;
        int last=-1;
        int first=-1;
        while(i>=0) {
            if(isFirst && s[i] != ' ') {
                last=i;
                isFirst=false;
            }
            if(s[i] != ' ' && (i==0 || s[i-1]==' ')){
                first=i;
                break;
            }
            i--;
        }
        return s.substr(first,last-first+1).length();
    }


//Problem 15: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.Increment the large integer by one and return the resulting array of digits.
vector<int> plusOne(vector<int>& digits) {
       int rest=1;
       int i=digits.size()-1;
       int sum;
       while(i>=0 && rest>0) {
           int sum=digits[i]+rest;
           rest=sum/10;
           if(rest>0)
              digits[i]=sum%10;
           else{
               digits[i]++;
           }
           i--;
       }
       if(rest>0) {
           digits.insert(digits.begin(),rest);
       }
       return digits;
    }


//Problem 16: Given two binary strings a and b, return their sum as a binary string.

 string addNumberOfZero(string s,int numberOfZero) {
        for(int i=0;i<numberOfZero;i++) {
            s = '0'+s;
        }
        return s;
    }
    string addBinary(string a, string b) {
        if(a.length()>b.length()) 
            b=addNumberOfZero(b,a.length()-b.length());
        else 
            a=addNumberOfZero(a,b.length()-a.length());
        int rest=0;
        string s="";
        for(int i=a.length()-1;i>=0;i--) {
            int sum=int(a[i]-48)+int(b[i]-48)+rest;
            if(sum==2) {
                rest=1;
                s='0' + s;
            }
            else  if(sum==3) {
                rest=1;
                s='1' + s;
            }
            else  {
                rest=0;
                if(sum==1)  
                   s='1' + s;
                else
                   s='0' + s; 
            }
        }

        if(rest==1) 
            s='1' + s; 
        
        return s;
    }

//Problem 17: Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) 
            return head;
        ListNode* tmp=head;
        ListNode* eff;
        while(tmp->next != NULL) {
            if(tmp->val == tmp->next->val) {
                eff=tmp->next;
                tmp->next=eff->next;
                delete eff;
            }
            else {
                tmp=tmp->next;
            }
        }
        return head;
        


    }

//Problem 18: Given the root of a binary tree, return the sum of all left leaves. 
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
    int sumOfLeftLeaves(TreeNode* root) {
        if(root != NULL) {
            if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
                return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);;
            }
            else {
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            }
        }
        else return 0;
    }

};