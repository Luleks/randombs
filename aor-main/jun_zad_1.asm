.386
.model flat, c
.data
	N dd 15
	X dd 10
	p db 3
	k dd 1
	a dd 0
	b dd 0
	suma dd 0
.code
	main proc
		mov cl, p
		mov esi, 1
		shl esi, cl
		dec esi; u esi je maska kojom se sredjuje nizih p bitova
		mov cl, 32
		sub cl, p
		mov edi, esi
		shl edi, cl; u edi je maska kojom se maskira visih p bitova
	
		mov ecx, N
		gore:
			mov ebx, k
			and ebx, esi
			mov a, ebx
			mov ebx, k
			and ebx, edi
			mov b, ebx
			mov ebx, X
			sub ebx, b
			mov eax, x
			add eax, a
			mov edx, 0
			div ebx
			add suma, eax
			add k, 1
		loop gore
		nop
		ret
	main endp
	end main