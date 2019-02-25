%Constant Resistance values
R = 10*10^3;
%Cutoff Frequencies
UpperCutOff = 3*10^3;
LowerCutOff = 100;
%Capacitance values in nF
CapUpper = (10^9)/(2*pi*UpperCutOff*R)
CapLower = (10^9)/(2*pi*LowerCutOff*R)
%Resonant Frequency
ResFreq = sqrt(UpperCutOff*LowerCutOff)
