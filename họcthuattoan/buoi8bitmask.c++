#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//// CÁC TOÁN TỬ BITWISE : & | ^ ! ~

// x  | y  | x & y | x l y | x ^ y (phép xor: x và y có khác nhau hay không) 
// 0    0      0       0       0 
// 0    1      0       1       1 
// 1    0      0       1       1 
// 1    1      1       1       0 
// a ^ b = c
// b = a ^ c
// Phép dịch bit: x << i || x >> i
/// nếu dịch trái (x << i) sang i lần thì số gốc sẽ nhân = 1 lượng 2^i; 
// muốn in ra 1 số 2 mũ i nhanh gọn thì cứ (1 << i);
/// nếu dịch phải (x >> i) sang i lần thì sẽ bằng số gốc chia cho 2^i lần lấy phần nguyên;
///Bật bit: nếu muốn bật bit thứ i của n thì n = n | (1 << i)
///Đảo bit: nếu muốn đảo bit thứ i của n từ 0 thành 1 hoặc từ 1 thành 0 thì n = n ^ (1 << i)
///Tắt bit: nếu muốn tắt bit thứ i của n thì n = n & (~(1 << i))
///Để kiểm tra bit thứ i bật hay tắt thì: (n >> i) & 1;
///

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// BITMASK -> ĐỆ QUY SINH XÂU NHỊ PHÂN
//// BITSET -> STL TRONG C++
