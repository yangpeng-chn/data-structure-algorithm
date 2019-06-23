#include "iostream"
#include <stack>

using namespace std;

void printStr(char str[]){
    cout << str << endl;
}

void printInt(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

string isBalanced(string s) {
    stack<char> stc;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            stc.push(s[i]);
        }
        else if(s[i] == '}'){
            if(stc.empty() || stc.top() != '{') return "NO";
            else stc.pop();
        }
        else if(s[i] == ']'){
            if(stc.empty() || stc.top() != '[') return "NO";
            else stc.pop();
        }
        else if(s[i] == ')'){
            if(stc.empty() || stc.top() != '(') return "NO";
            else stc.pop();
        }
    }
    if(stc.empty())return "YES";
    return "NO";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}

