.data
prompt1: 	.asciiz "Please enter the first integer: "
prompt2: 	.asciiz "Please enter the second integer: "
sum:		.asciiz "The sum is "
product:	.asciiz "\nThe product is "
result:		.asciiz "\n(3(num1-num2)-8 = "


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
	
	#compute 3*(t1 - t2) -8
	sub	$s0, $t1, $t2	#s0=t1-t2
	li	$s1, 3		#s1=3
	mult	$s1, $s0	# 3*(t1-t2)
	mflo	$s2		#s2=3(t1-t2)
	addi	$s3, $s2, -8	#s3 = 3(t1-t)-8
	#print it out
	li	$v0, 4
	la	$a0, result
	syscall
	#li	$v0, 
	
	li	$v0, 10
	syscall			# exit the program
	
	
	
