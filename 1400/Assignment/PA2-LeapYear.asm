# Write a program that asks the user to enter a year, and then the program should determine and display 
# whether it is a leap year.

.data
prompt:		.asciiz "Please enter a year: "
resultYear:	.asciiz "The year "
resultYes:	.asciiz " is a leap year"
resultNo:	.asciiz " is not a leap year"

.text 
main:
		# Prompt user for year
		li	$v0, 4
		la	$a0, prompt
		syscall
		
		li	$v0, 5
		syscall
		
		move 	$s0, $v0
		
		# output: The year (year)...
		li	$v0, 4
		la	$a0, resultYear
		syscall 
		li	$v0, 1
		move	$a0, $s0			#s0 = year
		syscall 
		
		
		
		#if( s0 % 100 == 0 && s0 % 400 == 0) || (s0 % 100 != 0 && s0 % 4 == 0) )
		li 	$t1, 100			#t1 = 100
		li	$t2, 400			#t2 = 400

		#if(year % 100 == 0)
		div	$s0, $t1			#s0 / 100
		mfhi	$t0			#t0 = s0 % 100
		beqz	$t0, centuryYear
nonCentury:
		andi	$t0, $s0, 3		#t0 = binary AND with 0011 (year % 4)
		beqz	$t0, isLeapYear
		b	isNotLeapYear
centuryYear:
		div	$s0, $t2			#s0 / 400
		mfhi	$t0			#t0 = s0 % 400
		beqz	$t0, isLeapYear
		b	isNotLeapYear		
isLeapYear:
		# output: ...is a leap year
		li	$v0, 4
		la	$a0, resultYes
		b 	exit
isNotLeapYear:		
		# output: ...is not a leap year
		li	$v0, 4
		la	$a0, resultNo
exit:
		syscall
		li	$v0, 10
		syscall
		
		
