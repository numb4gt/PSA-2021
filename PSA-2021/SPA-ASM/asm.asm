.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/SPA_Lib.lib
ExitProcess PROTO : DWORD
_convert PROTO : DWORD
_strln PROTO : DWORD
_out PROTO : DWORD
_outbool PROTO : DWORD
_outpint PROTO : DWORD


.stack 4096
.const
	_DIVISION_BY_ZERO_ERROR BYTE 'Деление на ноль запрещено', 0
	_OVERFLOW_ERROR BYTE 'Переполнение', 0
	L0 BYTE 'Arefmetic:', 0
	L1 DWORD -897
	L2 DWORD 89
	L3 DWORD 17
	L4 DWORD -10
	L5 DWORD 45
	L6 DWORD 234
	L7 DWORD 34
	L8 DWORD 45
	L9 BYTE 'If-Else:', 0
	L10 DWORD 10
	L11 BYTE 'zb more then zc', 0
	L12 BYTE 'zc more then zb', 0
	L13 DWORD 45
	L14 DWORD 25
	L15 DWORD 7
	L16 BYTE 'bless', 0
	L17 BYTE '1234567890', 0
	L18 DWORD 5
	L19 DWORD 1
	L20 DWORD 0
.data
	_arefmza		DWORD 0 ; int
	_arefmzb		DWORD 0 ; int
	_arefmzc		DWORD 0 ; int
	_arefmzk		DWORD 0 ; int
	_arefmg		DWORD 0 ; int
	_arefmz		DWORD 0 ; int
	_mainxa		DWORD 0 ; int
	_mainya		DWORD 0 ; int
	_mainza		DWORD 0 ; int
	_maindf		DWORD 0 ; int
	_maindc		DWORD 0 ; int
	_mainca		DWORD 0 ; str
	_maincb		DWORD 0 ; str
	_maincc		DWORD 0 ; str
	_scope_2x		DWORD 0 ; int

.code
_arefm PROC _arefmy: DWORD, _arefmx: DWORD
	push		offset L0
	call		_out

	push		L1
	pop			_arefmza

	push		L2
	pop			_arefmzb

	push		L3
	pop			_arefmzc

	push		_arefmza
	push		_arefmzc

	pop		ebx
	pop		eax
	test		ebx, ebx
	jz		EXIT_DIV_ON_NULL
	cdq
	idiv		ebx
	jo		EXIT_OVERFLOW
	push		edx

	push		_arefmzb

	pop		ebx
	pop		eax
	imul		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	pop			_arefmzk

	push		_arefmzk
	call		_outpint

	push		_arefmx
	push		_arefmy

	pop		ebx
	pop		eax
	sub		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	push		L4

	pop		ebx
	pop		eax
	sub		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	pop			_arefmz

	push		_arefmz
	call		_outpint

	push		_arefmy
	push		L5

	pop		ebx
	pop		eax
	imul		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	push		L6
	push		_arefmx
	push		_arefmx
	push		_arefmy

	pop		eax
	pop		ebx
	add		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax


	pop		ebx
	pop		eax
	imul		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax


	pop		ebx
	pop		eax
	test		ebx, ebx
	jz		EXIT_DIV_ON_NULL
	cdq
	idiv		ebx
	jo		EXIT_OVERFLOW
	push		eax

	push		_arefmx
	push		_arefmy

	pop		eax
	pop		ebx
	add		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax


	pop		ebx
	pop		eax
	test		ebx, ebx
	jz		EXIT_DIV_ON_NULL
	cdq
	idiv		ebx
	jo		EXIT_OVERFLOW
	push		eax

	push		L7

	pop		ebx
	pop		eax
	imul		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	push		L8

	pop		ebx
	pop		eax
	test		ebx, ebx
	jz		EXIT_DIV_ON_NULL
	cdq
	idiv		ebx
	jo		EXIT_OVERFLOW
	push		eax


	pop		eax
	pop		ebx
	add		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	pop			_arefmz

	push		_arefmza
	pop			_arefmzk

	push		_arefmzk
	call		_outpint

	push		_arefmz
	call		_outpint

	push		offset L9
	call		_out

	push		L10
	push		_arefmzb
	pop		ebx
	pop		eax
	cmp		eax, ebx
	ja		FALSE22
	jb		TRUE22
TRUE22: 
	push		offset L11
	call		_out

	jmp		IFOUT22
FALSE22: 
	push		offset L12
	call		_out

IFOUT22: 


	jmp EXIT
EXIT_DIV_ON_NULL:
	push offset _DIVISION_BY_ZERO_ERROR
	call _out
	push -1
	call ExitProcess

EXIT_OVERFLOW:
	push offset _OVERFLOW_ERROR
	call _out
	push -2
	call ExitProcess

EXIT:
	mov		eax, _arefmz
	ret		8
_arefm ENDP

main PROC
	push		L13
	pop			_mainxa

	push		L14
	pop			_mainya

	push		L15
	pop			_maindf

	push		_mainxa
	push		_maindf
	call		_arefm
	push		eax
	pop			_mainza

	push		_mainza
	call		_outpint

	push		offset L16
	pop			_mainca

	push		offset L17
	pop			_maincb

	push		_mainca
	call		_out

	push		_maincb
	call		_out

	push		_maindf
	call		_outpint

	push		_maincb
	call		_strln
	push		eax
	push		L18

	pop		eax
	pop		ebx
	add		eax, ebx
	jo		EXIT_OVERFLOW
	push		eax

	pop			_maindc

	push		_maindc
	call		_outpint

	push		_mainxa
	push		_mainya
	pop		ebx
	pop		eax
	cmp		eax, ebx
	jna		FALSE51
	push		L19
	pop			_scope_2x

FALSE51: 


	jmp EXIT
EXIT_DIV_ON_NULL:
	push offset _DIVISION_BY_ZERO_ERROR
	call _out
	push -1
	call ExitProcess

EXIT_OVERFLOW:
	push offset _OVERFLOW_ERROR
	call _out
	push -2
	call ExitProcess

EXIT:
	push		L20
	call		ExitProcess

main ENDP
end main
