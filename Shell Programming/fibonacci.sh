
#!/bin/sh
echo "Enter Number  : "
read num
a=0
b=1
((c=a+b))
((num=num-2))
echo " Series : "
echo $a
echo $b

for (( i = 0; i < num; i++ ))
do
	echo $c
	((a=b))
	((b=c))
	((c=a+b))	
done


: '

OUTPUT
				Enter Number  :
				10
				 Series :
				0
				1
				1
				2
				3
				5
				8
				13
				21
				34

'