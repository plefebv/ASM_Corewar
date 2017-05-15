cp $1.s $1_zaz.s
./asm_zaz $1_zaz.s
./asm $1.s
if [  ! -e $1.cor ] && [ ! -e $1.cor ]
then
	echo "$1 : [OK] NO FILE CREATE"
fi

if [ -e $1.cor ] && [ -e $1_zaz.cor ] && diff $1.cor $1_zaz.cor
then
	echo "$1: [OK]"	
	if [ -e $1.cor ]
		then
			hexdump -C $1.cor > ok_$1.txt
			rm $1.cor $1_zaz.cor
	fi
else
	 
	if [ -e $1.cor ] && [ -e $1_zaz.cor ] 
	then
		echo $1": [KO]"
		diff $1.cor $1_zaz.cor > diff_$1.txt
		echo "\n\n$1.cor \n" >> diff_$1.txt
		hexdump -C $1.cor >> diff_$1.txt
		echo "\n\n$1_zaz.cor\n" >> diff_$1.txt
		hexdump -C $1_zaz.cor >> diff_$1.txt
	fi
fi
rm $1_zaz.s
