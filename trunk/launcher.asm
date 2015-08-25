;########################################################
;# [launcher.asm]
;#-------------------------------------------------------
;# Ce code est un pur hack de mon pote !
;# Il permet de lancer le programme comme le 
;# ferait un shell
;# La limite de ~8k est imposée par TI, l'OS verifie la
;# taille du programme avant de lancer et refuse si ça 
;# depasse. Lancer avec un launcher permet de contourner 
;# ce probleme.
;# Attention il y a une autre limite (pas de code exécuté 
;# après C000 si je me gourre pas) qui est violée dans 
;# zmegaman grace au hack de zstart 
;#-------------------------------------------------------

; Hey TI, please execute my code, do it now !

#include "zincludes/ti83plus.inc"
#include "zincludes/ion.inc"
_NZIf83Plus   = $50E0
.org progstart-2
.db t2ByteTok, tasmCmp
  ;call disable_c000_protection

	ld hl,debut_routine
	ld de,gbuf
	ld bc,fin_routine-debut_routine
	ldir
	jp gbuf

debut_routine:
	ld	hl, programme_a_executer
	rst	20h
	bcall(_ChkFindSym)
	 ret	c
	ld	a, b					;a = page flash
	or	a
	 ret	z					;quitter si dans la ram
	ex	de, hl					;hl = début du programme
	ld	de, appBackUpScreen
	ld	bc, 2+2+7+1+3+3+3
	push	af					;sauver page flash
		bcall(_FlashToRam)		;copier 22 octets (header/AsmPrgm) dans appbackupscreen
	pop	af						;restaurer page flash (possiblement pas nécéssaire)
	ld	bc, 2+2+7+1+3+3+3+$4000
	or	a
	sbc	hl, bc					;si hl <$4022, on a avancé à la prochaine page
	add	hl, bc					; il faut donc augmenter a
	adc	a, 0					;a+1 si on a avancé une page
	push	af
	ex	de, hl					;hl = prochain octet dans appBackUpScreen
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl)					;MSB de la taille du programme
	dec	hl						;
	ld	l, (hl)					;LSB de la taille du programme
	ld	h, a
	push	hl					;hl = taille du programme
	push	de
	ld	de, $9D95				;de = où charger le programme
	bcall(_InsertMem)			;créer de l'espace
	pop	hl						;hl = premier octet des datas du programme
	pop	bc						;bc = taille du programme
	pop	af						;af = première page de ses datas
	bcall(_FlashToRam)
	jp	$9D95					;l'exécuter
programme_a_executer:
.db ProgObj,"ZMEGAMAN",0
fin_routine:

