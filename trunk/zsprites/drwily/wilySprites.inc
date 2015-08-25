;Tile data - Graphics Studio

wily_sprites:
.db $03,$1C,$00,$0C,$FA,$00,$04,$45,$00,$08,$D2,$00,$05,$5B
.db $00,$09,$00,$80,$10,$9E,$80,$0F,$8B,$00,$0B,$C5,$C0,$0F,$B1,$20
.db $08,$4E,$20,$0F,$B9,$20,$0F,$DF,$E0,$0F,$E7,$F8,$3F,$F8,$1C,$69
.db $7F,$EE,$7C,$FF,$EE,$69,$7F,$FC,$3F,$FF,$F0,$1F,$FF,$F0
 ;Tile 5
 .db $03,$1C,$00,$0C,$FA,$00,$04,$45,$00,$08
 .db $D2,$00,$05,$5B,$00,$09,$00,$80,$10,$9E,$80,$0F,$8B,$00,$0B,$C5
 .db $C0,$0F,$B1,$20,$08,$4E,$20,$0F,$B9,$20,$0F,$DF,$E0,$0F,$E7,$F8
 .db $3F,$F8,$1C,$69,$7F,$EE,$7C,$FF,$EE,$69,$7F,$FC,$7F,$FF,$F0,$7F
 .db $FF,$F0,$52,$0A,$40,$3F,$87,$F0,$28,$45,$08,$74,$4E,$88,$77,$8E
 .db $F0,$2F,$85,$F0,$34,$46,$88,$23,$F4,$7E,$67,$CC,$F9,$FF,$FF,$FF
 ;Tile 6
 .db $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
 .db $00,$00,$00,$00,$00,$00,$00,$00,$06,$38,$00,$19,$F4,$00,$08,$0A
 .db $00,$11,$A4,$00,$0A,$B6,$00,$12,$01,$00,$21,$3D,$00,$1F,$16,$00
 .db $17,$8B,$80,$1F,$62,$40,$10,$9C,$40,$1F,$72,$40,$1F,$BF,$C0,$1F
 .db $CF,$F0,$7F,$F0,$38,$D2,$FF,$DC,$F9,$FF,$DC,$D2,$FF,$FC,$FF,$FF
 .db $F8,$FF,$FF,$E0,$12,$02,$40,$24,$04,$80,$48,$09,$00,$50,$0A,$00
 .db $B0,$16,$00,$D0,$1A,$00,$D0,$1A,$00,$B0,$16,$00,$68,$0D,$00,$64
 .db $0C,$80,$52,$0A,$40,$3F,$87,$F0,$28,$45,$08,$74,$4E,$88,$77,$8E
 .db $F0,$2F,$85,$F0,$34,$46,$88,$23,$F4,$7E,$67,$CC,$F9,$FF,$FF,$FF
 ;Tile 7
 .db $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
 .db $00,$00,$00,$00,$00,$00,$00,$00,$06,$38,$00,$19,$F4,$00,$08,$0A
 .db $00,$11,$A4,$00,$0A,$B6,$00,$12,$01,$00,$21,$3D,$00,$1F,$16,$00
 .db $17,$8B,$80,$1F,$62,$40,$10,$9C,$40,$1F,$72,$40,$1F,$BF,$C0,$1F
 .db $CF,$F0,$7F,$F0,$38,$D2,$FF,$DC,$F9,$FF,$DC,$D2,$FF,$FC,$FF,$FF
 .db $F8,$FF,$FF,$E0,$12,$02,$40,$24,$04,$80,$48,$05,$00,$50,$0B,$00
 .db $B0,$0D,$00,$D0,$0D,$00,$D0,$0F,$00,$B0,$04,$80,$68,$07,$F0,$64
 .db $05,$08,$52,$0E,$88,$3F,$8E,$F0,$28,$45,$F0,$74,$46,$88,$77,$84
 .db $7E,$2F,$84,$F9,$34,$4F,$FF,$23,$F0,$00,$67,$C8,$00,$FF,$F8,$00
wily_sprites_end:

W_HOVER	= 20
W_TRANS	= 30
W_WALKER= 48
W_WALK	= 48
;offset size, sprite height
wilySpriteSize:
.dw 0 				\ .db	W_HOVER				;hover
.dw W_HOVER*3		\ .db	W_TRANS		;walker transformation
.dw (W_HOVER+W_TRANS)*3	\ .db W_WALKER	;walker
.dw (W_HOVER+W_TRANS+W_WALKER)*3