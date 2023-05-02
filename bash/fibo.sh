echo Enter the number of terms
read n

n1=0
n2=1
echo $n1
echo $n2

for ((i=0; i<$n; i++))
do
    n3=$(($n1+$n2))
    echo $n3
    n1=$n2
    n2=$n3
done