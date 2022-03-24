#include<bits/stdc++.h>
using namespace std;
int N, T;
map<string, string> userBlances;

string removeLeadingZeros(string str)
{
    int lens = str.length();
    if(lens == 1){
        return str;
    }

    string newStr;
    int iMark = -1;
    for(int i=0; i<lens; i++){
        if(str[i] != '0'){
            iMark = i;
            break;
        }
    }

    if(iMark == -1){
        return "0";
    }

    return str.substr(iMark, lens);
}

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits

        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());
    return str;
}

void solve(string username1, string username2, string transfer){
    map<string, string>::iterator user1 = userBlances.find(username1);
    map<string, string>::iterator user2 = userBlances.find(username2);

    if(!isSmaller(user1->second, transfer)){
        string balance1 = findDiff(user1->second, transfer);
        string balance2 = findSum(user2->second, transfer);

        user1->second = removeLeadingZeros(balance1);
        user2->second = removeLeadingZeros(balance2);
    }
}

void input(){
    cin >> N >> T;
    for(int i=0; i<N; i++){
        string tempName;
        string rootBalance;
        cin >> tempName >> rootBalance;
        userBlances.insert(pair<string, string>(tempName, rootBalance));
    }

    for(int i=0; i<T; i++){
        string tempUser1;
        string tempUser2;
        string tmpTransfer;

        cin >> tempUser1 >> tempUser2 >> tmpTransfer;
        solve(tempUser1, tempUser2, tmpTransfer);
    }
}

int main(){
    input();

    map<string, string>::iterator itr;
    vector<string> keys;
    for(itr=userBlances.begin(); itr != userBlances.end(); ++itr){
        string username = itr->first;
        keys.push_back(username);
    }

    sort(keys.begin(), keys.end());
    for(string key: keys){
        string username = userBlances.find(key)->first;
        string balance = userBlances.find(key)->second;
        cout << username << " " << balance << endl;
    }
    return 0;
}
