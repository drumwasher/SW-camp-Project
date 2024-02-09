s=0;
sys1=10*(s+2)/(s*(s+4)*(s+6)*(s+8)*(s+10));
Rs1=1;
Es1=Rs1-sys1;


sys2=10*(s+2)/(s^5+28*s^4+284*s^3+1232*s^2+1930*s+20);
Rs2=1;
Es2=Rs1-sys1;

zeros = [2];
poles = [6 5 4];
gain = 10;
ts = 0.1;
sys = zpk(zeros,poles,gain,ts);

