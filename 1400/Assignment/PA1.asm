.data
Prompt1:	.asciiz "Please enter the first integer: "
prompt2: 	.asciiz "Please enter the second integer: "
Sum:		.asciiz "The sum of those two number is "
Plus:		.asciiz "\nnum1 - num2 + 2 = "
Times:		.asciiz "\nnum1 * num2 - 5 = "
Divide:		.asciiz "\nnum1/num2 = "
Remainder:	.asciiz "\nnum1%num2 = "
	
.text
	# Prompt the user for the first int
	li	$v0, 4
	la	$a0, Prompt1
	syscall
	
	# Get first user input
	li	$v0, 5
	syscall
	move	$t1, $v0	#t1: First Int
	
	li	$v0, 4
	la	$a0, prompt2
	syscall
	
first:
	# Get second user input
	li	$v0, 5
	syscall
	move	$t2, $v0	#t2: Second Int
	
	# Get sum
	add	$t3, $t1, $t2	#t3: Sum
	
	# Print Sum
	li	$v0, 4
	la	$a0, Sum	# Print Message
	syscall
	li	$v0, 1
	move	$a0, $t3	#Print Sum
	syscall
	
second:
	# num1 – num2 + 2 
	# Print Message
	li	$v0, 4
	la	$a0, Plus	# Print Message
	syscall
	
	# Get Value
	sub	$t3, $t1, $t2	#t3: t1 - t2
	addi	$t3, $t3, 2	#t3: t3 + 2
	
	# Print Value
	li	$v0, 1
	move	$a0, $t3
	syscall
	
third:
	#num1 * num2 – 5
	# Print Message
	li	$v0, 4
	la	$a0, Times	# Print Message
	syscall
	
	mult	$t1, $t2	#lo: num1 * num2
	mflo	$t3		#t3: product
	addi	$t3, $t3, -5		#t3: t3-5
	
	# Print Value
	li	$v0, 1
	move	$a0, $t3
	syscall
	
fourth:
	# integer results of num1/num2
	
	div	$t1, $t2	#t1 / t2
	mflo	$t3		#t3 quotient
	mfhi	$t4		#t4 remainder
	
	# Print Message
	li	$v0, 4
	la	$a0, Divide	# Print Message
	syscall
	
	# Print Quotient
	li	$v0, 1
	move	$a0, $t3
	syscall
	
fifth:
	# Print Message
	li	$v0, 4
	la	$a0, Remainder	# Print Message
	syscall
	
	# Print Remainder
	li	$v0, 1
	move	$a0, $t4
	syscall