#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

using namespace std;

#define random(x) (rand()%x)

int main (){
	int a,b,c,d,i;
	int s1,s2,t;
	srand((unsigned)time(0));
	for(i=0;i<30;i++){
		a=random(100)+1;
		b=random(100)+1;
		c=random(100)+1;
		s1=random(4)+1;
		s2=random(4)+1;
		printf("��%d��: ",i+1);
		switch(s1) {
			//��һ������Ϊ+ʱ����� 
			case 1:
			switch(s2){
			case 1:
			while((d=a+b+c)>100){				
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d+%d+%d=\n",a,b,c);
			break;
			case 2:
			while((a+b)<=c||(d=a+b-c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d+%d-%d=\n",a,b,c);
			break;
			case 3:
			while((d=a+b*c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d+%d��%d=\n",a,b,c);
			break;
			case 4:
			while(b%c!=0||(d=a+b/c>100)){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d+%d��%d=\n",a,b,c);
			break;
			}
			break;
			//��һ������Ϊ���ŵ���� 
			case 2:
				switch(s2){
			case 1:
			while(a<b||(d=a-b+c)>100){				
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d-%d+%d=\n",a,b,c);
			break;
			case 2:
			while(a<b||(a-b)<c||(d=a-b-c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d-%d-%d=\n",a,b,c);
			break;
			case 3:
			while(a<b*c||(d=a-b*c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d-%d��%d=\n",a,b,c);
			break;
			case 4:
			while(b%c!=0||a<b/c||(d=a-b/c>100)){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d-%d��%d=\n",a,b,c);
			break;
			}
			break;
			//��һ��������x����� 
			case 3:
			switch(s2){
			case 1:
			while((d=a*b+c)>100){				
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d+%d=\n",a,b,c);
			break;
			case 2:
			while((a*b)<c||(d=a*b-c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d-%d=\n",a,b,c);
			break;
			case 3:
			while((d=a*b*c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d��%d=\n",a,b,c);
			break;
			case 4:
			while(a*b%c!=0||(d=a*b/c>100)){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d��%d=\n",a,b,c);
			break;
			}
			break; 
			//��һ��������/�����
			case 4:
			switch(s2){
			case 1:
			while(a%b!=0||(d=a/b+c)>100){				
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d+%d=\n",a,b,c);
			break;
			case 2:
			while(a%b!=0||(a/b)<=c||(d=a/b-c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d-%d=\n",a,b,c);
			break;
			case 3:
			while(a%b!=0||(d=a/b*c)>100){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d��%d=\n",a,b,c);
			break;
			case 4:
			while(a%b!=0||a/b%c!=0||(d=a/b/c>100)){
				a=random(100)+1;
				b=random(100)+1;
				c=random(100)+1;
			}printf("%d��%d��%d=\n",a,b,c);
			break;
			}
			break; 
		}
	}
	return 0;
}

