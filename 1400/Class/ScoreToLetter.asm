.data
prompt:		.asciiz "Please enter your grade: "
resultA:	.asciiz "\nYou got an A"
resultB:	.asciiz "\nYou got a B"
resultC:	.asciiz "\nYou got a C"
resultD:	.asciiz "\nYou got a D"
resultF:	.asciiz "\nYou got an F"

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
	#li $t2, 90
	#bge	$t1, $t2, A
	bge	$t1, 90, A
	#li $t2, 80
	#bge	$t1, $t2, B
	bge	$t1, 80, B
	#li $t2, 70
	#bge	$t1, $t2, C
	bge	$t1, 70, C
	#li $t2, 60
	#bge	$t1, $t2, D
	bge	$t1, 60, D
	
F:
	#print F
	li	$v0, 4
	la	$a0, resultF
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
	
