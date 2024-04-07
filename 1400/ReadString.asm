.data
prompt:		.asciiz "Please enter your name: "
#char array
name:		.space 31		#alloc a space max of 30 char
result:		.asciiz "Your name: "

.text
main:
	li	$v0, 4		# output
	la	$a0, prompt
	syscall
	
	# cin.getline()
	li	$v0, 8		# input string
	la	$a0, name	# store input in the variable, name
	li	$a1, 30		# max char from input
	syscall
	
	li	$v0, 4		# output name
	la	$a0, result
	syscall
	
	# not necessary to set 4 again since line 19 is already set to 4
	#li	$v0, 4		# output name
	la	$a0, name
	syscall
	
	li	$v0, 10
	syscall			#exit
