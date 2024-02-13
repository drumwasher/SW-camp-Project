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

%h1=tf(Km,[L R]);
%h2=tf(1,[J Kf]);

%dcm_ol=h1*h2; %open_circuit
%dcm=feedback(dcm_ol,Kb,1,1); 

%dcm = ss(h2)*[h1,1];
%dcm = feedback(dcm,Kb,1,1);

%wn = 10;
%zeta = 0.7;
%num = wn^2;
%den = [1 2*wn*zeta wn^2];
%G = tf(num,den);
%step(G)

%P = tf(3,[1 3 2 0]);

%Low pass filter for Speed
num = 1;
den = [0.05 1];

G = tf(num,den);
Gd = c2d(G, Ts);

num_Gd = Gd.Num{:};
den_Gd = Gd.Den{:};


Wref = 128; % 430~442pwm 128

Vlim=12;

KP = 0.05; % 0.05 0.4;   0.7 
KI = 0.2;  % 0.2 0.15;  0.1 
KD = 0.01; % 0.01 0.1;   0.5

f=100;
l=100;
r=100;
b=100;

%sim("ex1_pid_simulink.slx")
