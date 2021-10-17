#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> split_string(string);

ll findparent(vector<ll> &parent, ll i){
    if(parent[i]!=i)
        parent[i]=findparent(parent, parent[i]);
    return parent[i];
}

void theHackathon(int n, int m, int a, int b, int f, int s, int t){
    vector<int> limit = {b, f, s, t};
    unordered_map<string,ll> in;
    vector<string> inre(n);
    vector<ll> dep(n),parent(n);
    vector<vector<ll>> people(n,vector<ll>(4));
    int maxi = 0;
    while(n--)
    {
        cin>>inre[n]>>dep[n];
        parent[n]=n;
        people[n][0]=people[n][dep[n]]=1;
        in[inre[n]]=n;
    }
    string s1,s2;
    ll in1,in2,p1,p2;
    while(m--)
    {
        cin>>s1>>s2;
        in1=in[s1];
        in2=in[s2];
        p1=findparent(parent,in1);
        p2=findparent(parent,in2);
        if(p1==p2)
            continue;
        for(int i=0;i<4;i++){
            if(people[p1][i]+people[p2][i]>limit[i])
                break;
            if(i!=4)
                continue;
        }
        for(int i=0;i<4;i++)
            people[p1][i]=people[p2][i]=people[p1][i]+people[p2][i];
        parent[p2]=parent[p1]=min(p1,p2);
    }
    for(int i=0;i<people.size();i++){
        if(maxi<people[i][0])
            maxi=people[i][0];
    }
    if(a>maxi){
        cout<<"no groups";
        return;
    }
    n=people.size();
    vector<string> ans;
    unordered_set<ll> u;
    for(int i=0;i<n;i++){
        if(maxi==people[i][0])
            u.insert(i);
    }
    for(int i=0;i<n;i++){
        if(u.find(findparent(parent,i))!=u.end())
            ans.push_back(inre[i]);
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans)
        cout<<i<<"\n";
}

int main(){
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
