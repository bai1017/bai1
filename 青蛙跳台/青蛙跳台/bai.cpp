#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int number(int n) {
	if (n>3) {
		return number(n - 1) + number(n - 2);
	}
	else {
		return n;
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int x=number(n);
	printf("%d\n", x);
	return 0;
}