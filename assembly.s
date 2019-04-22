			.data
_var0:		.word 0
_var1:		.word 0
_var2:		.word 0
_var3:		.word 0
_result0:		.word 0
_var4:		.word 0
           .text
function:
li $t9, 0
sw $t9 , _var1
li $t9, 1
sw $t9 , _var2
li $t9, 1
sw $t9 , _var0
LJ0:
lw $t9, _var0
lw $t8, 4($sp)
sle $t7, $t9, $t8
bne $t7, 1, IFS0
lw $t8, _var0
li $t9, 6
sle $t6, $t8, $t9
bne $t6, 1, IFS0
IFS0:
and $t9, $t7, $t6
beq $t9, 1, IFS1
IFS1:
bne $t9, 1, LF0
b LS0
LT0:
lw $t9, _var0
li $t6, 1
add $t7, $t9, $t6
sw $t7 , _var0
b LJ0
LS0:
lw $t7, _var1
lw $t6, _var2
add $t9, $t7, $t6
sw $t9 , _var3
lw $t6, _var2
sw $t6 , _var1
lw $t7, _var3
sw $t7 , _var2
b LT0
LF0:
lw $t8, _var2
move $v0, $t8
jr $ra
jr $ra
main:
li $t5, 7
sw $t5, -4($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
jal function
lw $ra, 0($sp)
addi $sp, $sp, 8
sw $v0, _var4
li $t5, 0
move $v0, $t5
jr $ra
jr $ra
