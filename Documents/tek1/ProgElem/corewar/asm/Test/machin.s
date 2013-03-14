.name "machin"
.comment "just a machin"
.extend

l2:
sti r1,%:live,%68       # live = (11)16 soit (17)10
and r1,512,r1
live:
live %68
zjmp %:live
.code AA BB CC 7E

#live: live :machin
#machin: live %:live

