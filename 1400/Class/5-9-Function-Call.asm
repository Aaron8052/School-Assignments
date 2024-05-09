.data
array:		.word 10, 2, -3, -2, 9, 1, 0, 8, -3
size:		.word 9
result1:	.asciiz "The sum of all positive numbers is "
result2:	.asciiz "\nThe sum of all negative numbers is "


.text
main:
	# pass arguments to function via a0 and a1
	la	$a0, array
	lw	$a1, size
	jal	sum
	
	# save the return values
	move	$s0, $v0
	move	$s1, $v1
	
	# print
	li	$v0, 4
	la	$a0, result1
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	li	$v0, 4
	la	$a0, result2
	syscall
	li	$v0, 1
	move	$a0, $s1
	syscall
	
	#end program
	li	$v0, 10
	syscall
	
	
sum:
	move	$t0, $a0		# t0 = address of the first element
	move	$t1, $a1		# t1 = size
	li	$t2, 0			# sum of all positive numbers
	li	$t3, 0			# sum of all negative numbers
	
loop:
	blez	$t1, return
	lw	$t4, ($t0)		# t4 = element
	bgtz	$t4, positive
	#else --> zero or negative
	beqz	$t4, update
	#else --> negative
	add	$t3, $t3, $t4		# negative sum += element
	b 	update
positive:
	add	$t2, $t2, $t4		# positive sum += element	
update:	
	addi	$t0, $t0, 4		# t0 = address of next element
	addi	$t1, $t1, -1		# loop counter --
	b 	loop
return:
	# store return value into $v registers
	move	$v0, $t2
	move	$v1, $t3
	jr	$ra