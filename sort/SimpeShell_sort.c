#include<stdio.h>

void Shell_sort(int *a,int n);

int main(){
	int a[] = {0,99,19,20,88,22,31,23};
	int n = sizeof(a) / sizeof(a[0]);
	Shell_sort(a,n);
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}

void Shell_sort(int *a,int n){
	for(int p = n/2;p >=1;p /= 2){
		for(int q = 1;q < n;q += p){
			int tmp = a[q];
			int i;
			for(i = q;i >= 0&&tmp < a[i-1];i--){
				a[i] = a[i-1];
			}
			a[i] = tmp;
		}
	}
}
