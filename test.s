.data 0x10008000
var1:	.word 0x11111111
var2:	.word 0x22222222
var3:	.word 3
var4:	.word 4
var5:	.word 5
var6:	.word 6
		.data 0x1000a004
var7:	.word 7
var8:	.word 8
var9:	.word 9
var10:	.word 10
		.data 0x1000c000
var11:	.word 11
var12:	.word 12
var13:	.word 13
var14:	.word 14
		.data 0x1000e000
var15:	.word 15
var16:	.word 16
var17:	.word 17
var18:	.word 18

.text 0x00400024
.globl main

foo:
	nop
	sw		$t2, 8($gp)
	slt		$a0, $t0, $t1
	sub		$t2, $t1, $t0
	or		$t2, $t1, $t0
	and		$t2, $t1, $t0
	nop
	nop

main:
	lw		$t0, 0($gp)
	lw		$t1, 4($gp)
	beq		$t0, $t1, foo
	add		$t2, $t0, $t0
	beq		$t2, $t1, foo
	j		bar
	add		$t3, $t2, $t1

bar:
	add		$t4, $t3, $t2