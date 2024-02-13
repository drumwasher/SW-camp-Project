clear;
clc;

%Low pass filter for Speed
num = 1;
den = [0.05 1];

G = tf(num,den);
Gd = c2d(G, Ts);

num_Gd = Gd.Num{:};
den_Gd = Gd.Den{:};

Wref = 128;

Vlim=12;

KP = 0.05; %0.7
KI = 0.02; %0.1
KD = 0.01; %0.5

