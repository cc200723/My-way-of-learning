/*经过笔算可以得到：
 A==105-3*B 
 C==2B
 故A+B+C==105
 即第三笔订单需要返积分105 
*/ 

// author chen boshuo
// 积分之谜
#include <stdio.h>

int main() {
  int a, b, c;  // 假定三个数积分为整数
  for (int a = 0; a < 320; ++a) {
    for (int b = 0; b < 300; ++b) {
      for (int c = 0; c < 315; ++c) {
        if (3 * a + 7 * b + c == 315 && 4 * a + 10 * b + c == 420) {
          printf("%d\n", a + b + c);
          return 0;  // 在添加之前发现解空间只有唯一解，故直接返回
        }
      }
    }
  }
  return 0;
}
