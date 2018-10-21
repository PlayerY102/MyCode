#include<cstdio>
#include<algorithm>

const int N = 1000010;
int n, m, a[N];

void qs(int dep, int l, int r) {
	int i = l, j = r, x = a[l + r + 1 >> 1];
	while(i <= j) {
		while(a[i] < x) ++i;
		while(a[j] > x) --j;
		if(i <= j) {
			std::swap(a[i], a[j]);
			i++, j--;
		}
	}
	if(l < j) qs(dep + 1, l, j);
	if(i < r) qs(dep + 1, i, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	qs(1, 1, n);
	return 0;
}