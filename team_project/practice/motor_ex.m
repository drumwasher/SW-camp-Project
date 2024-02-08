R=2.0;
L=0.5;
Km=0.1;
Kb=0.1;
Kf=0.2;
J=0.02;


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