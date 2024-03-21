#include "main.h"

char ch;
int duty1 = 0;
int duty2 = 0;
int speed1 = 0;
int speed2 = 0;

int l_dir = 0;
int r_dir = 1;
int drive = 0;

int r_counter = 0;
int f_counter = 0;
int left = 0;
int right = 0;
int auto_park = 0;
int cnt = 0;
int cnt2 = 0;
float left_dist = 0;
float right_dist = 0;
int park = 0;
int do_parking = 0;
int turn = 4;
int dutyflag = 0;
int emergency = 0;
int left_emer_cnt = 0;
int right_emer_cnt = 0;
int avoid_flag = 0;
int back_flag = 0;
int decrease_flag = 0;
int buzzer_flag = 0;

int front_dist;

float rear_dist;

void keyborad_ctrl(){
   if (drive == 0 && (ch == 'r' || ch == 'R')) {
               drive = 1;
            } else if (drive == 1 && (ch == 'r' || ch == 'R')) {
               drive = 0;
            }
            //avoid flag
            if ((ch == 'u' || ch == 'U') && avoid_flag == 1) {
               avoid_flag = 0;
            } else if ((ch == 'u' || ch == 'U') && avoid_flag == 0) {
               avoid_flag = 1;
            }

            //키보드 제어 및 자동주차 키
            if ((ch == 'w' || ch == 'W') && drive) { // SW1 is on
               buzzer_flag=0;
               if (duty1 == 0 || duty2 == 0 || duty1 == 1 || duty2 == 1) {
                  duty1 = 30;
                  duty2 = 30;
               } else {
                  duty1 += 4;  //모터    작동
                  duty2 += 4;
               }
            } else if ((ch == 's' || ch == 'S') && drive) {
               if (duty1 == 0 || duty2 == 0 || duty1 == 1 || duty2 == 1) {
                  duty1 = -30;
                  duty2 = -30;
               } else {
                  duty1 -= 4;
                  duty2 -= 4;
               }
            } else if ((ch == 'a' || ch == 'A') && drive) {
               left = 1;
            } else if ((ch == 'D' || ch == 'd') && drive) {
               right = 1;
            } else if ((ch == ' ') && drive) {
               duty1 = 1;
               duty2 = 1;
               l_dir = 0;
               r_dir = 1;
               auto_park = 0;
               back_flag = 0;
               do_parking = 0;
            } else if ((ch == 'p') && drive) {
               auto_park = 1;
               duty1 = 40;
               duty2 = 40;
               turn = 12;
               back_flag = 0;
               do_parking = 0;
            }
}

void auto_parking(){
   //자동주차 on
         if (auto_park == 1) {
            if (duty1 != 20) {
               duty1 -= 4;
               duty2 -= 4;
            }
            if (left_dist > 35.000) {
               cnt++;
            } else if (left_dist < 35.000) {
               if (cnt < 25) {
                  cnt = 0;
               } else {
                  do_parking = 1;
                  auto_park = 0;
                  cnt2 = cnt;
                  duty1 = -36;
                  duty2 = -36;
               }
            }
         }
         //주차가능시 수행
         if (do_parking == 1) {

            if (cnt > cnt2 / 2) {
               if (duty1 < -20) {

                  duty1 += 2;
                  duty2 += 2;
               }
               cnt--;
            } else if (cnt == cnt2 / 2) {
               cnt--;
               duty1 = 0;
               duty2 = 0;
            } else if (cnt > cnt2 / 4 && back_flag == 0) {
               duty1 = 45;
               duty2 = 45;
               movChA_PWM(duty1, 1);
               movChB_PWM(duty2, 1);
               delay_ms(180);
               back_flag = 1;
               decrease_flag = 1;
            } else if (cnt > cnt2 / 4 && back_flag == 1) {
               if (decrease_flag == 1) {
                  duty1 = -34;
                  duty2 = -34;
                  decrease_flag = 0;
               } else {
                  if (duty1 < -20) {
                     duty1 += 2;
                     duty2 += 2;
                  }
               }
            }
         }
}

void back_detection(){
   if (r_counter == 0 && duty1 > -30 && duty1 < 0) {
            if (rear_dist < 15.000) {
               duty1 = 1;
               duty2 = 1;
               r_counter = 1;
               auto_park = 0;
               back_flag = 0;
               do_parking = 0;
               buzzer_flag=1;

            }
         } else if ((r_counter == 0) && (duty1 <= -30) && (duty1 < 0)) {
            if (rear_dist < 45.000) {
               duty1 = 1;
               duty2 = 1;
               r_counter = 1;
               auto_park = 0;
               back_flag = 0;
               do_parking = 0;
               buzzer_flag=2;
            }
         }
         if (r_counter == 1 && rear_dist >= 15.000) {
            r_counter = 0;
         }
}

