.386
.model flat, c
.data
	mat dd 100, 1, 2, 3
		dd 20, 2, -3, 5
		dd 10, 2, 3, -5
		dd 10, 2, 3, 4
	N dd 4
	rez dd ?
.stack 4096
.code
	suma proc
		push ebp
		mov ebp, esp
		pushfd
		push ecx
		push edi

		mov eax, 0
		mov ecx, [ebp + 8]
		mov edi, [ebp + 12]

		gore:
			add eax, [edi + (type mat * ecx - type mat)]
		loop gore

		pop edi
		pop ecx
		popfd
		pop ebp
		ret 8
	suma endp
	
	main proc
		mov ebx, 0
		mov ecx, 1
		mov edx, 0

		mov eax, N
		mul N
		mov esi, eax ;u esi je inc

		shl eax, 2
		mov edi, eax
		sub edi, esi

		pocetak:
		cmp ecx, 0
		je testic
		cmp ebx, edi
		je testic

		lea eax, mat[ebx]
		push eax
		push N
		call suma

		sub eax, mat[ebx]
		cmp mat[ebx], eax
		jle nadjeno

		add ebx, esi
		inc edx
		jmp pocetak

		nadjeno:
		mov ecx, 0
		mov rez, edx 
		jmp pocetak

		testic:
		cmp ecx, 0
		je kraj
		mov rez, 0
		kraj:
		nop
		ret
	main endp
	end main