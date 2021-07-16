while true
do
ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
# echo $ARG
is_ok2=$(./push_swap $ARG | ./checker $ARG);
# ARG="1 5 2 4 3"
is_ok=$(./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | ./checker_OS $ARG && ./push_swap $ARG | wc -l);
echo $is_ok
if [[ $is_ok2 == *"KO"* ]]
then
	echo $ARG >> ARGS
	 exit;
fi
if [[ $is_ok2 == *"Error"* ]]
then
	echo $ARG >> ARGS
	 exit;
fi
sleep 0.25
done