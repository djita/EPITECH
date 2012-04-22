.name "Shield"
.comment "Puts live everywhere and ends by a suicid"

init:	sti r1,%:live,%1	# Pour le live
	ld %1,r2		# Init de r2 a 1 (live) et carry
	ld %126,r3		# Init de r3 a 256 (offset)
	ld %32,r4		# Init de r4 a 48 (offset)

live:	live %1			# Un live pour la forme

dump:	sti r2,r3,%-3		# Ecriture de r2 (1 -> live) a l'offset dans r3
	sti r1,r3,%-5		# Ajout du numero de champion
	add r3,r4,r3		# Modification de l'offset
	zjmp %:live		# C'est reparti :D
