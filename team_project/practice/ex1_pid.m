P = tf(3,[1 3 2 0]);
%KD = 0.1;
%KD = 0.1;
%KP = 20;
%KI = 0.1;


%KP = 6;
%KI = 0.09;
%KD = 3.8;

KP = 0.7;
KI = 0.1;
KD = 0.5;

Ppid = tf([KD KP KI],[1 0]);
G = Ppid*P/(1+Ppid*P)
G1 = feedback(Ppid*P,1)
zero(G1)
pole(G1)
step(G1)
sim("ex1_pid_simulink.slx")
