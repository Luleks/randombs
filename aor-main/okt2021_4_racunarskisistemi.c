#include <stdio.h>
#include <stdlib.h>

int razlika(char* niz, int N) {
	_asm {
		mov esi, niz
		mov ecx, N
		xor ebx, ebx
		gore:
			cmp byte ptr[esi], 'a'
			je ink
			cmp byte ptr[esi], 'e'
			je ink
			cmp byte ptr[esi], 'i'
			je ink
			cmp byte ptr[esi], 'o'
			je ink
			cmp byte ptr[esi], 'u'
			je ink
			jmp nema
			ink:
			inc ebx
			nema:
			inc esi
		loop gore
		mov eax, N
		sub eax, ebx
		sub eax, ebx
	}
}

void main() {
	char** mat;
	int* niz, i, j, N;
	scanf("%d", &N);
	mat = (char**)malloc(N * sizeof(char*));
	for (i = 0; i < N; i++)
		mat[i] = (char*)malloc(N * sizeof(char));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			getchar();
			scanf("%c", &mat[i][j]);
		}
	niz = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
		niz[i] = razlika(&mat[i][0], N);
	for (i = 0; i < N; i++)
		printf("%d ", niz[i]);
	for (i = 0; i < N; i++)
		free(mat[i]);
	free(mat);
	free(niz);
}