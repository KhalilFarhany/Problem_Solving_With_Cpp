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
};
