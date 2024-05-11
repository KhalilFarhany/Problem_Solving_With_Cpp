#include <bits/stdc++.h>

class Solution {
public:
    //Problem 1 
    bool isValid(string word) {
        if(word.size()<3)
            return false;
        string vowels="aAeEiIuUoO";
        bool isVowel=false;
        bool isConsonant=false;
        for(char &i : word) {
            if(i>47 && i<58)
                continue;
            if((i>64 &&  i<91)  || (i>96 && i<123) ) {
                if(vowels.find(i) != string::npos) {
                    isVowel=true;
                } else 
                    isConsonant=true;
                continue;
            }
            return false;
        }
        if(isVowel && isConsonant)
            return true;
        return false;
    }
};