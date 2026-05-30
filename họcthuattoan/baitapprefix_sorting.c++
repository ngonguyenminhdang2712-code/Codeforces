#include<bits/stdc++.h>
#include<iostream>
using namespace std;

///////////////////////////////SORTING/////////////////////// 
//BÀI 1: SẮP XẾP ĐIỂM X Y Z TĂNG DẦN
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<tuple<int, int, int>>v(n);
    for(int i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[i] = make_tuple(x,y,z);
    }
    sort(v.begin(),v.end());
    for(auto [a,b,c] : v)
    {
        cout << a << ' ' << b << ' ' << c <<'\n';
    }
    return 0;
}


///BÀI 2: NẤU THUỐC: MARISA có n cây nấm, mỗi cây nấm nặng Ai. MARISA muốn pha thuốc từ n cây nấm này
/// Mỗi chai thuốc không được pha từ không quá 2 cây nấm và cân nặng của chúng cũng không được quá k.
/// số chai thuốc ít nhất mà cô ấy có thể pha được từ n chai thuốc là bn(vì càng ít càng dễ mang theo).
// input: n = 5, k = 7, a[i] = 1 2 3 5 7; output: 3 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int l = 0, r = n - 1;
    int count = 0;

    while(l <= r)
    {
        if(v[l] + v[r] <= k)
        {
            l++; 
        }
        r--; 
        count++;
    }
    cout << count;
}


//BÀI 3: KHOẢNG CÁCH NHỎ NHẤT: Cho n điểm trên hệ trục tọa độ hai chiều. Điểm i có tọa độ(x,y). Khoảng cách
// giữa điểm u và v là |ux - vx| + |uy - vy|. Tìm điểm A với tọa độ nguyên để tổng khoảng cách từ A tới n
//điểm đã cho là min
//Input:dòng thứ nhất là n và n dòng tiếp theo là x và y;
//Output: in ra một số nguyên khoảng cách nhỏ nhất từ A - n điểm.
//HINT: sort một mảng theo thứ tự tăng dần thì để cho tổng tất cả phần tử |a[i] - x| min 
/// thì x là vị trí trung vị của mảng 
int main()
{
        int n; cin >> n;
        vector<int>x(n),y(n);
        for(int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int X = x[n/2];
        int Y = y[n/2];
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += abs(X - x[i]) + abs(Y-y[i]);
        }
        cout << ans << '\n';

}

////BÀI 4: SẮP XẾP LỚN NHẤT; cho mảng A gồm n phần tử dương, nhiệm vụ là sắp xếp lại mảng A và ghép chúng
// thành 1 số nguyên duy nhất sao cho số nguyên đó là lớn nhất. ví dụ A = {23,16,4}
// thì in ra là: 42316.
int main()
{
    int n; cin >> n;
    vector<string>v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end(), [](string a, string b) { //phải dùng string vì ví dụ 9,91 thì khi a + b là 991
                                                     // còn nếu dùng int thì a + b thành 100;
        return a + b > b + a;
    });
    for(string c:v ) cout << c;
}


///BÀI 5: TRÒ CHƠI BẤM NÚT; Bạn đang chơi 1 trò chơi với n nút bấm. bạn có q lượt chơi, mỗi lượt sẽ dc bấm 1 nút
/// Khi bấm nút thứ i, bạn sẽ được thêm Si điểm. Ngoài ra, khi lần đầu tiên bấm nút thứ i, bạn cũng sẽ được thưởng
// thêm Ei điểm. Hãy tìm cách bấm nút đó sao cho được max điểm
int main()
{
    int n,q; cin >> n >> q;
    vector<pair<int,int>>v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;     
        }
        sort(v.begin(),v.end(), [](pair<int,int> a, pair<int,int> b)
        {
            return (a.first + a.second) > (b.first + b.second);
        });
        int Max = 0;
        int sum = 0;
        for(int i =0; i < n; i++)
        {
            if(q == 0 || v[i].first + v[i].second <= Max)
            {
                break;
            }
            q--;
            sum += v[i].first + v[i].second;
            Max = max(Max,v[i].second);
        }
        sum += Max * q;
        cout << sum;
    }

//////////////////////////Prefix Sum///////////////////////
//////Bài 1: Xâu con cân bằng
// Cho một sâu nhị phân S, Đếm số lượng xâu con có số lượng số 0 = số lượng số 1
// Môt xâu có là một dãy liên tiếp các kí tự trong một xâu cho trước. Ví dụ ta có xâu marisa
// thì ris là một xâu con của marisa nhưng rsa thì ko phải
int main()
{
    string s;
    cin >> s;

    map <int, int> cnt;
    int sum = 0;
    int ans = 0;
    cnt[0] = 1;
    for(char c : s)
    {
        if(c == '1') sum++;
        else sum--;
        ans = ans + cnt[sum];
        cnt[sum]++;

    }
    cout << ans;
}

/////////Bài 2: Chia hết cho d
///Cho 1 mảng A gồm n số nguyên. Đếm số lượng mảng con có tổng chia hết cho d;
//Một mảng con là 1 chuỗi các phần tử liên tục trong mảng. ví dụ: B ={1, 2, 3, 4, 5}, mảng C ={2,3,4} là mảng con của B
int main()
{
    int n,d; cin >> n >> d;
    vector<int> v(n);
    map<int,int> cnt;
    int sum = 0;
    int ans = 0;
    cnt[0] = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++)
    {
        sum = (sum + v[i]) % d;
        if(sum < 0) sum+=d; //để khi mà sum ra số âm thì cộng lên cho thành số dương: có nghĩa là sum là số dư khi mod cho d
        /// mà nếu số dư ra âm ta cộng thêm một lượng d thì là số âm đó đồng dư với số mới vì khi 1 số mod d có thể ra từ 1->d-1
        ans += cnt[sum];
        cnt[sum]++;
    }
    cout << ans;
}

/////Bài 3: Tổng dãy con
//////Cho một mảng A độ dài n. Đếm số lượng mảng con liên tiếp có tổng bằng x;
int main()
{
    int n,x; cin >> n >> x;
    vector<int> v(n);
    map<int,int> cnt;
    int sum = 0;
    int ans = 0;
    cnt[0] = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++)
    {
        sum = sum + v[i];
        ans += cnt[sum - x];
        cnt[sum]++;
    }
    cout << ans;
}
