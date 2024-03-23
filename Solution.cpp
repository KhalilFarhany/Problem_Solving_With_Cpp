#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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

//Problem 19: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
bool isPalindrome(string s) {
        string s2="";
        for(int i=0;i<s.length();i++) {
            if(s[i]>96 && s[i]<123 || s[i]>47 && s[i]<58) 
                s2+=s[i];
            else if(s[i]>64 && s[i]<91)
                s2+=s[i]+32;
        }
        for(int i=0;i<s2.length()/2;i++) {
            if(s2[i] != s2[s2.length()-1-i])
                return false;
        }
        return true;
    }

//Problem 19: other method
bool isPalindrom(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])) 
                return false;
            i++;
            j--;
        }
        return true;
    }


//Problem 20: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] != nums[i+1]) {
                return nums[i];
            }
            i++;
        }
        return nums[nums.size()-1];
    }


//Problem 21: Given two strings s and t, return true if t is an anagram of s, and false otherwise. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. 
//s and t consist of lowercase English letters.
bool isAnagram(string s, string t) {
        int lenS=s.length();
        int lenT=t.length();
        if(lenS != lenT) 
            return false;
        int arr[26]={0};
        for(int i=0;i<lenS;i++) {
            arr[s[i]-97]++;
            arr[t[i]-97]--;
        }
        for(int i=0;i<26;i++) {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }


//Problem 22: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it. and num >= .0
int addDigits(int num) {
        while(num>9) {
            int tmp=0;
            while(num > 9) {
                tmp+=num % 10;
                num=num / 10;
            }
            tmp+=num;
            num=tmp;
        }
        return num;
    }


//Problem 23: Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr != nullptr) {
            if(curr->val == val) {
                if(prev==nullptr) {
                    head=curr->next;
                    delete curr;
                    curr=head;
                } else {
                    curr=curr->next;
                    delete prev->next;
                    prev->next=curr;
                }
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }


//Problem 24: You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 int convertListToNumber(ListNode* l) {
        int res=0;
        while(l != nullptr){
            res*=10;
            res+=l->val;
            l=l->next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=convertListToNumber(l1)+convertListToNumber(l2);
        ListNode* l3=nullptr;
        ListNode* tmp=nullptr;
        if(sum == 0)
        {
            l3=new ListNode(0);
            l3->next=nullptr;
        }
        while(sum != 0) {
            l3=new ListNode(sum%10);
            sum /= 10;
            l3->next=tmp;
            tmp=l3;
        }
        return l3;
    }

//Problem 25:Given the head of a singly linked list, reverse the list, and return the reversed list.
 ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* head2=nullptr;
        ListNode* curr=head;
        while(curr != nullptr) {
            tmp=curr;
            curr=curr->next;
            tmp->next=head2;
            head2=tmp;
        }
        return head2;
    }


//Problem 24 (method 2):  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        ListNode* result=nullptr;
        ListNode* newNode;
        
        int rest=0;
        while(tmp1 != nullptr || tmp2 != nullptr) {
            int sum=rest;
            if(tmp1!=nullptr){
                sum+=tmp1->val;
                tmp1=tmp1->next;
            }
            if(tmp2!=nullptr) {
                sum+=tmp2->val;
                tmp2=tmp2->next;
            }
            if(sum>9) {
                sum %= 10;
                rest = 1;
            }
            else 
                rest=0;
            
            newNode = new ListNode(sum);

            newNode->next=result;
            result=newNode;
        }
        if(rest != 0) {
            newNode = new ListNode(rest);
            newNode->next=result;
            result=newNode;
        }
        return result;
    }

//Problem 26: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i=0;i<nums1.size();i++) {
            if(find(nums2.begin(),nums2.end(), nums1[i]) != nums2.end() && find(result.begin(),result.end(),nums1[i]) == result.end())
            result.push_back(nums1[i]);
        }
        return result;
    }


//Problem 27: sort by selection
vector<int> sortBySelection(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
		    int min = i;
		    for (int j = i+1; j < nums.size(); j++) 
			    if (nums[j] < nums[min])
				    min = j;
		    int tmp = nums[i];
		    nums[i] = nums[min];
		    nums[min] = tmp;
	    }
        return nums;
    }

//Problem 28: insertion sort
vector<int> insertionSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		int nb = nums[i];
		int j = i-1;
		while (nb < nums[j] && j >= 0 ) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j + 1] = nb;
	}
    return nums;
}

