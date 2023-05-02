# echo "enter the number"
# read num
# ans=0
# while [num>0]
# do
#     ans=(( $ans +$(($num/10))))
# done
# echo $ans

echo enter n
read n
num=0
while [ $n -gt 0 ]
do
num=$(expr $num \* 10)
k=$(expr $n % 10)
num=$(expr $num + $k)
n=$(expr $n / 10)
done
echo number is $num