void front_detection(){
   if (duty1 < 40 && duty1 > 0) {
            if (f_counter == 0 && front_dist < 500 && front_dist != -2) //8cm 미만
                  {
               duty1 = 1;
               duty2 = 1;
               f_counter = 1;
            }
         } else if (duty1 < 60 && duty1 > 0) {
            if (f_counter == 0 && front_dist < 700 && front_dist != -2) //8cm 미만
                  {
               duty1 = 1;
               duty2 = 1;
               f_counter = 1;
            }
         } else if (duty1 > 60 && duty1 > 0) {
            if (f_counter == 0 && front_dist < 1000 && front_dist != -2) //8cm 미만
                  {
               duty1 = 1;
               duty2 = 1;
               f_counter = 1;
            }
         }
         if (f_counter == 1 && front_dist >= 500) {
            f_counter = 0;
         }
}

void buzzer_setting(){
   if (drive == 1) {

            if(buzzer_flag>0){
               setBeepCycle(1);
            }
            else{
               if (duty1 > -30) {
                  if (rear_dist <= 33.00) {
                     setBeepCycle(100);
                  } else if (rear_dist <= 45.00) {
                     setBeepCycle(300);
                  } else {
                     setBeepCycle(0);
                  }
               }
               if (duty1 < -30) {
                  if (rear_dist <= 90.00) {
                     setBeepCycle(100);
                  } else if (rear_dist <= 135.00) {
                     setBeepCycle(300);
                  } else {
                     setBeepCycle(0);
                  }
               }

            }
         }
}

void avoid_operation(){
   if (avoid_flag == 1) {
            if ((right_dist < 15.000 || left_dist < 15.000) && auto_park == 0
                  && do_parking == 0 && drive == 1) {
               if (left_dist < 15.000 && right_dist < 15.000) {
                  speed1 = 100;
                  speed2 = 100;
               } else if (right_dist < 15.000) {
                  speed1 = 90;
                  speed2 = 30;
                  right_emer_cnt++;
               } else if (left_dist < 15.000) {
                  speed1 = 30;
                  speed2 = 90;
                  left_emer_cnt++;
               }
               emergency = 1;

            }
            // 회피기동 복구
            if ((right_dist >= 15.000 && left_dist >= 15.000) && emergency == 1
                  && drive == 1) {
               if (right_emer_cnt != 0) {
                  right_emer_cnt--;
                  speed1 = 30;
                  speed2 = 90;
               } else if (left_emer_cnt != 0) {
                  left_emer_cnt--;
                  speed1 = 90;
                  speed2 = 30;
               } else if (left_emer_cnt == 0 && right_emer_cnt == 0) {
                  emergency = 0;
               }
            }
         }
}

void direction_setting(){
   if (duty1 > 100) {
            duty1 = 100;
         } else if (duty1 < 0) {
            l_dir = 1;
            speed1 = -duty1;
         } else if (duty1 > 0) {
            l_dir = 0;
            speed1 = duty1;
         }
         if (duty2 > 100) {
            duty2 = 100;
         } else if (duty2 < 0) {
            r_dir = 0;
            speed2 = -duty2;
         } else if (duty2 > 0) {
            r_dir = 1;
            speed2 = (duty2);
         }
}

void speed_setting(){
   if (left == 1) {
            speed1 = speed1 * 1.4;
            speed2 = speed2 * 0.35;
            left = 0;
            if (speed2 < 0) {
               speed2 = 0;
            }
         }
         if (right == 1) {
            speed1 = speed1 * 0.35;
            speed2 = speed2 * 2.1;

            right = 0;
            if (speed1 < 0) {
               speed1 = 0;
            }
         }
}

int main(void) {
   SYSTEM_Init();
   InterruptInit();
   _init_uart3();
   init_gpt1();
   init_gpt2();
   Init_DCMotors();
   Init_Bluetooth();
   Init_Ultrasonics();
   Init_ToF();
   Init_Buzzer();


   runGpt12_T6();


   while (1) {
      ch = getBluetoothByte_nonBlocked();

      if (ch >= 0) {
         keyborad_ctrl();
      }

      rear_dist = ReadRearUltrasonic_Filt();
      left_dist = ReadLeftUltrasonic_Filt();
      right_dist = ReadRightUltrasonic_Filt();
      front_dist = getTofDistance();

      auto_parking();

      //후방 초음파
      back_detection();

      //부저
//      buzzer_setting();

      //전방 레이저
      front_detection();

      // 회피기동
      avoid_operation();

      // 방향 전환
      direction_setting();
      // 속도 설정
      speed_setting();

      bl_printf(" %d,   %d,    %.5f,  %.5f,   %d,  %.5f,  %d,  %d,   %d \n", duty2,
               duty1, rear_dist, left_dist, left_emer_cnt, right_dist,
               right_emer_cnt, cnt, front_dist);


      movChA_PWM(speed1, l_dir);            //오른쪽
      movChB_PWM(speed2, r_dir);            //왼쪽
      setBluetoothByte_Blocked(ch);
   }
   return 0;
}
