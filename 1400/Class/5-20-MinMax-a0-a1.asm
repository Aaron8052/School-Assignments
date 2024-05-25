# Write a function named sumOfRange function that accepts two integer
# parameters min and max and returns the sum of th integer from min
# through max inclusive. For example, the call of sumOfRange(3, 7)
# returns 3 + 4 + 5 + 6 + 7 or 25. If min is greater than max, return 0.

# use $a and $v registers for arguments and return values
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
	move	$a0, $s1
	move	$a1, $s2
	jal	sumOfRange
	move	$s3, $v0
	
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
	# min = a0, max = a1
	move	$t1, $a0	# t1 = i = min --> max
	li	$t2, 0		# t2 = sum = 0
loop:
	bgt	$t1, $a1, return
	add	$t2, $t2, $t1		# sum = sum + i
	addi	$t1, $t1, 1
	b	loop
return:
	move	$v0, $t2		# v0 = return value, sum
	jr	$ra