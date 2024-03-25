.data
prompt1: 	.asciiz "Please enter the first integer: "
prompt2: 	.asciiz "Please enter the second integer: "
sum:		.asciiz "The sum is "
product:	.asciiz "\nThe product is "


.text 
main:
	# or use addi $v0, $zero, 4; CANNOT use move $v0, 4
	li	$v0, 4 		# print the string
	la	$a0, prompt1 	# store the address or prompt message into $ao
	syscall
	
	li 	$v0, 5		# get user input
	syscall			# the input is in $v0
	
	# add $t1, $v0, $zero
	# addi $t1, $v0, 0
	move	$t1, $v0	# $t1 = 1st integer
	
	li 	$v0, 4
	la	$a0, prompt2
	syscall			# print the 2nd prompt message
	li	$v0, 5
	syscall			# v0 = 2nd input
	move	$t2, $v0	# t2 = 2nd input
	
	add	$t3, $t1, $t2	# t3 = sum
	mult	$t1, $t2	# product is in register LO
	mflo	$t4		# t4 = product
	
	li	$v0, 4
	la	$a0, sum
	syscall			# print the message for the sum
	
	li	$v0, 1
	move	$a0, $t3
	syscall			# print the sum
	
	li	$v0, 4
	la	$a0, product
	syscall			# print the message for the 2nd result
	
	li	$v0, 1
	add	$a0, $t4, $zero	# pass the product into a0
	syscall			# print the product
	
	li	$v0, 10
	syscall			# exit the program
	
	
	
