#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int q, p, l, r;
    int a[50][2], b[50][2];
//    int c[1000] = {0};
    int total;
    while (cin >> q >> p >> l >> r) {
        total = 0;
        int c[1000] = {0};
        for (int i = 0; i < q; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        for (int i = 0; i < p; i++) {
            cin >> b[i][0] >> b[i][1];
        }
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < q; j++) {
                for (int k = 0; k < p; k++) {
                    if ((b[k][0] + i <= a[j][0] && b[k][1] + i >= a[j][0]) ||
                        (b[k][0] + i <= a[j][1] && b[k][1] + i >= a[j][1]) ||
                        (b[k][0] + i <= a[j][0] && b[k][1] + i >= a[j][1]) ||
                        (b[k][0] + i >= a[j][0] && b[k][1] + i <= a[j][1]))
                        c[i] = 1;
                }
            }
            total += c[i];
        }
        cout << total << endl;
    }

    return 0;
}



/*
A��B�Ǻ��ѣ����Ǿ����ڿ���ʱ�����죬A�Ŀ���ʱ��Ϊ[a1 ,b1 ],[a2 ,b2 ]..[ap ,bp ]��B�Ŀ���ʱ����[c1 +t,d1 +t]..[cq +t,dq +t],����tΪB����ʱ�䡣��Щʱ������˱߽�㡣B����ʱ��Ϊ[l,r]��һ��ʱ�̡���һ����ʱ����ʹ����������ʱ�����죬��ô���ʱ����Ǻ��ʵģ����ж��ٸ����ʵ���ʱ�䣿

��������:
��һ�������ĸ�������p,q,l,r��1��p,q��50,0��l��r��1000)��������p������ÿһ����һ������ai��bi(0��aii+1>bi,ci+1>di


�������:
����𰸸���

��������:
2 3 0 20
15 17
23 26
1 4
7 11
15 17

�������:
20
*/
