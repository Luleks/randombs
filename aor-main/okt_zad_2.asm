.386
.model flat, c
.data
	mat dd 6, 5, 4, 3
		dd 10, 9, 8, 7
		dd 2, 1, 0, -1
		dd -2, -3, -4, -5
	N dd 4
	rez dd ?
	ink dd ?
.stack 4096
.code
	suma proc
		push ebp
		mov ebp, esp
		pushfd
		push edi
		push ecx

		mov edi, [ebp + 12]
		mov ecx, [ebp + 8]
		mov eax, 0
		gore:
			add eax, [edi]
			add edi, 4
		loop gore
		
		pop ecx
		pop edi
		popfd
		pop ebp
		ret 8
	suma endp

	main proc
		push offset mat
		push N
		call suma
		mov ebx, eax
		mov rez, 0
		mov edi, 1

		mov esi, N
		shl esi, 2
		mov ink, esi

		mov ecx, N
		dec ecx
		gore:
			lea edx, mat[esi]
			push edx
			push N
			call suma
			cmp ebx, eax
			jge nista
			mov ebx, eax
			mov rez, edi
			nista:
			inc edi
			add esi, ink
		loop gore

		kraj:
		nop

	main endp
	end main
