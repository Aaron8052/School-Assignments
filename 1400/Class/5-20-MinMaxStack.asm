# Write a function named sumOfRange function that accepts two integer
# parameters min and max and returns the sum of th integer from min
# through max inclusive. For example, the call of sumOfRange(3, 7)
# returns 3 + 4 + 5 + 6 + 7 or 25. If min is greater than max, return 0.

# use stack for arguments and return values
.data
prompt1:		.asciiz "Enter the min: "
prompt2:		.asciiz "Enter the max: "
result:			.asciiz "The sum is "

.text
main:
	# get input	s1 = min, s2 = max
	li	$v0, 4
	la	$a0, prompt1
	syscall
	li	$v0, 5
	syscall
	move	$s1, $v0	# s1 = min
	
	li	$v0, 4
	la	$a0, prompt2
	syscall
	li	$v0, 5
	syscall
	move	$s2, $v0	# s2 = max
	
	# call the function
	addi	$sp, $sp, -12		# allocate 12-byte stack memory
	sw	$s1, 0($sp)
	sw	$s2, 4($sp)
	jal	sumOfRange
	lw	$s3, 8($sp)
	addi	$sp, $sp, 12		# deallocate
	
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
	
sumOfRange:
	# min = 0($sp), max = 4($sp), sum = 8($sp)
	lw	$t1, 0($sp)	# t1 = i = min --> max
	lw	$a1, 4($sp)	# a1 = max
	li	$t2, 0		# t2 = sum = 0
loop:
	bgt	$t1, $a1, return
	add	$t2, $t2, $t1		# sum = sum + i
	addi	$t1, $t1, 1
	b	loop
return:
	sw	$t2, 8($sp)		# return value is in 8($sp)
	jr	$ra