//Problem 29: bubble sorting
vector<int> bubbleSorting(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size()-1-i; j++) {
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
    return nums;
}

//problem 30: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m!=nums1.size()) {
            nums1.pop_back();
        }
        for(int i=0;i<n;i++) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
    }

//problem 31: Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != nullptr && q != nullptr)
            if(p->val == q->val)
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            else 
                return false;
        else if(p == nullptr && q == nullptr)
            return true;
        else 
            return false;
    }

//Problem 32: Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        for(int i=0;i<ransomNote.length();i++) {
            arr[ransomNote[i]-97]--;
        }
        for(int i=0;i<magazine.length();i++) {
            arr[magazine[i]-97]++;
        }
        for(int i=0;i<26;i++) {
            if(arr[i]<0) 
                return false;
        }
        return true;
}

//Problem 32(method 2): Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
bool canConstruct2(string ransomNote, string magazine) {
        for(int i=0;i<ransomNote.length();i++) {
            int index=magazine.find(ransomNote[i]);
            if(index == string::npos)
                return false;
            else 
                magazine.erase(magazine.begin()+index,magazine.begin()+index+1);
        }
        return true;     
    }

//Problem 33: Binary Search 
int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j) {
            int mid=(i+j)/2;
            if(nums[mid]==target) 
                return mid;
            else if(target>nums[mid]) 
                i=mid+1;
            else
                j=mid-1;
        }
        return -1;
    }


//Problem 34: reverse String with stack
string reverseStringWithStack(string str) {
    stack<char>st;
    for (char i : str) {
        st.push(i);
    }
    int j = 0;
    while (!st.empty()) {
        str[j] = st.top();
        j++;
        st.pop();
    }
    return str;
}

//Problem 35: reverse String 
string reverseString(string str) {
    for (int i = 0; i < str.length()/2; i++) {
        char c = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = c;
    }
    return str;
}


//Problem 36: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.
int calc(int a,int b,char c) {
        if(c=='+') return a+b;
        if(c=='-') return a-b;
        if(c=='*') return a*b;
        return a/b;
    } 
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string i : tokens) {
            if(i.size()==1 && (i[0]== '+' || i[0]== '-' || i[0]== '*' || i[0]== '/')){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(calc(a,b,i[0]));
            }
            else {
                st.push(stoi(i));
            } 
        }
        return st.top();
    }

//Problem 37: Write a function to find the longest common prefix string amongst an array of strings.
string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
        }
    }
    return prefix;
}

//Problem 37: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
int mySqrt(int x) {
       long start=0; 
       long end=x; 
       while(start+1 < end) {
           long mid = (end + start)/2;
           if(mid * mid == x) 
            return (int)mid;
           else if(mid * mid < x) 
            start = mid;
           else 
            end = mid;
       }
       if(end * end == x )
        return (int)end;
       return (int)start;
    }


//Problem 38: Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
string removeKdigits(string num, int k) {
    if (k >= num.length()) return "0";
    deque<int>dq;

    for (int i = 0; i < num.length(); i++) {
        int curr = num[i] - '0';
        while (!dq.empty() && curr < dq.back() && k) {
            dq.pop_back();
            k--;
        }
        dq.push_back(curr);
    }
    while (!dq.empty() && dq.front()==0) {
        dq.pop_front();
    }
    while (!dq.empty() && k--) {
        dq.pop_back();
    }
    string str = "";
    while (!dq.empty())
    {
        str += dq.front() + '0';
        dq.pop_front();
    }
    if (str == "") return "0";
    return str;
}


//Problem 39: You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//If the element is even, divide it by 2.
//for example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//If the element is odd, multiply it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.
int minimumDeviation(vector<int> nums) {
    set<int>st;
    for (int i = 0; i < nums.size(); i++) {
        int val=nums[i];
        if(val%2 != 0)
        {
            val *=2;
        }
        st.insert(val);
    }
    int mn=INT_MAX;
    int diff;
    while(1) {
        auto last=prev(st.end());
        auto first=st.begin();
        diff=*last - (*first);
        mn=min(mn,diff);
        if(*last%2 == 0) {
            int val=*last;
            st.erase(last);
            st.insert(val/2);
        }
        else break;
    }
    return mn;
    } 


