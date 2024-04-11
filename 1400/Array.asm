.data
#int array[1024]
array:		.space 4096
#int pof2[16] = {1, 2, 4, 8,16,32, 64,128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768}
pof2:		.word 1, 2, 4, 8,16,32, 64,128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
#char* charArr = "assembly"
charArr:	.asciiz	"assembly"	#8 chars string
charArr2:	.space 9		#one more space for nullterminate




.text

	la	$a0, pof2	# a0 = $pof2
	lw	$s0, 8($a0)	# s0 = MEM(a0 + 8)