.386
.model flat, c
.data
	N dd 5
	mat dd 1, 2
		dd 3, 4
		dd 5, 6
		dd 7, 8
		dd -1, -2
	niz dd 5 dup (?)
.stack 4096
.code
	max proc
		push ebp
		mov ebp, esp
		pushfd
		pushad
		mov esi, [ebp + 8]
		cmp eax, edx
		jg ispod
		mov [esi], edx
		jmp kraj
		ispod:
		mov [esi], eax
		kraj:
		popad
		popfd
		pop ebp
		ret 4
	max endp

	main proc
		mov ebx, 0
		mov ecx, N
		mov edi, 0
		gore:
			lea eax, niz
			add eax, edi
			push eax
			mov eax, mat[ebx][0]
			mov edx, mat[ebx][4]
			call max
			add ebx, 8
			add edi, 4
		loop gore
		nop
		ret
	main endp
	end main