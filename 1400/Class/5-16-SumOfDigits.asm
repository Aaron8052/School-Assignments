# sum of digits

.data
prompt:		.asciiz "Please enter a positive number: "
result:		.asciiz	"Sum of digits: "
.text 
main:
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	li	$v0, 5
	syscall
	addi	$sp, $sp, -8
	
	sw	$v0, 0($sp)
	
	li	$v0, 4
	la	$a0, result
	syscall
	
	
	jal	sumOfDigits
	
	lw	$a0, 4($sp)
	li	$v0, 1
	syscall
	addi	$sp, $sp, 8

	# exit
	li	$v0, 10
	syscall
	
sumOfDigits: # 0 = arg, 4 = return value
	lw	$t0, 0($sp)		# t0 = argument
	li	$t1, 10			# t1 = 10
	li	$t4, 0			# result
loop:
	blez	$t0, return
	div	$t0, $t1
	mfhi	$t3			# t3 = remainder
	mflo	$t0			# update t0
	add	$t4, $t4, $t3		# t4 += t3
	b	loop
	
return:
	sw	$t4, 4($sp)
	jr	$ra
