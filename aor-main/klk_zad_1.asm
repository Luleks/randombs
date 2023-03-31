.386
.model flat, c
.data
	niz dd 44, 55, 12, 42, 94, 18, 6, 67, 0
	n dd 9
	suma dd ?
.code
	main proc
		mov esi, 0
		mov eax, 0
		mov ecx, n
		mov bl, 0
		gore:
		cmp bl, 0
		je poredjenje
		add eax, niz[esi]
		jmp petlja
		poredjenje:
		cmp niz[esi], 0
		jne petlja
		inc bl
		petlja:
		add esi, type niz
		loop gore
		mov suma, eax
	ret
	main endp
	end main