
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#define N 150010
const double pi = 3.141592653;
char s1[N>>1], s2[N>>1];
double rea[N], ina[N], reb[N], inb[N], Retmp[N], Intmp[N];
int ans[N>>1];
 
void FFT(double *reA, double *inA, int n, int flag)
{
	if(n == 1) return;
    int k, u, i;
	double reWm = cos(2*pi/n), inWm = sin(2*pi/n);
	if(flag) inWm = -inWm;
    double reW = 1.0, inW = 0.0;
	//把下标为偶数的值按顺序放前面，下标为奇数的值按顺序放后面 
	for(k = 1,u = 0; k < n; k += 2,u++){
		Retmp[u] = reA[k];
		Intmp[u] = inA[k];
	}
	for(k = 2; k < n; k += 2){
		reA[k/2] = reA[k];
		inA[k/2] = inA[k];
	}
	for(k = u,i = 0; k < n && i < u; k++, i++){
		reA[k] = Retmp[i];
		inA[k] = Intmp[i];
	}
	//递归处理 
	FFT(reA, inA, n/2, flag);
	FFT(reA + n/2, inA + n/2, n/2, flag);
	for(k = 0; k < n/2; k++){
		int tag = k+n/2;
		double reT = reW * reA[tag] - inW * inA[tag];
		double inT = reW * inA[tag] + inW * reA[tag];
		double reU = reA[k], inU = inA[k];
		reA[k] = reU + reT;
		inA[k] = inU + inT;
		reA[tag] = reU - reT;
		inA[tag] = inU - inT;
		double rew_t = reW * reWm - inW * inWm; 
		double inw_t = reW * inWm + inW * reWm; 
		reW = rew_t;
		inW = inw_t;
	}
}
 
int main()
{
#if 0
    freopen("in.txt","r",stdin);
#endif
    while(~scanf("%s%s", s1, s2)){
        memset(ans, 0 , sizeof(ans));
        memset(rea, 0 , sizeof(rea));
        memset(ina, 0 , sizeof(ina));
        memset(reb, 0 , sizeof(reb));
        memset(inb, 0 , sizeof(inb));
		//计算长度为 2 的幂的长度len 
        int i, lent, len = 1, len1, len2;
        len1 = strlen(s1);
        len2 = strlen(s2);
        lent = (len1 > len2 ? len1 : len2);
        while(len < lent) len <<= 1;
        len <<= 1;
		// 系数反转并添加 0 使长度凑成 2 的幂 
        for(i = 0; i < len; i++){
            if(i < len1) rea[i] = (double)s1[len1-i-1] - '0';
            if(i < len2) reb[i] = (double)s2[len2-i-1] - '0';
            ina[i] = inb[i] = 0.0;
        }
		//分别把向量 a, 和向量 b 的系数表示转化为点值表示
        FFT(rea, ina, len, 0);
        FFT(reb, inb, len, 0);
		//点值相乘得到向量 c 的点值表示 
        for(i = 0; i < len; i++){
            double rec = rea[i] * reb[i] - ina[i] * inb[i];
            double inc = rea[i] * inb[i] + ina[i] * reb[i];
            rea[i] = rec; ina[i] = inc;
        }
		// 向量 c 的点值表示转化为系数表示 
        FFT(rea, ina, len, 1);
        for(i = 0; i < len; i++){
            rea[i] /= len;
            ina[i] /= len;
        }
		//进位 
        for(i = 0; i < len; i++)
            ans[i] = (int)(rea[i] + 0.5);
        for(i = 0; i < len; i++){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
        int len_ans = len1 + len2 + 2;
        while(ans[len_ans] == 0 && len_ans > 0) len_ans--;
        for(i = len_ans; i >= 0; i--)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;

} 
