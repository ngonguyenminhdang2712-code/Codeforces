
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map <string, int > m;
    m["A"] = 170;
    m.insert({"B",170});
    m["C"] = 180;
    for( map <string,int> :: iterator it = m.begin(); it != m.end(); it++) //duyet map bang con tro hoac thay vi dung 
                                                                        //map <string,int> :: iterator it ta co the dung auto it
    {
        cout << it->first <<' '<< it->second << '\n';
    }
    // hoac co the dung cach sau
    for(pair <string,int> p : m) // hoac auto p : m
    {
        cout << p.first <<' '<< p.second << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map <int,int> m;
    for(int i = 0; i < n ; i++)
    {   int x;
        cin >> x;
        m[x]++;
    }
    for( auto p : m)
    {
        if(p.second % 2 != 0)
        {
            cout << p.first;
            return 0;
        }
    }
    cout << " KO CO ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    set <char> st;
    for(char c : s)
    {
         st.insert(c);
    }
    cout << st.size() << endl;
    vector <char> c(st.begin(),st.end());
    for(char x : c) cout << x << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    set <string> alcohol ={"ABSINTH", "TEQUILA", "VODKA", "WHISKEY",
        "WINE", "BEER", "BRANDY", "CHAMPAGNE",
        "GIN", "RUM", "SAKE"};
    int count = 0;
    while(n--)
    {
        string s; cin >> s;
        if(isdigit(s[0]))
        {
            int tuoi = stoi(s); // dùng để chuyển 1 chuỗi thành số nguyên ví dụ string s = "17" thì s = 17
            if(tuoi < 18)
            {
                count++;
            }
        }
        else if(alcohol.count(s)) count++;
    }
    cout << count;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    set <string> s;
    for(int i = 0; i < n; i++)
    {
        string x; cin >> x;
        s.insert(x);
    }
    int m; cin >> m;
    for(int i = 0; i<m; i++)
    {
        string q; cin >> q;
        if(s.count(q))
        {
            cout << "YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}

#define maxN 1000
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k; 
    cin >> n >> k;
    map <long long, long long > m;
    int e = min(k,30);
    int a[maxN];
    int p[31];
    p[0] = 1;
    long long ans[31];
    for(int i = 1; i <= 30; i++)
    {
        p[i] = p[i-1] * 2;//  2^i = 2^i-1 * 2
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j<=30;j++)
        {
            ans[j] += m[p[j] - a[i]];
        }
        m[a[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        if(i <= e) cout << ans[i];
        else cout << 0;
        cout << '\n';
     }

    return 0;
}

int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    stack <int> s;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        int check = x % 2;
        if(s.size() > 0 && check == s.top()) s.pop();
        else s.push(check);
    }
    cout << s.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    map <int, vector <int>>v;
    for(int i = 1; i <= k; i++)
    {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
    }
    long long ans = 1LL * (n-v.size() * (m - 1)); // với mỗi hàng trống thì sẽ có m - 1 cách -> nhân cho n -vsize hàng trống
                                                  // ans là tổng số cách có thể đặt ghế á, n là số hàng, m là số ghế, vsize là số hàng đã có ghế bị đặt
    for(auto[e,a] : v)
    {
        a.push_back(m+1);
        a.push_back(0);
        sort(a.begin(),a.end());
        for(int i = 1; i < a.size(); i++)
        {
            ans += max((a[i] - a[i-1])-2,0);
        }
        cout << ans;
    }
}