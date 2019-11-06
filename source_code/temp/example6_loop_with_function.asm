sdasd
	.text
	.globl	main
main:
	li	$v0,34		# print_string syscall code = 4
	la	$a0, msg1	
	syscall
	li	$v0,5		# read_int syscall code = 5
	syscall	
	move	$s0,$v0	
	li	$s1, 0		# Reg $s1 = counter (i)
	li	$s2, 0
loop:	
	addi	$s1, $s1, 1	
	move	$a0, $s2	# Argument 1: sum ($s2)
	move	$a1, $s1	# Argument 2: i ($s1)
	jal	add2		# Save current PC in $ra, and jump to add2
	move	$s2,$v0		# Return value saved in $v0. This is sum ($s2)
	beq	$s0, $s1, exit	# if i = N, continue
	j	loop
exit:	
	li	$v0, 4		# print_string syscall code = 4
	la	$a0, msg2
	syscall
	li	$v0,1		# print_string syscall code = 4
	move	$a0, $s2
	syscall
	li	$v0,4		# print_string syscall code = 4
	la	$a0, lf
	syscall
	li	$v0,10		# exit
	syscall
add2:	
	addi $sp,$sp, -4	
	sw $s0,0($sp)	
	add $s0,$a0,$a1	
	move $v0,$s0
	lw $s0,0($sp)
	addi $sp,$sp,4
	jr $ra
	.data
msg1:	.asciiz	"Number of integers (N)?  "
msg2:	.asciiz	"Sum = "
lf:     .asciiz	"\n"