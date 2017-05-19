clear all;
s1 = serial('COM4');                            %define serial port
s1.BaudRate = 9600;                               %define baud rate

fopen(s1);
    data=fscanf(s1);
    vector = strsplit(data, ':');
    plot(vector(1), vector(2));
fclose(s1);