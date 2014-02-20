// current state : AC
// time (first submit) : 50:23
// state (first submit) : WA
// error reason : The program didn't say that the name after country would have both first name and last name

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define maxInputNum 2000

map<string, vector<string> >input;
main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string country, name;
        cin >> country;
        getline(cin, name);

        vector<string>::iterator it = find(input[country].begin(), input[country].end(), name);
        if (it == input[country].end())
            input[country].push_back(name);
    }

    for (map<string, vector<string> >::iterator it = input.begin(); it!=input.end(); ++it)
        cout << it->first << " " << it->second.size() << endl;
}
