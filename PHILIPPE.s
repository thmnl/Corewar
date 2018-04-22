.name "PHILIPPE"
.comment "Je sais ou tu t'caches"	
	
		ld %303, r3
		ld %190317059, r2
		sti r2, r3, %0
		ld %-450, r3 
		ld %190317059, r2
		sti r2, r3, %0
		ld %6, r3 
 start: sti r1, %0, %8
 		live %1
		fork %:wall
start2:	sti r1, %0, %8
 		live %1
		fork %:start2
		sti r1, %0, %8
 		live %1
		lfork %200
		sti r1, %0, %8
		live %1
		lfork %400
		sti r1, %0, %8
		live %1
		lfork %600
		sti r1, %0, %8
		live %1
		lfork %800
		sti r1, %0, %8
		live %1
		lfork %1000
		sti r1, %0, %8
		live %1
		lfork %1200
		sti r1, %0, %8
		live %1
		lfork %1400
		sti r1, %0, %8
		live %1
		lfork %1600
		sti r1, %0, %8
		live %1
		lfork %1800
		sti r1, %0, %8
		live %1
		lfork %2000
		sti r1, %0, %8
		live %1
		lfork %2200
		sti r1, %0, %8
		live %1
		lfork %2400
		sti r1, %0, %8
		live %1
		lfork %2600
		sti r1, %0, %8
		live %1
		lfork %2800
		sti r1, %0, %8
		live %1
		lfork %3000
		sti r1, %0, %8
		live %1
		lfork %3200
wall:
