#include <cstdio>
#define MAXT 101

const int maxn = 1e5 + 10;
int a[MAXT], b[MAXT];
int ca[MAXT], cb[MAXT];
int x[maxn], y[maxn];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	for (int i=0; i<n; ++i) scanf("%d", y+i);
	for (int i = 0; i < n; i++){
		a[x[i]]++;
		b[y[i]]++;

		for (int j = 0; j < MAXT; j++){
			ca[j] = a[j];
			cb[j] = b[j];
		}

		int sol = 0;

		int ap = MAXT - 1;
		int bp = 1;

		while ( ap > 0 && bp < MAXT ){
			while ( ap > 0 && !ca[ap] ) ap--;
			while ( bp < MAXT && !cb[bp] ) bp++;

			if ( ap == 0 || bp == MAXT ) break;

			if ( ap + bp > sol ) sol = ap + bp;

			if ( ca[ap] > cb[bp] ){
				ca[ap] -= cb[bp];
				cb[bp] = 0;
			}
			else {
				cb[bp] -= ca[ap];
				ca[ap] = 0;
			}
		}

		printf("%d\n", sol);
	}
	return 0;

}

