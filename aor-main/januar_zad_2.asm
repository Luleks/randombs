.386
.model flat, c
.data
	N dd 4
	mat dd 1, 2, 3, 10
		dd 4, 5, 6, 11
		dd 7, 8, 9, 12
		dd 13, 14, 15, 16
	niz dd 4 dup (?)
.stack 4096
.code
	max proc
		push ebp
		mov ebp, esp
		pushfd
		pushad
		mov edi, [ebp + 12]
		mov eax, [edi]
		add edi, 4
		mov ecx, [ebp + 16]
		dec ecx
		cld
		gore:
			scasd
			jae petlja
			mov eax, [edi - 4]
			petlja:
		loop gore
		mov edi, [ebp + 8]
		stosd
		popad
		popfd
		pop ebp
		ret 12
	max endp

	main proc
		mov edi, 0
		mov ecx, N
		mov eax, ecx
		shl eax, 2
		mov edx, eax
		mov ebx, 0
		gore:
			push N
			lea eax, mat[ebx]
			push eax
			lea eax, niz[edi]
			push eax
			call max
			add ebx, edx
			add edi, 4
		loop gore
		nop
		ret
	main endp
	end main