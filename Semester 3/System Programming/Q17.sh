if [ $# -eq 2 ]
then
	if [ -f $1 -a -f $2 ]
	then
		ls -l $1 $2 | cut -d " " -f1 | tr "\n" " "  > t1.txt
	
		awk '$1==$2 { printf "Permissions of the two files are same\n" }' t1.txt | tee t2.txt

		if [ ! -s t2.txt ]
		then
			echo "Persmissions are different"
		fi

		rm t1.txt t2.txt
	else
		echo "File(s) does not exist"
	fi

else
	echo "Please provide only two arguments"
fi
