#include<bits/stdc++.h>
using namespace std;

// split string with space charactor
vector<string> simple_tokenizer(string s)
{
    vector<string> tokenizer;

    stringstream ss(s);
    string word;
    while (ss >> word) {
        tokenizer.push_back(word);
    }

    return tokenizer;
}

// convert string to int
int string_parse_int(string str){
    stringstream ss(str);
    int x = 0;

    ss >> x;

    return x;
}
