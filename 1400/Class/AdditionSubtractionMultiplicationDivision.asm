.data


.text
	#t3 = 20; 2 cout << t3;
	li 	$t3, 20		#addi	$t3, $zero, 20
	li	$v0, 1
	move	$a0, $t3	#add	$a0, $t3, $zero
	syscall
	
	#cin >> t0;	(input integer)
	li	$v0, 5		#user input goes to v0
	syscall
	move	$t0, $v0	#add $t0, $v0, $zero
	
	#t3 = t4 + t5 - t6;	(t4=2, t5 = 12, t6=16;
	li	$t4, 20
	li	$t5, 12
	li	$t6, 16
	add	$t3, $t4, $t5	#t3=t4+t5
	sub	$t3, $t3, $t6	#t3=t3-t6
	
	#s4 = s4 * 8;	(s4=11)
	li	$s4, 11
	#li	$t1, 8
	#mult	$s4, $t1	#s4*8
	#mflo	$s4
	sll 	$s4, $s4, 3	#shift s4 to left by 3bit	(times 8)
	
	#t3 = t3 / 4	(t3=28)
	li	$t3, 28
	#li	$t1, 4
	#div	$t3, $t1	#t3/4
	#mflo	$t3		#t3=t3/4
	sra	$t3, $t3, 2	#shift t3 to right arithmetic by 2bits	(divide by 4)
	
	#s3 = t2 / (s1 - 3);	(s1=5. t2=18)
	li	$s1, 5
	li	$t2, 18
	addi	$t0, $s1, -3	#t0=s1-3
	div	$t2, $t0
	mflo	$s3		#move from lo to s3
