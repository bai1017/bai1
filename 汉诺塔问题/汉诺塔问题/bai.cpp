#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void move_(char x,char y) {
	printf("��һ��Բ�̴�%c�����Ƶ�%c����\n",x, y);
}
void res(char A,char B,char C,int n) {
	if (n != 1) {
		res(A, C, B, n - 1);
		move_(A, C);
		res(B, A, C, n - 1);
	}
	else {
		move_(A, C);
	}
}
int ca(int n) {
	if (n != 1) {
		int x = 0;
		return 2*ca(n-1)+1;
	}
	else {
		return 1;
	}
}
int main() {
	int n = 0;
	int y = 0;
	char A='A';
	char B='B';
	char C='C';
	scanf("%d",&n);
	y=ca(n);
	res(A, B, C, n);
	printf("һ����Ҫ%d��", y);
	return 0;
}