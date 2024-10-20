read_file = open("encoder_readings3.txt" , "r")
write_file1 = open("encoder_readings1.txt" , "w")
write_file2 = open("encoder_readings2.txt" , "w")

for line in read_file:
		line = line.rstrip()
		new_line = line.split(" ")
		print new_line
		if new_line[2] == '1':
			write_file1.write(new_line[0] + " " + new_line[1] + "\n")
		elif new_line[2] == '2':
			write_file2.write(new_line[0] + " " + new_line[1] + "\n")
	
read_file.close()
write_file1.close()
write_file2.close()