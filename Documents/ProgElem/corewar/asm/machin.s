.name "machin"
.comment "just a machin"
.extend

l2:     sti r1,%:live,%1       # live = (11)16 soit (17)10
        and r1,%0,r1

live:   live %1
        zjmp %:live
