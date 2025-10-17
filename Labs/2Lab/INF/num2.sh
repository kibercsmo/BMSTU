read -p "Первое число: " num1
num1=$((num1 % 2))
if [ "$num1" -eq 1 ];then
    echo 'Число нечётное! '
else
    echo 'Число чётное! '
fi




