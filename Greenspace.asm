.include "Header.inc"
.include "Snes_Init.asm"

; Needed to satisfy the interrupt definition in header.inc.
VBlank:
	rti

.bank 0
.section "MainCode"

Start:
	Snes_Init

	; Set background color to green.
	sep 	#$20
	lda 	#%10000000
	sta 	$2100
	lda 	#%11100000	; Green low byte
	sta 	$2122
	lda 	#%00000000	; Green high byte
	sta 	$2122
	lda 	#%00001111
	sta 	$2100

Forever:
	jmp 	Forever

.ends