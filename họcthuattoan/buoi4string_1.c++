#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); 
    // tìm số nguyên âm hoặc tìm bất cứ kí tự nào và đếm nó:
    string s;
    getline(cin, s);
    string t = "aeoui";
    int ans = 0;
    for(char c : s)
    {
        c = tolower(c);
        ans += t.find(c) != -1;
    }
    cout << ans;
}

//////////////// MẬT KHẨU MẠNH////////////
// một mật khẩu được xem là mạnh nếu như nó có:
// ít nhất 1 chữ số, ít nhất 1 chữ Hoa, ít nhất một chữ thường và có độ dài ít nhất 8 kí tự.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); 
    string s; cin >> s;
    bool digit = false;
    bool chuhoa = false;
    bool chuthuong = false;
    for(char c : s)
    {
        if(isdigit(c))
        {
            digit = true;
        }
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            chuhoa = true;
        }
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            chuthuong = true;
        }
    }
    if(digit && chuhoa && chuthuong &&s.size()>=8)
    {
        cout << "STRONG";
    }
     else
        {
            cout << "WEAK";
        }
}

/////////////THỐNG KÊ KÍ TỰ///////////////////
// với mỗi ký tự từ a-z hãy đếm số lần xuất hiện của nó trong S

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); 
    // tìm số nguyên âm hoặc tìm bất cứ kí tự nào và đếm nó:
    string s;
    getline(cin,s);
    map <char,int> mp;
    for(char c : s)
    {
        if( c >= 'a' && c <= 'z')
        {
            mp[c]++;
        }
    }
    for(char c = 'a'; c <='z';c++)
    {
        cout << c << " " << mp[c] << '\n';
    }
}

//////////ĐẾM XÂU//////////////
// cho 2 xâu S và T. Đếm số lần xuất hiện của T trong S ví dụ: input :asasa và asa, thì sẽ in ra 2 xâu giống nhau
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s,t; 
    cin >> s >> t;
    int vitri = 0;
    int ans = 0;
    while(1)
    {
        vitri = s.find(t,vitri);
        if(vitri != -1)
        {
            ans++;
            vitri++;
        }
        else{
            break;
        }
    }
    cout << ans;
}

/////////////////////CHUẨN HÓA XÂU///////////////////
//Cho 1 xâu gồm các chữ cái và dấu cách. Thực hiện chuẩn hóa xâu:
///////////Không có dấu cách ở đầu và cuối câu
///////////Không có quá 1 dấu cách giữa các từ
///////////Các chữ cái đầu tiên giữa các từ viết hoa còn lại viết thường



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    getline(cin,s);
    for(int i = 0;i < s.size(); i++)
    {
        if(s[0] == ' ') s.erase(0,1);
        if(s[s.size()-1] == ' ') s.erase(s.size()-1,1);
    }
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == ' ' && s[i+1] == ' ')
        {
            s.erase(i,1);
            i--;
        }
    }
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i-1]  == ' ')
        {
            s[i] = toupper(s[i]);
        }
    }
    cout << s;
}
//////////Cách hay hơn///////////

int main()
{
    string s; getline(cin,s);
    string ans;
    for(char c : s)
    {
        if (c == ' ')
        {
            if(ans.size() == 0 || ans.back() == ' ') continue;
            ans += ' ';
        }
        else
        {
            if(ans.size() == 0 || ans.back() == ' ') c = toupper(c);
            else c = tolower(c);
            ans+=c;
        }
    }
    if(ans.back() == ' ') ans.pop_back();
    cout << ans;
    return 0;
}


//////////Cách hay hơn nhất///////////
int main()
{
    string s;
    vector <string> v;
    while(cin >> s)
    {
        v.push_back(s);   
    }
    for(string &s : v)
    {
        transform(s.begin(),s.end(),s.begin(), :: tolower);
        s[0] -= 32;
    }
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i == v.size()-1)
        {
            cout <<'\n';
        }
        else cout << ' ';
    }
}


/////////////////Run-Length-Ecoding//////////////
//// dòng đầu tiên là xâu s1 để giải mã xâu ví dụ: aaabbcc thì sẽ đổi thành 3a2b2c;
////dòng 2 là xâu s2 để nén xâu ví dụ nhập 3a2b2c thì sẽ đổi thành aaabbcc;

int main()
{
    string s1; cin >> s1;
    string s2; cin >> s2;
    int dem = 1;
    for(int i = 1; i < s1.size(); i++)
    {
        if(s1[i] == s1[i-1])
        {
            dem++;
        }
        else
        {
            cout << dem << ' ' << s1[i-1];
            dem = 1;    
        }
    }
    cout << dem << ' ' << s1[s1.size()-1]; //in ra thằng cuối cùng
    int num = 0;
    for(char c : s2)
    {
        if(isdigit(c))
        {
            num = num * 10 + (c - '0'); // ghép chữ ví dụ c = '1' thì num = 0*10 + 1 = 1 (c-'0') là biến kiểu char thành int
        }
        else
        {
            for(int i = 0; i < num; i++) cout << c;
            num = 0;
            
        }
    }

}

//////////////Cách dùng vector cho xâu s1///////////
int main()
{
    string s1; cin >> s1;
    vector <pair<int,char>> v;
    for(char c : s1)
    {
        if(v.size() == 0 || v.back().first != c )
        {
            v.push_back({c,1});
        }
        else
        {
            v.back().second++;
        }
    }
    for(auto x : v)
    {
        cout << x.second << " " << x.first;
    }
}

////////////////TỔNG//////////////////////
//Cho một xâu S chỉ gồm các chữ cái, chữ số và dấu cách, xóa các chữ cái và in ra tổng các số trong xâu.
//Xâu có thể gồm các dấu cách thừa

int main()
{
    string s; getline(cin, s);
    int sum = 0; 
    int num = 0;
    for(char c : s)
    {
        if(isdigit(c))
        {
            num = num * 10 + (c-'0'); // lỡ nó là các số liên tiếp nên làm vậy;
        }
        else
        {
            sum = sum + num;
            num = 0;
        }

    }
    sum += num; // cộng số cuối
    cout << sum;
}

////////Chat room//////////////
// cho chuỗi s và chuỗi t = hello. tìm coi chuỗi s có ghép lại thành được hello hay ko
int main()
{
    string s; cin >> s;
    string t = "hello";
    int vitri = 0;
    for(char c : s)
    {
        if(vitri < t.size() && c == t[vitri])
        {
            vitri++;
        }
    }
    if(vitri == t.size())
    {
        cout << "YES";
    }
    else cout << "NO";
}

////////////////QUERIES ON STRING////////////////////
//có 1 chuỗi s và m truy vấn và trong mỗi truy vấn có l r và k
// l và r là điểm đầu và điểm  cuỗi của chuỗi cần xoay và k là số lần xoay
// mỗi lần xoay sẽ chuyển thằng cuối lên đầu
int main()
{
    string s; cin >> s;
    int m; cin >> m;
    while(m--)
    {
        int l, r, k; cin >> l >> r >> k;
        int len = r - l + 1;
        k = k % len;
        while (k--)
        {
            char last = s[r-1];
            for(int i = r-1; i > l-1; i--)
            {
                s[i] = s[i-1];
            }
            s[l-1] = last;
        }
    }
    cout << s;
}