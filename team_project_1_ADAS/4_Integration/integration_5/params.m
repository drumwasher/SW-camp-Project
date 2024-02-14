clear;
clc;
R=2.0;
L=0.5;
Km=1;
Kb=0.1;
Kf=0.01;
J=0.02;

Ts=1e-2;
encoder_scale = 1/12/4 *2*pi;

%Low pass filter for Speed
num = 1;
den = [0.05 1];

G = tf(num,den);
Gd = c2d(G, Ts);

num_Gd = Gd.Num{:};
den_Gd = Gd.Den{:};


%Wref = 400; % 430~442pwm 128

default1 = 360;
steering = 0.02;

Vlim=12;

KP = 0.009; %0.005 0.05 0.4;   0.7 
KI = 0.03;  %0.01 0.2 0.15;  0.1 
KD = 0; % 0.01 0.1;   0.5

f=100;
l=100;
r=100;
b=100;
