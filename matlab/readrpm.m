clear all;
s1 = serial('COM3');    %define serial port
s1.BaudRate = 9600;     %define baud rate

fopen(s1);
figure

    counter = int32(0);
    while(1)
        try
            data=fscanf(s1);
            counter = counter + 1;
        catch err
            break;
        end

        %vector = strsplit(data, ':');
        x = str2double(counter);
        y = str2double(data);
        plot(x, y);
        drawnow;
    end
fclose(s1);