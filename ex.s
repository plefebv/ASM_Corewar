.name "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289"

.comment "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890145690125670112890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901456901256701128901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890145690125670112890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901456901256701128901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890145690125670112890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901456901256701128901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890145690125670112890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901456901256701128901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890145690125670112890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901456901256701128901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789014569012567011289"

l0:
l1:
l2:	sti	r1,%:label,%0
	and	r1,%:label,r1
label:	live	%:l0
	zjmp	%:label
l3:	sti	r1,%:l1,%0
	and	r1,%:l2,r1
