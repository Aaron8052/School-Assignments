# Write a program that asks the user to enter an integer and outputs the integer in 32-bit two's completement binary.
# There should be a space separating each 4 digits

# Sample runs

# Enter a number: -1
# 1111 1111 1111 1111 1111 1111 1111 1111

# -- Program is finished running --

# Enter a number: 9
# 0000 0000 0000 0000 0000 0000 0000 1001

# -- Program is finished running --

.data
prompt:		.asciiz "Enter a number: "
space:		.asciiz " "

.text

		# get input / initializations
		# setup digit counter
		# setup divider (1000....0)
loop:		
		# branch counter (if counter % 4 = 0 then skip this digit and print a space)
		# branch counter (if counter > max digits then exit)
		# andi input with divider to get first digit
		# shift input to left (sll)
		# branch back to loop
