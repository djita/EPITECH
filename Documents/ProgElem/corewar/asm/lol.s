.name  "Yo"
	.comment "ca roule ?"
	.extend

	sti r1,%:live,%1
	and r1,%0,r1
live:	   live %1
	zjmp %:live
	.code 01 00 00 00 01
	