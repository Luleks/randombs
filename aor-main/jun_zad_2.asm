.386
.model flat, c
.data
	N dd 3
	mat dd 9 dup (0)
	niz dd 1, 2, 3, 4, 5, 0

.stack 4096
.code
	swap proc
		push ebp
		mov ebp, esp
		pushfd
		push esi
		push edi

		mov edi, [ebp + 8]
		mov esi, [ebp + 12]
		movsd

		pop edi
		pop esi
		popfd
		pop ebp
		ret 8
	swap endp

	main proc
		mov edx, 0
		mov ebx, 0
		mov ecx, N
		mov esi, N
		shl esi, 2
		mov edi, 0
		spolj:
			push ecx
			mov ecx, N
			mov ebx, 0
			un:
				lea eax, niz[edi]
				push eax
				lea eax, mat[ebx][edx]
				push eax
				call swap
				add edi, 4
				cmp dword ptr niz[edi], 0
				jne dalje
				mov edi, 0
				dalje:
				add ebx, esi
			loop un
			pop ecx
			add edx, 4
		loop spolj
		nop

		ret
	main endp
	end main