.name "Overwriter"
.comment "I punch myself and I like it!"

start:
	sti		r1, %:live0, %1
live0:
	live	%42
fork:
	fork	%:start

	lldi	%0,%0,r2
	lldi	%0,%0,r2
	lldi	%0,%0,r2
	sti		r1, %:fork, %0
