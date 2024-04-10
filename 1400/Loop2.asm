#Ask the user to enter a positive integer and then use a loop to add
#all integers from 1 to the integer the user entered, inclusive.
#Do input validation for the user input
.data
Prompt:		.asciiz "Please enter a positive integer: "
Error:		.asciiz "Not accept negative or zero\n"
Line:		.asciiz "\nLoop:"
Sum:		.asciiz "\nThe sum is "
.text

main:
	li	$v0, 4
	la	$a0, Prompt
	syscall
	
	li	$v0, 5		#input
	syscall
	move	$t0, $v0	#t0 = input
	
	#input validation
	#get input
	#while(invalid input)
	#	print error message
	#	get input 
	#end loop
	
	bgtz	$t0, validInput
	
invalidInput:
	#need complete the code
	#
	li	$v0, 4
	la	$a0, Error
	syscall
	
	b 	main
	
validInput:
	li	$t1, 0			#t1 = 0
	li	$s0, 0			#s0 = 0
loop:
	bge	$t1, $t0, result	#if(t1 >= t0) result
	
	addi	$t1, $t1, 1		#t1++
	add	$s0, $s0, $t1		#s0 += t1
	
	li	$v0, 4			#print "\nLoop:"
	la	$a0, Line
	syscall
	
	li	$v0, 1
	move	$a0, $t1
	syscall				#print t1
	
	blt	$t1, $t0, loop		#if(t2<=t0) => loop
	
result:
	li	$v0, 4			#print sum
	la	$a0, Sum
	syscall
	
	li	$v0, 1
	move	$a0, $s0
	syscall	
