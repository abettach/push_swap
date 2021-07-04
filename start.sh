gcc -c *.c push_swap_programme/*.c && gcc *.o *.h -o push_swap && rm *.o
gcc -c *.c checker_programme/*.c && gcc *.o *.h -o checker && rm *.o
export ARG="5 4 1 100 200"
./push_swap $ARG
./push_swap $ARG | ./checker $ARG