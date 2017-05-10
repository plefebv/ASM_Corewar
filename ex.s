.name "name"

.comment "comment"

l2:sti	r1,14,%0
	and	r1,%:label,r1;
label:	live	%:l2
	zjmp	%:label
	;
l3:	sti	r1,%:l2,%0
	and	r1,%:l2,r1
