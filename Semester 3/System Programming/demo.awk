BEGIN{ FS="|"; printf "\n%s\n","Name	Basic	 DA	 HRA	 GROSS" }
{
da=0.25*$2; hra=0.50*$2;gp=$2+da+hra
tot[1]+=$2; tot[2]+=da; tot[3]+=hra; tot[4]+=gp
count++
}
END{printf "\nAverage \t%d\t%d\t%d\t%d\n", tot[1]/count, tot[2]/count, tot[3]/count, tot[4]/count}
