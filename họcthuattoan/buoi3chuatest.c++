#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> v;
    while(n--)
    {
        string s; cin >> s;
        if(s == "push")
        {
            int x; cin >> x;
            v.push_back(x);
        }
        else if(s == "pop")
        {
            if(v.size() > 0)
            {
                v.pop_back();
            }
        }
        else if(s == "index")
        {
            int k; cin >> k;
            if(k >= 1 && k <= v.size())
            {
                cout << v[k-1] <<"\n";
            }
            else cout << -1 << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    map <int,int> mp;
    while(n--)
    {
        string s; cin >> s;
        int x;
        if(s == "add")
        {
            cin >> x;
            mp[x]++;
        }
        else if(s == "del")
        {
            cin >> x;
            if(mp.count(x))
            {
                mp[x]--;
                if(mp[x] == 0)
                {
                    mp.erase(x);
                }
            }
        }
        else if(s == "count")
        {
            cin >> x;
            if(mp.count(x))
            {
                cout << mp[x] <<"\n"; // nó sẽ in ra số lần xuất hiện của x vì trong map nó lưu theo kiểu v
            }
        }
    }
}

int main()
{
    string s; cin >> s;
    map <char,int> mp;
    for (char c : s)
    {
        mp[c]++;
    }
    for(auto it : mp)
    {
        cout << it.first << ' ' << it.second << "\n";
    }
}

//cho mãng a có n phần tử và số nguyên x. đếm cặp i < j sao cho ai+aj = x
int main()
{
    int n,x; cin >> n >> x;
    map <long long, long long> mp;
    long long ans = 0;
    for(int i = 0; i<n; i++)
    {
        long long a; cin >> a;
        long long need = x - a;
        if(mp.count(need))
        {
            ans += mp[need];
        }
        mp[a]++;
    }
    cout<<ans;
}

int main()
{
   int n; cin >> n;
   map <long long, vector<long long>> mp;
   for(int i = 0; i < n; i++)
   {
        long long x; cin >> x;
        mp[x].push_back(i); // lưu vị trí
   }
   for(auto it : mp)
   {
      cout << it.first << endl;
      for(int pos: it.second)
      {
            cout << pos << " ";        
      }
      cout <<endl;
   }
}

// cho mãng A có n x m phần tử, mỗi hàng là một tập hơp, đếm xem trong mãng có bao nhiêu tập hợp khác nhau.
// ví dụ {0,1,2} = {1,1,0,2} khác với {0,3};
int main()
{
  int n,m; cin >> n >> m;
  set<set<long long>> s;  
  for(int i = 0; i<n; i++)
  {
    set <long long> st;
    for(int j = 0; j < m;j++)
    {
        long long x; cin >> x;
        st.insert(x);
    }
    s.insert(st);
  }  
  cout << s.size();
}


int main()
{
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>>v(n+1,vector<int>(m+1)); // mãng 2 chiều m x n
    vector<long long> tonghang(n+1);
    vector <long long> tongcot(m+1);
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >>v[i][j];
            tonghang[i] += v[i][j];
            tongcot[j] += v[i][j];
        }
    }
    while (q--)
    {
        char c; cin >> c;
        int i, j, x;
        if(c == '1')
        {
            cin >> i >> j;
            swap(v[i],v[j]);
            swap(tonghang[i],tonghang[j]);
        }
        if(c == '2')
        {   cin >> i >> j >> x;
            tonghang[i] -= v[i][j];
            tongcot[j] -= v[i][j];  
            v[i][j] = x;
            tonghang[i] += v[i][j];
            tongcot[j] +=v[i][j];
        }
        if(c == 'r')
        {   
            cin >> i;
            cout << tonghang[i];
        }
        if( c == 'c')
        {
            cin >> j;
            cout << tongcot[j];
        }
    }
}

