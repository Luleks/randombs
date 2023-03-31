.386
.model flat, c
.data
.stack 4096
.code
	public Ponavljanje
	Ponavljanje proc
		push ebp
		mov ebp, esp
		pushfd
		push edi
		push esi

		mov edi, [ebp + 8]
		mov eax, 1
		mov esi, edi
		inc esi
		gore:
			cmpsb
			jne kraj
			inc eax
			dec edi
		jmp gore
		kraj:
		pop esi
		pop edi
		popfd
		pop ebp
		ret
	Ponavljanje endp
	end