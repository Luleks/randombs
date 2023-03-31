.386
.model flat, c
.data
	mat dd 1, 2, 3, 4
		dd 5, 6, 7, 8
		dd 9, 10, 11, 12
		dd 13, 14, 15, 16

	N dd 4
.stack 4096
.code
	uporedi proc
		push ebp
		mov ebp, esp
		pushfd
		push ebx

		mov eax, [ebp + 8]
		mov ebx, [ebp + 4]

		cmp eax, ebx
		je jednaki
		jg prvi
		mov eax, 1
		jmp kraj
		prvi:
		mov eax, 2
		jmp kraj
		jednaki:
		mov eax, 0

		kraj:
		pop ebx
		popfd
		pop ebp
		ret 8
	uporedi endp
	main proc
		mov edi, N
		shl edi, 2
		mov ebx, 0

		mov ecx, N
		dec ecx
		spp:
			push ecx
			mov ecx, N
			mov esi, 0
			unp:
				lea edx, mat[ebx][esi]
				push [edx]
				add edx, edi
				push [edx]
				call uporedi
				cmp eax, 1
				jne dalje
				mov eax, [edx]
				mov mat[ebx][esi], eax
				dalje:
				add esi, type mat
			loop unp
			pop ecx
			add ebx, edi
		loop spp
		kraj:
		nop
		ret
	main endp
	end main

