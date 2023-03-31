.386
.model flat, c
.data
.stack 4096
.code
	public kopiraj
	kopiraj proc
		push ebp
		mov ebp, esp
		pushfd
		push esi
		push edi
		push ebx
		push ecx

		cld
		mov edi, [ebp + 8]
		mov esi, [ebp + 12]
		mov ebx, 0
		mov eax, 0
		mov ecx, [ebp + 16]

		gore:
			mov dx, [edi]
			scasw
			jle petlja
			sub edi, 2
			xchg edi, esi
			movsw
			xchg edi, esi
			inc ebx
			petlja:
		loop gore
		mov eax, ebx

		pop ecx
		pop ebx
		pop edi
		pop esi
		popfd
		pop ebp
		ret
	kopiraj endp
	end