//Problem 40: Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
bool validateStackSequences(vector<int>pushed, vector<int>popped) {
    stack<int>st;
    int i = 0;
    int j = 0;
    while (i < pushed.size() || j < popped.size()) {
        if (!st.empty() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
        else if (i >= pushed.size()) {
            return false;
        }
        else {
            st.push(pushed[i]);
            i++;
        }
    }
    return st.empty();
}

//Problem 41:Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
        int mx=0;
        string str="";
        for(int i=0;i<s.length();i++) {
            while(i<s.length() && str.find(s[i])==string::npos) 
            {
                    str+=s[i];
                    i++;
            }
            int len = str.length();
            if ( len > mx)
                mx = len;
            if(i<s.length())
                str=str.substr(str.find(s[i])+1);
            i--;
        }
        return mx;
    }
//Problem 42 : Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        for(unordered_map<int,int>::iterator it = mp.begin();it!=mp.end();it++) {
            if(it->second > nums.size()/2) {
                return it->first;
            }
        }
        return 0;
    }

//Problem 43 (method 2) : Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
int majorityElementM2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int majority_element = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            majority_element = nums[i];
        }
        if (nums[i] == majority_element) {
            count++;
        }
        else {
            count--;
        }
    }
    return majority_element;
}


//Problem 44 : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
bool containsDuplicate(vector<int> nums) {
        sort(nums.begin(),nums.end());
        for(vector<int>::iterator  it=nums.begin();it != prev(nums.end());it++) {
            if(*it == *(it+1)) return true;
        }
        return false;
    }

//Problem 45 : Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        int mid= nums.size() * (nums.size()+1) /2;

        return mid - sum; 
    }

//Problem 45 : Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.
void sortColors(vector<int>& nums) {
        int now=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                swap(nums[now],nums[i]);
                now++;
            }
        }

        for(int i=now;i<nums.size();i++) {
            if(nums[i] == 1) {
                swap(nums[now],nums[i]);
                now++;
            }
        }

        for(int i=now;i<nums.size();i++) {
            if(nums[i] == 2) {
                swap(nums[now],nums[i]);
                now++;
            }
        }
    }

////Problem 46 : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
vector<vector<int>> merge(vector<vector<int>> intervals) {
    int i = 0;
    sort(intervals.begin(),intervals.end());
    while (i < intervals.size() - 1) {
        if (intervals[i+1][1] < intervals[i][1])
            intervals.erase(intervals.begin() + i + 1);
        else if (intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i][1] = intervals[i + 1][1];
            intervals.erase(intervals.begin() + i + 1);
        }  
        else {
            i++;
        }
    }
    return intervals;
    }

//Problem 47 : You are given a binary string s that contains at least one '1'.
//You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
//Return a string representing the maximum odd binary number that can be created from the given combination.
string maximumOddBinaryNumber(string s) {
        string res="";
        int count =0;
        for(char& i : s) {
            if(i =='1')
                count++;
        }
        if(count==0) 
            return s;
        for(int i=1;i<count;i++) {
            res+='1';
        }
        for(int i=count;i<s.length();i++) {
            res+='0';
        }
        return res+'1';
    }

//problem 48 : Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
string reorganizeString(string s) {
    vector<int>v(26, 0);
    for (char& c : s) {
       v[c - 'a']++;
    }
    priority_queue<pair<int, char>>pq;
    for (int i = 0; i < 26;i++) {
        if (v[i])
            pq.push({ v[i],'a' + i });
    }
    string ans = "";
    while (!pq.empty()) {
        pair<int, char>t = pq.top();
        pq.pop();
        if (pq.empty() && t.first>1) {
            return "";
        }
        
        ans += t.second;
        if (!pq.empty())
        {
            pair<int, char>t2 = pq.top();
            pq.pop();
            ans += t2.second;
            if (t2.first - 1) {
                t2.first--;
                pq.push(t2);
            }
        }
        if (t.first - 1) {
            t.first--;
            pq.push(t);
        }
    }
    return ans;
}

//problem 49 : Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        for(int & i : nums) {
            res.push_back(pow(i,2));
        }
        sort(res.begin(),res.end());
        return res;
    }

//problem 50 : Given the head of a singly linked list, reverse the list, and return the reversed list.
ListNode* reverseListUsingRecursion(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

//problem 51 : Given the root of a binary tree, return the postorder traversal of its nodes' values.
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root != nullptr){
            vector<int>left=postorderTraversal(root->left);
            res.insert(res.end(),left.begin(),left.end());

            

            vector<int>right=postorderTraversal(root->right);
            res.insert(res.end(),right.begin(),right.end());

            res.push_back(root->val);
        }
        return res;
    }

