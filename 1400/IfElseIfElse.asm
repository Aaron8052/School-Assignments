# Write a program that asks the user to enter an integer an then
# determines and outputs whether the integer is negative, positive, or zero

.data
prompt:		.asciiz "Please enter an integer: "
result1:	.asciiz "Positive\n"
result2:	.asciiz "Negative\n"
result3:	.asciiz "Zero\n"

.text
main:
	li	$v0, 4		#output prompt
	la	$a0, prompt
	syscall
	
	li	$v0, 5		#get input
	syscall
	
	move	$t1, $v0	#t1=input
	
	bgtz	$t1, positive	#t1 > 0
	bltz	$t1, negative	#t1 < 0
else:
	li	$v0, 4
	la	$a0, result3	#output zero
	syscall
	b 	exit
positive:
	li	$v0, 4
	la,	$a0, result1	#output positive
	syscall
	b 	exit
negative:
	li	$v0, 4
	la,	$a0, result2	#output negative
	syscall
	#b 	exit

exit:
	li	$v0, 10
	syscall		
	