#include<bits/stdc++.h>
#include<iostream>
using namespace std;
///////CHUYỂN SỐ NGUYÊN THÀNH XÂU NHỊ PHÂN///////////////
int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        vector<int>v;
        while(n)
         {
            v.push_back(n%2);
            n = n / 2;
         }
         reverse(v.begin(),v.end());
        for(int x : v)
        {
            cout << x;
        }
    }
    
}

////////////CHO SỐ N TÌM TẤT CẢ CÁC XÂU NHỊ PHÂN ĐỘ DÀI N//////////////
int a[21]; int n;
void backtrack(int pos)
{
    if(pos == n + 1)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout <<'\n';
        return;
    }
    a[pos] = 0;
    backtrack(pos+1);
    a[pos] = 1;
    backtrack(pos+1);
}
int main()
{   
    cin >> n;
    backtrack(1);

}


/////////Hoán Vị///////////
int a[10], n;
int d[10]; // mảng dùng đánh dấu đã sử dụng phần tử đó chưa
void backtrack(int pos)
{

    if(pos == n + 1)
    {
        for(int i = 1; i <=n; i++) cout << a[i];
        cout <<'\n';
        return;
    }
    for(int i = 1; i<=n; i++)
    {
      if(d[i] == 0)  
      { a[pos] = i;
       d[i] = 1;
       backtrack(pos+1); 
       d[i] = 0;
    }
 }
}

int main()
{
    cin >> n;
    backtrack(1);
}



//////// MỘT CÁCH HOÁN VỊ KHÁC //////////
//chỉ có tác dụng khi mãng a[] dc sắp theo thứ tự từ bé đến lớn chứ sắp lộn xộn thì k dc
// và có thể dùng cho hoán vị nhiều phần tử giống nhau ví dụ a[1] = 1; a[2] = 1; a[3] = 2;,...
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
        {
            a[i] = i;
        }
    do{
        for(int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << '\n';
    }while(next_permutation(a+1, a + n + 1));   
}
/////TẬP CON//////////////////
//cho mãng A có n phần tử. Hãy xác định xem có tồn tại một tập con của A mà có tổng bằng K ko
//input n,k và n số Ai;
// ví dụ n = 4, k = 7;
// a[i] = {1,2,3,4} thì sẽ in ra 3 4 và 1 2 4 vì tổng nó = 7
//hướng làm bài này sử dụng backtrack nhị phân để tự in ra các trường hợp có thể và đánh dấu nó nếu = 1 thì chọn = 0 thì ko chọn
// rồi xét xem tổng có = k ko thì in ra;

