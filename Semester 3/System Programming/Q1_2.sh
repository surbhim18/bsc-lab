argv=$*
argc=$#

rev=""

for((i=1; $i<=$argc; i++))
do
	((n=$argc-$i))
	shift $n
	rev="$rev $1"
	set $argv
done

echo $rev
	
