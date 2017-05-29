clear
clc
 
%User Defined Properties 
serialPort = 'COM3';            % define COM port #


s = serial(serialPort);
s.BaudRate = 9600;
fopen(s);


while(true) 
    delimiter = ",";
    dat = fscanf(s);
    rotations = strsplit(dat,delimiter);
    disp(rotations);
end

fclose(s);
