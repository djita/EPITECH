.name "zork"
.comment "just a basic living prog"
.extend

l2:	sti	r1,%:live,%1
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
	
#	live	%0x12		#OK
	ld	21,r1		#OK
#	st	r5,23		#OK
#	add	r1,r2,r3	#OK
#	sub	r2,r1,r2	#OK
#	and	%34,34,r1	#OK
#	or	%0x34,23,r2	#OK
#	xor	23,%0x15,r3	#OK
#	zjmp	%23		#OK
#	ldi	%31,r2,r3	#OK
#	sti	r2,%0x2,r1	#OK
#	fork	%1		#OK
#	lld	%1,r2		#OK
#	lldi	%23,r1,r2	#OK
#	lfork	%21		#OK
#	aff	r2		#OK