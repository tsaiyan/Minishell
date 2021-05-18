# !/bin/zsh

for ((;;))
do
	clear
	echo $STEP
	echo $1
	leaks minishell | grep -A10 for
	sleep 4
done
