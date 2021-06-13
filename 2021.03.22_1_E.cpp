//��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ������������
//
//��ʾ��
//��������ǳ���Ϊ 32 �� �����ƴ� ��
//
//���ף�
//�����ε�������������㽫����Ż�����㷨��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/number-of-1-bits
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


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
