// https://leetcode.com/problems/reorganize-string

//  Amazon ✯   Microsoft ✯   Expedia Group ✯   Capgemini ✯   Dunzo ✯   Paypal   Adobe   eBay   Nagarro   Ingenuity Gaming   Directi   Facebook   Thought Works   American Express   Qualtrics   Google   eBay   Uber   Oracle  

// Medium

#include<iostream>
#include<climits>
using namespace std;


string reorganizeString(string s) {
    // Initialising a hash of 26 characters [small alphabets] with 0
    int hash[26] = {0};

    // storing the frequency of each character in the hash
    for(int i=0; i<s.length(); i++) {
        hash[s[i]-'a']++;
    }

    int max_frequency  = INT_MIN;
    char max_frequency_char;

    // storing the max_frequency_char and its frequency
    for(int i=0; i<26; i++) {
        if(hash[i] > max_frequency) {
            max_frequency = hash[i];
            max_frequency_char = i+'a';
        }
    }
    int index = 0;
    // putting the max frequency char at even places
    while(max_frequency > 0 && index < s.length()) {
        s[index] = max_frequency_char;
        max_frequency--;
        index += 2;
    }
        
    if(max_frequency != 0) {
        return "";
    }
    
    hash[max_frequency_char - 'a'] = 0;

    for(int i=0; i<26; i++) {
        
        while(hash[i] > 0) {
            index  = index >= s.length() ? 1 : index;
            s[index] = i+'a';
            hash[i]--;
            index += 2;
        }
        
    }

    return s;
}