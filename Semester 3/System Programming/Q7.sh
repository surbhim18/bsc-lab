
who | cut -d " " -f1 | sort | uniq > temp1
cat temp1 | tr "\n" " " > temp2
((count=`cat temp1 | wc -l`))

for((i=1;i<=count;i++))
do
	patt=`cat temp2 | cut -d " " -f$i`
	uniqueCount=`who | grep -cw "$patt"`
	echo "$patt is logged in $uniqueCount times"
done

