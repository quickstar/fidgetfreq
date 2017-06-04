clear
clc
 
%User Defined Properties 
serialPort = 'COM3';            % define COM port #


s = serial(serialPort);
s.BaudRate = 9600;
fopen(s);

oldFreq = double(0);
diff = double(0);

while(true)
    rotTime = str2double(fscanf(s));
    freq = 1/(rotTime/1000000);    
    diff = oldFreq - freq;
    estimated = freq/diff;
    disp(estimated);
    oldFreq = freq;
end

fclose(s);
