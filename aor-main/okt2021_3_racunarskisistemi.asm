.386
.model flat, c
.data
	mat dw 2, 1, 2, 1, 1
		dw 9, 5, 7, 5, 9
		dw 2, 6, 7, 8 ,4
		dw 2, 6, 7, 8, 4
		dw 3, 3, 7, 3, 3
	N dd 5
	rez dd ?
.code
	main proc
		mov ecx, -1
		mov edx, 0

		mov eax, N
		shl eax, 1
		mov ebx, 0

		goregore:
		cmp edx, 1
		je kraj
		inc ecx
		cmp ecx, N
		je kraj

			mov esi, 0
			mov edi, eax
			sub edi, 2
			push eax


			gore:
			cmp esi, edi
			jae dalje
			mov ax, mat[ebx][edi]
			cmp ax, mat[ebx][esi]
			jne dalje
			add esi, 2
			sub edi, 2
			jmp gore
			dalje:
			cmp esi, edi
			jb ispod
			inc edx
			ispod:
			pop eax
			add ebx, eax
		jmp goregore
		kraj:
		cmp edx, 1
		jne nula
		mov rez, ecx
		jmp nope
		nula:
		mov rez,0
		nope:
		nop
		ret
	main endp
	end main