#ask the user enter the positive even integers until
#non-positive or odd integer, and find and display
#the sum of those positive even integers

.data
prompt:		.asciiz "Please enter a even number, enter an odd or negative number to exit: "
sum:		.asciiz "\nThe sum of even numbers is "


.text
main:
		li	$s0, 0		#s0 = 0	
loop:	
		li 	$v0, 4		#print prompt
		la	$a0, prompt
		syscall
		
		li	$v0, 5
		syscall			#v0 = input
		move	$t0, $v0	#t0 = input
		
		# check is negative
		bltz	$t0, result	#if(v0 < 0) printSum
		
		# check is odd number
		# using div or rem instruction is expensive
		# use and-immediate (andi) instead
		andi	$t1, $t0, 1	#compare binary of t0 with 0001, if resultn (t1) is 0 then t0 is even, otherwise odd
		bnez	$t1, result	#check if t1 is not 0
		
		
		# s0 += input
		add	$s0, $s0, $t0	#s0 += t0
		b 	loop
result:	
		li	$v0, 4		#print sum msg
		la	$a0, sum
		syscall
		
		li	$v0, 1		#print int result
		move	$a0, $s0	#a0 = s0
		syscall