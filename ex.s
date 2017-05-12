.name "zork"
.comment "just a basic living prog"
		
l2:	sti	r1,%:vide,%0
	and	r1,%0,r1
label:	live	%1
	zjmp	%:label
vide:
