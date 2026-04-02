BEGIN{
print("Processing numbers in a text file...\n");
}
{
	split($0,a," "); #split fields and store in array a
	for(i = 1; i<=NF; i++){
		row[NR] += a[i];#sum up values in the row or record
	}
	printf "%s ",$0; #print the original line with a space
	printf "%d\n", row[NR]; #print the sum of te numbers
}
END{
print("Script ended...");
}

