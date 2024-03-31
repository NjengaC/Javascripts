#!/bin/bash

# Calculate the average of a series of numbers.

SCORE="0"
AVERAGE="0"
SUM="0"
NUM="0"
CHOICE=""

while true; do

	echo -n "Enter your score [00-100%] ('q' for quit): "; read SCORE;

	if (("$SCORE" < "00"))  || (("$SCORE" > "100")); then
		echo "Be serious.  Come on, try again! "
	elif [ "$SCORE" == "q" ]; then
		echo "Average rating: $AVERAGE%."
		break
	elif [ "$SCORE" == "print" ]; then
		echo "Avarage rating: $AVERAGE%."
		SUM="0"
		NUM="0"
		AVERAGE="0"
		echo -n "Start the next classes or quit('q' for quit)?";
		echo -n "";
		read CHOICE;
		if  [ "CHOICE" == "YES" ]; then
			continue
		elif [ "CHOICE" == "NO" ] || [ "CHOICE" == "quit" ]; then
			exit
		fi
	else
		SUM=$[$SUM + $SCORE]
		NUM=$[$NUM + 1]
		AVERAGE=$[$SUM / $NUM]
	fi
done

echo "Exiting."
