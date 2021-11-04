close all
clear

load ntc.csv

temper = ntc(1:156,1);   %temperature
ADC_value = 1024*(ntc(1:156, 2)./(ntc(1:156, 2)+10))  %value of ADC
p = polyfit(ADC_value, temper, 10);  %polynome
ad2 = 0:1023;  %index of array
t2 = round(polyval(p, ad2), 1); %value of array (temperature - rounded: tenht)
plot(ADC_value, temper, 'o')
grid on;
hold on;
plot(ad2, t2)

dlmwrite('data.dlm', t2*10, ',');