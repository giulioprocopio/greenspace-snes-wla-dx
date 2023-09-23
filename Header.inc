.MEMORYMAP ; System architecture
	SLOTSIZE 	$8000	; The slot is $8000 bytes long
	DEFAULTSLOT 	0
	SLOT 	0	$8000	; Slot 0 starting address
.ENDME

.ROMBANKSIZE $8000 ; Every ROM bank is 32 KBytes in size
.ROMBANKS 8 ; 2 Mbits -- tell WLA we want to use 8 ROM banks

.SNESHEADER
	ID 	"SNES"	; 1-4 letter string, just leave it as "SNES"

	NAME 	"SNES Project Template"	; Program title, can't be longer than 21
	; characters.  "123456789012345678901": use spaces for unused characters.

	SLOWROM
	LOROM

	; For more options, see WLA docs.
	CARTRIDGETYPE 	$00	; $00 = ROM only
	ROMSIZE 	$08	; $08 = 2 Mbits
	SRAMSIZE 	$00	; No SRAM
	COUNTRY 	$00	; $01 = U.S., $00 = Japan, $02 = Australia, Europe, Oceania
	; Holland, $08 = Spain, $09 = Germany, and Asia, $03 = Sweden, $04 = 
	; Finland, $05 = Denmark, $06 = France, $07 = Austria and Switzerland, $0A =
	; Italy, $0B = Hong Kong and China, $0C = Indonesia, $0D = Korea...
	LICENSEECODE 	$00	; Usually $00
	VERSION 	$00	; $00 = 1.00, $01 = 1.01, etc.
.ENDSNES

.SNESNATIVEVECTOR ; Native mode interrupt vectors
	COP 	EmptyHandler
	BRK 	EmptyHandler
	ABORT 	EmptyHandler
	NMI 	VBlank
	IRQ 	EmptyHandler
.ENDNATIVEVECTOR

.SNESEMUVECTOR ; Emulation mode interrupt vectors
	COP 	EmptyHandler
	ABORT 	EmptyHandler
	NMI 	EmptyHandler
	RESET 	Start
	IRQBRK 	EmptyHandler
.ENDEMUVECTOR

.BANK 0 SLOT 0 ; ROM bank and the slot it's in
.ORG 0 ; .ORG 0 is really $8000, because the slot starts at $8000
.SECTION "EmptyVectors" SEMIFREE

EmptyHandler:
	rti

.ENDS

.EMPTYFILL $00 ; Fill unused space with $00, opcode for BRK.  Will crash the
; SNES if it's executed