int a[20]; // mãng cần nhập ai;
int k,n;
int b[20]; // mãng sinh ra số nhị phân và đánh dấu có chọn phần tử hay ko;
void backtrack(int pos)
{
    if(pos == n)
    {
        long long s = 0;
        for(int i = 0; i < n; i++)
        {
            if (b[i] == 1)
            {
                s += a[i];
                if(s > k) return;
            }
        }
        if(s == k)
            {
                for(int i = 0; i < n; i++)
                {
                    if(b[i] == 1)
                    {
                        cout << a[i] << " ";
                    }
                }
                cout << '\n';
            }
            return;
    }

    for(int i = 0; i < 2; i++)
    {
        b[pos] = i;
        backtrack(pos + 1); 
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    backtrack(0);
    
}

//////////////////a MŨ b///////////////////////
// cho q truy vấn, mỗi truy vấn gồm số nguyên a, b, tính a^b mod 10^9 + 7. giả  sử 0^0 = 1;
#define mod 1000000007
int a,b,q;
/// VỀ SAU DÙNG HÀM POW THÌ GHI KIỂU NÀY SẼ NHANH HƠN VÀ BỎ % MOD;
int Pow(int a, int b)
{
    if(b == 0) return 1;
    int temp = Pow(a,b/2);
    temp = temp * temp % mod; // nếu n chẵn thì temp * temp tức (2,2) thì 2 * 2 còn n lẽ thì nhân thêm a.
    if(b % 2 != 0) 
    {
        temp = temp * a;
    }
    return temp;
}
 // hàm main lười ghi quá 

 ////////////////////TRÀN SỐ//////////////////
 // tính a * b mod c . Chú ý a * b có thể vượt quá kiểu dữ liệu long long là 10 mũ 18;
 // cách làm là như pow ở trên a * b = a *b/2 + a *b/2 nếu chẵn còn lẽ thì + a
 int c;
 long long Nhan(long long a, long long b)
 {
    if(b == 0) return 0;
    long long temp = Nhan(a,b/2);
    temp = temp + temp;
    if(b % 2 != 0) temp = temp + a;
    return temp % c;
 }
 
 ////////////////TẬP CON/////////////////
 // Liệt kê các tập con có độ dài k của tập S = {1,2,...n};
 //input: 1 dòng gồm số nguyên n và k
int a[20],k,n;
void backtrack(int pos, int prev) // prev dùng để biến mãng lúc nào cũng tăng dần ko có trùng lập
{
    if(pos == k)
    {
        for(int i = 0; i < k; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = prev + 1; i <= n; i++)
    {
        a[pos] = i;
        backtrack(pos+1,i);
    }
}

//////////CÁI TÚI/////////////////
//CÓ N món đồ, món thứ i có cân nặng w và giá trị vi.Bạn có thể chọn số lượng món đồ tùy ý
//miễn cân nặng không quá S.Tìm cách chọn đồ để có giá trị lớn nhất.
//input: dòng đầu gồm 2 số nguyên n , S. n dòng tiếp theo gồm 2 số nguyên wi và vi.


int n, S;
int w[25], v[25];
int d[25];
int ans = 0;
void backtrack(int pos)
{
    if(pos == n)
    {   int W = 0, V = 0;
        for(int i = 0; i < n; i++)
        {
            if(d[i] == 1)
            {
                W += w[i];
                V += v[i]; 
            }
        }
         if(W <= S)
        {
            ans = max(ans,V);
            return;
        }
    }
    for(int i = 0; i < 2; i++)
    {
        d[pos] = i;
        backtrack(pos+1);
    }
}



////////////BÀI N QUÂN XE/////////
// mỗi quân xe chỉ có thể đc đặt ở 1 cột và hàng. tim tất cả các cách đặt quân xe dùng backtracking
int board[20][20]; // hàng cột
int n,cot[20]; // cot[20] dùng để đánh dấu cột đã được sử dụng  chưa
void backtrack(int row) // row này đánh dấu hàng dc sử dụng chưa;
{
    if(row == n) // n là số quân xe cần đặt và là kích thường bàn cờ
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                {
                    cout << 'X';
                }
                else cout << '.';
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n;i++)
    {
        if(cot[i] == 0)
        {
            board[row][i] = 1;
            cot[i] = 1;
            backtrack(row + 1);
            board[row][i] = 0;
            cot[i] = 0;
        }
    }
}


////////////BÀI N QUÂN HẬU/////////////////
/// quân hậu y như quân xe nhưng có đường chéo sẽ bị ko được đặt
// nhưng mà đường chéo thì có đường chéo chính và chéo phụ nhé.
// chéo chính = row - col
// chéo phụ = row + col
// giải thích chéo chính chéo phụ: vì khi bạn vẽ ra thì các vị trí chéo chính khi trừ nhau lun bằng nhau
// phụ cũng vậy
// ví dụ : 0;1    0;2      0;3
////////// 1;1    1;2      1;3
//chéo chính là 01 và 12; thì 0-1 = -1 và 1-2 = -1 lun bằng nhau nên ta đánh dấu và bên phụ cũng vậy
//lưu ý khi đánh dấu lỡ như chéo chính trừ với nhau ra âm nên mảng sẻ ko đánh dấu số âm được
// vì thế ta cộng thêm 1 lượng bất kỳ để thành số dương và đa số là cộng thêm n để vừa khít;



int board[20][20];
int n,cot[20];
int cheochinh[40],cheophu[40]; // ~~ 2*n;
void backtrack(int row)
{
    if(row == n) //n = số lượng quân hậu cần đặt; và là kích thước bàn cờ
    {
        for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(board[i][j] == 1)
                    {
                        cout << 'X';
                    }
                    else cout << '.';
                }
                 cout << '\n';
            }
            cout << '\n'; return;
    }
    for(int i = 0; i < n; i++)
    {
        if(cot[i] == 0 && cheochinh[row - i + n] == 0 && cheophu[row + i] == 0)
        {
            board[row][i] = 1;
            cot[i] = 1;
            cheochinh[row -i + n] = 1;
            cheophu[row + i] = 1;
            backtrack(row + 1);
            board[row][i] = 0;
            cot[i] = 0;
            cheochinh[row -i + n] = 0;
            cheophu[row + i] = 0;
        }
    }
}

////////////////////QUÂN MÃ ĐI TUẦN////////////////////////////
int n,m, board[7][7];
int dx[] = {-2,-2,2,2,1,1,-1,-1}; /// quân mã đi được x = +-2; +-1 kết hợp với y = +-1; +-2
int dy[] = {-1,1,-1,1,2,-2,2,-2};

void backtrack(int count, int x, int y) //x là hàng y là cột
{
    if(count == n * m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    for(int i = 0; i < 8;i++)
    {
        int nx =x + dx[i];
        int ny =y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] == 0)
        {   
            board[nx][ny] = count + 1;
            backtrack(count+1,nx,ny);
            board[nx][ny] = 0;

        }
    }
}


///////////////LẬP LỊCH////////////////
///////////// tao muốn đóng chai n lọ thuốc, mỗi lọ thuốc mất Ai giây để đổ đầy và Bi giây để dán nhãn.
////Một lọ thuốc cần đc đổ đầy trước khi dán nhãn. Tao có 2 chiếc máy, một để đổ thuốc vào lọ, 1 để dán nhãn
//// mỗi máy chỉ có thể xử lý tuần tự từng lọ. T cần biết cần ít nhất bn tgian để đóng chai hết n lọ.
int main()
{
    int n; cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    long long ans = LLONG_MAX;
    do
    {
        long long do_day = 0, dan_nhan = 0;// tgian do day và tgian dán nhãn
        for(int i = 0; i < n; i++)
        {
            do_day = do_day + a[i].first;
            dan_nhan = max(dan_nhan,do_day) + a[i].second;
        }
        ans = min(ans,dan_nhan);
    }
    while(next_permutation(a.begin(),a.end()));
    cout << ans;
}

