//퀵정렬
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t=x; x=y; y=t;}while(0)


void quick(int a[], int left, int right);
void quick_sort(int a[], int n);

int main(void)
{
	int nx, i;
	int *x;
	scanf("%d", &nx);
	x = calloc(nx+1, sizeof(int));

	for (i = 0; i < nx; i++)
		scanf("%d", &x[i]);

	quick_sort(x, nx);
	for (i = 0; i < nx; i++)
		printf("%d\n", x[i]);

	free(x);
	return 0;
}
void quick_sort(int a[], int n)
{
	quick(a, 0, n - 1);
}
void quick(int a[], int left, int right)
{
	int pl = left;	// pl : 왼쪽 끝 요소의 인덱스
	int pr = right;	// pr : 오른쪽 끝 요소의 인덱스
	int x = a[(left+right) / 2];	// x : 피벗
	
	do {
		while (a[pl] < x)pl++;
		while (a[pr] > x)pr--;
		if (pl <= pr)
		{
			swap(int, a[pl], a[pr]);
			pr--;
			pl++;
		}
	} while (pl <= pr);

	if (left < pr)
		quick(a, left, pr);
	if (pl < right)
		quick(a, pl, right);
}
	// 그룹 나누기
	// 1. a[pl]>=x 가 성립하는 요소를 찾을 때까지 pl을 오른쪽으로 옮깁니다.-> 성립하면, 멈추고 swap with a[pr]
	// 2. a[pr]<=x 가 성립하는 요소를 찾을 때까지 pr을 왼쪽으로 옮깁니다.-> 성립하면, 멈추고 swap with a[pl]
	// 3. a[pl]==x과a[pr] 이 나란히 있게댐
	// 4. 그 때 두 요소 값을 교환함 <<a[pr]==x, a[pl]>>
	// 5. 피벗 이하의 그룹(a[0]~a[pl-1])/피벗 이상의 그룹(a[pr+1]~a[n-1]) 으로 나누어짐
	// 6. 그룹 나누는 작업 끝난 뒤 pl>pr+1 이면 피벗과 일치하는 값을 가지는 그룹 : a[pr+1]~a[pl-1]
	
	// 퀵정렬
	// 나눠진 그룹을 다시 두 그룹으로 나눕니다.
	// 1. pr이 a[0]보다 오른쪽에 있으면(left < pr) 왼쪽 그룹을 나눕니다.
	// 2. pl이 a[8]보다 왼쪽에 있으면(pl < right) 오른쪽 그룹을 나눕니다.
	// 가운데 그룹a[pr+1] ~ a[pl-1] 은 나눌 필요없음
	// left<pr, pl<right 모두 그룹의 개수가 1개인 경우에는 성립하지 않는 조건
