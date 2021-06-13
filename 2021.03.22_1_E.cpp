//编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
//
//提示：
//输入必须是长度为 32 的 二进制串 。
//
//进阶：
//如果多次调用这个函数，你将如何优化你的算法？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-1-bits
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
using namespace std;

class mySolution {
public:
    int hammingWeight(uint32_t n) {
        int index = 0;
        for (int i = 0; i < 32; i++) {
            if (n % 2)
                index += 1;
            n = n / 2;
        }
        return index;
    }
};

class bestSolution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};

//void main() {
//    uint32_t n = 00000000000000000000000000001011;
//    mySolution mytest;
//    cout << mytest.hammingWeight(n) << endl;
//}
