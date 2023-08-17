#!/bin/bash

records_file="records.txt"

function create_emp_record() {
	read -p "Enter Employee Name ::: " e_name
	read -p "Enter Employee Id ::: " e_id
	read -p "Enter Employee Contact Number ::: " e_phone
	echo $e_name $e_id $e_phone >> $records_file
}

echo "Please choose from the folowing menu to operate on employee records"
select option in create delete search sort display_all clear_database exit
do
	echo option selected is ::: $option
	case $option in
		create )
			create_emp_record ;;
		delete )
			echo delete selected ;;
		search )
			echo search selected ;;
		sort )
			echo sort selected
			sort -k 2n -k 1,1 records.txt > records.txt
			;;
		display_all )
			if [ -s $records_file ]
			then
				cat $records_file
			else
				echo "No records exist !!!"
			fi
			;;
		clear_database )
			 > $records_file ;;
		exit )
			echo "Bye Bye !!!"
			exit ;;
		* )
			echo Please provide a number from 1 to 6
	esac
done

