/*
Đất nước A có n thành phố. Có m tuyến đường một chiều kết nối giữa các thành phố.
 Là thủ tướng của đất nước, bạn đảm bảo an ninh cho quốc gia của mình.
Để làm được điều này, bạn phải xây dựng các trụ sở cảnh sát. Một trụ sở ở thành phố i có thể đảm bảo an ninh cho thành phố j nếu i = j hoặc từ thành phố i có thể đi đến thành phố j rồi quay trở lại.
Xây dựng một trụ sở cảnh sát sẽ tốn một số tiền. Bạn phải xác định số tiền tối thiểu cần để xây dựng trụ sở cảnh sát sao cho an ninh được đảm bảo tại tất cả các thành phố và số cách xây dựng để đảm bảo số tiền chi ra và số trụ sở xây dựng là ít nhất.
Input
Dòng đầu tiên chứa số nguyên n — số thành phố (1 ≤ n ≤ 10^5).

Dòng tiếp theo ghi n số nguyên cách nhau bởi dấu cách.
Số nguyên thứ i là chi phí xây dựng trụ sở tại thành phố i
(chi phí không âm và không quá 10^9).

Dòng tiếp theo là số đường một chiều m (0 ≤ m ≤ 3 × 10^5).

Với m dòng tiếp theo, mỗi dòng chứa hai số nguyên u, v (1 ≤ u, v ≤ n).
Mỗi cặp u, v biểu diễn tuyến đường một chiều từ u đến v.

Output

In ra hai số nguyên cách nhau bởi dấu cách:

Số đầu tiên là số tiền tối thiểu để xây trụ sở cảnh sát sao cho đảm bảo an ninh cho tất cả các thành phố.

Số thứ hai là số cách xây dựng modulo 10^9 + 7
input:
3
2 4 6
3
2 1
3 1
1 3

output: 6 1 
*/

//BÀI NÀY HIỆN TẠI KO CÓ KHẢ THI LÀM :))))
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}