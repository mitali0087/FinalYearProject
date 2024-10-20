#Python script to convert hex codes from log file to integers in required format 

log_file = open("at_console_session_2018-04-21.log" , "r")
write_file = open("encoder_readings3.txt" , "w")

log_file.readline()
log_file.readline()

for line in log_file:
	new_line = line.split(",")
	temp = new_line[3].rstrip()
	temp1 = temp.decode("hex")
	write_file.write(temp1)
	
log_file.close()
write_file.close()