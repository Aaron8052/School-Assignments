.data
prompt:		.asciiz "Please enter aa grade: "
resultA:	.asciiz "\nA"
resultB:	.asciiz "\nB"
resultC:	.asciiz "\nC"
resultD:	.asciiz "\nD"
resultE:	.asciiz "\nE"

.text
	#print prompt
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	#get input
	li	$v0, 5
	syscall
	#save input to t1
	move	$t1, $v0
	
	#if score >= #
	bge	$t1, 90, A
	bge	$t1, 80, B
	bge	$t1, 70, C
	bge	$t1, 60, D
	
E:
	#print E
	li	$v0, 4
	la	$a0, resultE
	syscall
	b	Exit
A:
	#print A
	li	$v0, 4
	la	$a0, resultA
	syscall
	b	Exit
B:
	li	$v0, 4
	la	$a0, resultB
	syscall
	b	Exit
C:
	li	$v0, 4
	la	$a0, resultC
	syscall
	b	Exit
D:
	li	$v0, 4
	la	$a0, resultD
	syscall
	#b	Exit
Exit:
	li	$v0, 10
	syscall
	