//problem 52 : Given the root of a binary tree, return the preorder traversal of its nodes' values.
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root != nullptr){
            res.push_back(root->val);
            
            vector<int>left=postorderTraversal(root->left);
            res.insert(res.end(),left.begin(),left.end());
            
            vector<int>right=postorderTraversal(root->right);
            res.insert(res.end(),right.begin(),right.end());
        }
        return res;
    }

//problem 53 : You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.
//Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
//Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
//Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
//Return the maximum possible score you can achieve after playing any number of tokens.
int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int maxScore = 0;
        int score = 0;
        int l=0;
        int r=tokens.size() - 1;
        while( l<=r) {
            if(power >=tokens[l]) {
                power -=tokens[l++];
                score++;
                maxScore = max(maxScore,score);
            } else if (score>0) {
                power +=tokens[r--];
                score--;
            } else break;
        }
        return maxScore;
    }

//problem 54 : Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
//Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
//Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
//The prefix and the suffix should not intersect at any index.
//The characters from the prefix and suffix must be the same.
//Delete both the prefix and the suffix.
//Return the minimum length of s after performing the above operation any number of times (possibly zero times).
int minimumLength(string s) {
        bool test=true;
        while(s.size() > 1 && test) {
            char c1=s[0];
            char c2=s[s.size()-1];
            test=false;
            while(s.size()>0 && s[0] == c2) 
            {
                test=true;
                s.erase(s.begin());
            }
            while(s.size()>0 && s[s.size()-1] == c1) 
            {
                test=true;
                s.erase(s.begin()+s.size()-1);
            }
        }
        return s.size();
    }
//problem 55 :Given an integer n, return true if it is a power of four. Otherwise, return false.
//An integer n is a power of four, if there exists an integer x such that n == 4x.
bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<1 || n%4!=0) return false;
        return isPowerOfFour(n/4); 
    }

//problem 56 : You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
//The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
//The 1st place athlete's rank is "Gold Medal".
//The 2nd place athlete's rank is "Silver Medal".
//The 3rd place athlete's rank is "Bronze Medal".
//For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
//Return an array answer of size n where answer[i] is the rank of the ith athlete. 
vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int,int>>mp;
    int n = score.size();
    for (int i = 0; i < n; i++) {
        mp.push(make_pair(score[i], i));
    }
    vector<string>res(n);
    int i = 1;
    while(!mp.empty()) {
        pair<int, int> p = mp.top();
        if (i == 1)
            res[p.second] = "Gold Medal";
        else if (i == 2)
            res[p.second] = "Silver Medal";
        else if (i == 3)
            res[p.second] = "Bronze Medal";
        else
            res[p.second] = to_string(i);
        i++;
        mp.pop();
    }
    return res;
    }

//problem 56 : Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if (n==1) return true; 
        if(n%2 == 0) return isPowerOfTwo(n/2);
        return false;
}


//problem 57 : You are given a sorted unique integer array nums.
//A range [a,b] is the set of all integers from a to b (inclusive).
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//Each range [a,b] in the list should be output as:
//"a->b" if a != b
//"a" if a == b
vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            string s=to_string(nums[i]);
            bool entry=false;
            while(i< nums.size()-1 && nums[i]+1 == nums[i+1]) {
                i++;
                entry=true;
            }
            if(entry) {
                s+="->"+to_string(nums[i]);
            }

            res.push_back(s);
        }
        return res;
    }

//problem 58 : Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.
bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow = slow->next;
            fast=fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }


//problem 59 : Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.
int sizeList(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head->next;
        } 
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int mid = sizeList(head) / 2;
        while(mid--) {
            head=head->next;
        }
        return head;
    }

//problem 60 : You are given an array nums consisting of positive integers.
//Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
//The frequency of an element is the number of occurrences of that element in the array. 
int maxFrequencyElements(vector<int>& nums) {
       map<int,int>mp;
       int max = 0;
       int count=0;
       for(int & i:nums) {
           mp[i]++;
           if(mp[i]>max) {
               max=mp[i];
               count=1;
           }
           else if(mp[i]==max) {
               count++;
           }
       } 
       return count*max;
    }


//Problem 61 : Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
//Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int &i:nums1) {
            mp[i]++;
        }
        for(int &i:nums2) {
            if(mp[i]>0) 
                return i;
        }
        return -1;
    }

