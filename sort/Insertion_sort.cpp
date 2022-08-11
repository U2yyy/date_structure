#include<iostream>

void Insertion_sort(int *a,int n);

int main(){
	int a[] = {9,10,11,9,1,3};
	int n = sizeof(a)/sizeof(a[0]);
	Insertion_sort(a,n);
	for(int i = 0;i < n;i++){
		std::cout<< a[i];
	}
	return 0;
}

void Insertion_sort(int *a,int n){
	for(int p = 1;p < n;p++){
		int tmp = a[p];
		int i;
		for(i = p;p > 0 && tmp < a[i-1];i--){
			a[i] = a[i-1];
		}
		a[i] = tmp;
	}
}
