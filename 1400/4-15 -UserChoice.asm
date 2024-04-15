.data
menu:		.asciiz "1. Adult\n2. Child\n3. Senior\n4. Quit\nEnter your choice: "
result:		.asciiz "The total charge: "
month:		.asciiz "How many months: "
exit:		.asciiz "Program ending"

.text
		li	$v0, 4
		la	$a0, menu
		syscall
		li	$v0, 5
		syscall
		move	$t0, $v0		#t0=choice
		
		
		li	$t1, 1			#adult choice
		li	$t2, 2			#child choice
		li	$t3, 3			#senior choice
		
		beq	$t0, $t1, adult
		#not adult
		beq	$t0, $t2, child
		#not child
		beq	$t0, $t3, senior
		#not senior, quit the program
		li	$v0, 4
		la	$a0, exit
		syscall
		#exit the program
		b 	next
		
adult:
		li	$v0, 4
		la	$a0, month
		syscall
		
		li	$v0, 5
		syscall
		move	$s0, $v0		#s0=# of months
		li	$s1, 40			#s1=monthly fee, $40
		mult	$s0, $s1
		mflo	$s2			#s2=total charge
		
		#print the result
		li	$v0, 4
		la	$a0, result
		syscall
		li	$v0, 1
		move	$a0, $s2
		syscall
		
		b 	next	
child:	
		li	$v0, 4
		la	$a0, month
		syscall
		
		li	$v0, 5
		syscall
		move	$s0, $v0		#s0=# of months
		li	$s1, 20			#s1=monthly fee, $20
		mult	$s0, $s1
		mflo	$s2			#s2=total charge
		
		#print the result
		li	$v0, 4
		la	$a0, result
		syscall
		li	$v0, 1
		move	$a0, $s2
		syscall
		
		b 	next	

senior:
		li	$v0, 4
		la	$a0, month
		syscall
		
		li	$v0, 5
		syscall
		move	$s0, $v0		#s0=# of months
		li	$s1, 30			#s1=monthly fee, $30
		mult	$s0, $s1
		mflo	$s2			#s2=total charge
		
		#print the result
		li	$v0, 4
		la	$a0, result
		syscall
		li	$v0, 1
		move	$a0, $s2
		syscall	

next:		#exit the program
		li	$v0, 10
		syscall

		