//Problem 62 : Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]==nums[i+1]) i+=2;
            else 
                return nums[i] ;
        }
        return nums[nums.size()-1];
    }

//Problem 62 : Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
vector<int> singleNumber2(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int &i:nums) {
            mp[i]++;
        } 
        for(auto &i :mp){
            if(i.second == 1) {
                res.push_back(i.first);
                if(res.size()==2) return res;
            }
        }
        return res;
    }

//Problem 63 : transfert number to text 
string NumberToText(int Number) {
	if (Number == 0) {
		return"";
	}
	if (Number >= 1 && Number <= 19) {
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return  arr[Number] + " ";
	}
	if (Number >= 20 && Number <= 99) {
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return  arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 199) {
		return"One Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 200 && Number <= 999) {
		return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999) {
		return"One Thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999) {
		return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999) {
		return"One Million " + NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999) {
		return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999) {
		return"One Billion " + NumberToText(Number % 1000000000);
	}
	else {
		return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
	}
}

//Problem 63 : You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.
string customSortString(string order, string s) {
        map<char,int>mp;
        for(char i:s) {
            mp[i]++;
        }
        string res="";
        for(char i:order) {
                for(int j=0;j<mp[i];j++) {
                    res+=i;
                }
        }
        for(char i:s) {
            if(order.find(i) == string::npos)
                res+=i;
        }
        return res;
    }

//Problem 64 : Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
//After doing so, return the head of the final linked list.  You may return any such answer.
//(Note that in the examples below, all sequences are serializations of ListNode objects.)    
ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* prec=nullptr;
        ListNode* curr=head;
        while(curr) {
            ListNode* tmp=curr;
            int s=0;
            bool isEntry=false;
            while(tmp) {
                s+=tmp->val;
                if(s==0) {
                    isEntry=true;
                    if(prec==nullptr) {
                        head=tmp->next;
                        curr=head;
                    } else {
                       curr=prec;
                       curr->next=tmp->next; 
                    }
                    break;
                }
                tmp=tmp->next;
            }
            if(!isEntry) {
                prec=curr;
                curr=curr->next;
            }
        }
        return head;
}

//Problem 65 : Given a positive integer n, find the pivot integer x such that:
//The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
//Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.
int pivotInteger(int n) {
        if(n==1) return n;
        int s=(n*(n+1))/2;
        for(int i=n/2;i<n;i++) {
            int sum1ToX=(i*(i+1))/2;
            int sumXToN=s-sum1ToX+i;
            if(sum1ToX == sumXToN) 
                return i;
        }
        return -1;
}

//Problem 66 : Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//You must write an algorithm that runs in O(n) time and without using the division operation.
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int prefix = 1;
        for(int i=0; i<nums.size(); i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i=nums.size()-1; i>=0; i--) { // iterate in reverse
            answer[i] *= postfix; // dont replace the old prefix value
            postfix *= nums[i];
        }
        return answer;
    }

//Problem 67 : You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//Return intervals after the insertion.
//Note that you don't need to modify intervals in-place. You can make a new array and return it
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        ++i;
    }
    res.push_back(newInterval);
    
    while (i < intervals.size()) {
        res.push_back(intervals[i++]);
    }

    return res;
}


//Problem 68 : You are given two linked lists: list1 and list2 of sizes n and m respectively.
//Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* lastNodeList2 = list2;
    while (lastNodeList2->next) {
        lastNodeList2 = lastNodeList2->next;
    }
    ListNode* tmp1 = list1;
    b = b - a+3;
    while (--a && tmp1) {
        tmp1 = tmp1->next;
    }
    ListNode* tmp2 = tmp1;
   
    while (--b && tmp2) {
        tmp2 = tmp2->next;
    }
    tmp1->next = list2;
    lastNodeList2->next = tmp2;
    return list1;
}

//Problem 70 : You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
void reorderList(ListNode* head) {
        ListNode* tmp=head;
        vector<int>v1;
        while(tmp != nullptr) {
            v1.push_back(tmp->val);
            tmp=tmp->next;
        }

        tmp=head;
        int i=0;
        int j=v1.size()-1;
        bool test=true;
        while(tmp != nullptr) {
            if(test) {
                tmp->val=v1[i];
                i++;
                test=false;
            } else {
                tmp->val=v1[j];
                j--;
                test=true;
            }
            tmp=tmp->next;
        }
    }
};


