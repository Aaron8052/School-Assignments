# Write a program that asks the user to enter an integer
# and then determines that is even or odd

.data
prompt:		.asciiz "Please enter an integer: "
result1:	.asciiz "Even\n"
result2:	.asciiz "Odd\n"
	
.text
main:
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall			#get input
	move	$t1, $v0	#t1=input
	
	andi	$t2, $t1, 1	#t2=input%2 (1=binary 2)
	
	#li	$t3, 2
	#div	$t1, $t3
	#mfhi	$t2
	#if: input is zero (even)
	beqz	$t2, even 	#equal to zero: input is even
	#else: input is odd
	li	$v0, 4
	la	$a0, result2
	syscall
	b 	exit		# exit()
	
even:
	li	$v0, 4
	la	$a0, result1
	syscall
	
exit:
	li	$v0, 10
	syscall			#exit
	
	