#! /bin/bash

#set -o xtrace; #Descomentarlo si se quiere ver comando ejecutado y su output, para depurar
set -o nounset; #Alarma si se hace referencia a una variable que no se ha declarado.

# COLORS
DEFAULT='\033[0m'
PROCESSING='\033[5;38;5;15m'
RED='\033[7;38;5;9m'
GREEN='\033[7;38;5;10m'

cd ~/miniRT/checkers/;

#  Comprobacíón de la función de submatrices.
submatrix_checker()
{
	local test_main="./checkers/submatrix/submatrix_main.c";
	local expected_output="./submatrix/submatrix_checker.txt";
	local diff_output;
	local diff_exit;
	
	if [[ -e "../miniRT" ]]; then
		make -C ../ fclean 2>&1>/dev/null;
	fi;
	make -C ../ -s MAIN=$test_main 2>&1>/dev/null;
	diff_output=$(diff <(../miniRT) $expected_output);
	diff_exit=$?;
	echo -e "___CHECKS ft_submatrix___";
	echo -e "Comparing program output against expected output...";
	sleep 1;
	echo -ne "\r[#   ]";
	sleep 0.5;
	echo -ne "\r[##  ]";
	sleep 0.5;
	echo -ne "\r[### ]";
	sleep 0.5;
	echo -ne "\r[####]";
	sleep 0.5;
	if [[  $diff_exit -eq 0 ]]; then
		echo -e "${GREEN}    OK!    ${DEFAULT}";
	else
		echo -e "${RED}    KO    ${DEFAULT}\n___OUTPUT___";
		echo -e "$diff_output";
	fi;
}

det_matrix_checker()
{
	local test_main="./checkers/det_matrix/det_matrix_main.c";
	local expected_output="./det_matrix/det_matrix_checker.txt";
	local diff_output;
	local diff_exit;

	python3 "./det_matrix/det_generartor.py";	
	if [[ -e "../miniRT" ]]; then
		make -C ../ fclean 2>&1>/dev/null;
	fi;
	make -C ../ -s MAIN=$test_main 2>&1>/dev/null;
	diff_output=$(diff <(./det_matrix/tester.sh) $expected_output);
	diff_exit=$?;
	echo -e "___CHECKS ft_matrix_det___";
	echo -e "Comparing program output against expected output...";
	sleep 1;
	echo -ne "\r[#   ]";
	sleep 0.5;
	echo -ne "\r[##  ]";
	sleep 0.5;
	echo -ne "\r[### ]";
	sleep 0.5;
	echo -ne "\r[####]";
	sleep 0.5;
	if [[  $diff_exit -eq 0 ]]; then
		echo -e "${GREEN}    OK!    ${DEFAULT}";
	else
		echo -e "${RED}    KO    ${DEFAULT}\n___OUTPUT___";
		echo -e "$diff_output";
	fi;
}

submatrix_checker
det_matrix_checker
