// current state : AC
// error reason : forgot to handle empty string

#include <iostream>
#include <stack>
#include <map>
using namespace std;

const char leftParentheses[2] = {'(','['};
const char rightParentheses[2] = {')',']'};

map<char, char> pairedParentheses;

void initialPairedParentheses();
bool isBalancedParentheses(string);
bool isLeftParentheses(char);
bool isRightParentheses(char);

main()
{
    ios::sync_with_stdio(false);
    initialPairedParentheses();

    int caseNum;
    string parentheses;

    cin >> caseNum;
    getline(cin, parentheses);
    while(caseNum--) {
        getline(cin, parentheses);
        cout << (isBalancedParentheses(parentheses) ? "Yes": "No") << endl;
    }
}

void initialPairedParentheses() {
    for (int i = 0; i < 2; i++) {
        pairedParentheses[leftParentheses[i]] = rightParentheses[i];
        pairedParentheses[rightParentheses[i]] = leftParentheses[i];
    }
}

bool isBalancedParentheses(string p) {
        stack<char> s;
        bool isBalanced = true;

        for (int i = 0; i < p.size(); i++)
            if (s.empty() || isLeftParentheses(p[i]))
                s.push(p[i]);
            else {
                char top = s.top();
                s.pop();

                if (pairedParentheses[top] != p[i]) {
                    isBalanced = false;
                    break;
                }
            }

        if (!s.empty())
            isBalanced = false;

        return isBalanced;
}

bool isLeftParentheses(char p) {
    return (p == leftParentheses[0] || p == leftParentheses[1]);
}

bool isRightParentheses(char p) {
    return (p == rightParentheses[0] || p == rightParentheses[1]);
}
