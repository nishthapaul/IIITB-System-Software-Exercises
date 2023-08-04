#!/bin/bash

echo "Please choose from the folowing menu to operate on employee records"
select option in create delete search sort display_all exit
do
	echo option selected is ::: $option
	case $option in
		create )
			echo create selected ;;
		delete )
			echo delete selected ;;
		search )
			echo search selected ;;
		sort )
			echo sort selected ;;
		display_all )
			echo display all selected ;;
		exit )
			echo "Bye Bye !!!"
			exit ;;
		* )
			echo Please provide a number from 1 to 5
	esac
done

