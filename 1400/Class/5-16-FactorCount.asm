# Write a function named factorCount that accepts an integer
# (assumed to be positive) as its parameter and returns a count
# of its positive factirs. For example. the eight factors of 24
# are 1, 2, 3, 4, 6, 8, 12, and 24, so the call of factorCount(24)
# should return 8
# use the stack memory for arguments and return values

.data
prompt:		.asciiz "Please enter a positive integer: "
result:		.asciiz "Number of factors: "
.text
main:
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall				# v0 = input
	
	# call the function
	addi	$sp, $sp, -8		# allocate 8-byte stack memory
	sw	$v0, 0($sp)		# pass the argument via stack memory
	jal	factorCount		# function call
	lw	$s3, 4($sp)		# save the return value
	addi	$sp, $sp, 8		# release stack memory
	
	# output
	li	$v0, 4
	la	$a0, result
	syscall
	li	$v0, 1
	move	$a0, $s3
	syscall
	
	# exit
	li	$v0, 10
	syscall
factorCount: # 0($sp) = argument, 4($sp) = counter, return value
	lw	$t1, 0($sp)		# t1 = argument
	li	$t2, 0			# t2 = counter
	li	$t3, 1			# t3 = i, 1 --> argument
loop:
	bgt	$t3, $t1, return
	div	$t1, $t3
	mfhi	$t4			# t4 = t1 % t3, n % i
	bnez	$t4, update
	# else, increase counter
	addi	$t2, $t2, 1		# count ++
update:
	addi	$t3, $t3, 1		# i ++
	b 	loop
return:
	sw	$t2, 4($sp)		# save return value in stack
	jr	$ra