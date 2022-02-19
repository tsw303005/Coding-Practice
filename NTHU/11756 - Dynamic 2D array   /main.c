#include<stdio.h>
#include"function.h"
unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}
int main(){
	int n,m,k,_;
	scanf("%d%d%d%u",&_,&n,&m,&random_seed);
	while(_--){
		unsigned **arr=new_2d_array(n,m);
		int i,j;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				arr[i][j]=Random();
			}
		}
		for(i=0;i<5;++i){
			unsigned a,b;
			a=Random()%n;
			b=Random()%m;
			if(i)putchar(' ');
			printf("%u",arr[a][b]);
		}
		puts("");
		delete_2d_array(arr);
	}
	return 0;
}

