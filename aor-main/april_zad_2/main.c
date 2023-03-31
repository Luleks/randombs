#include <stdio.h>
#include <stdlib.h>

extern int kopiraj(short*, short*, int);

void main() {
	int n, m, i, j, dim;
	short* mat, *niz;
	scanf("%d%d", &n, &m);
	mat = (short*)malloc(n * m * sizeof(short));
	niz = (short*)malloc(n * m * sizeof(short));

	for (i = 0; i < n * m; i++) {
		scanf("%hi", &mat[i]);
	}	
	
	dim = kopiraj(mat, niz, n * m);
	for (i = 0; i < dim; i++)
		printf("%hi ", niz[i]);
}