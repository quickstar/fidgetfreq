clear all;
s1 = serial('COM4');                            %define serial port
s1.BaudRate = 9600;                               %define baud rate

fopen(s1);
figure
    while(1)
        data=fscanf(s1);
        vector = strsplit(data, ':');
        x = str2double(vector(1));
        y = str2double(vector(2));
        plot(x, y);
    end
fclose(s1);