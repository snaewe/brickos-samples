/* motors.c */

#include <unistd.h>
#include <dmotor.h>
#include <conio.h>

int main(int argc, char* argv[])
{
  int k;

  lcd_clear();

  /* start the motors */
  motor_a_dir(fwd);
  motor_a_speed(MAX_SPEED);

  motor_c_dir(fwd);
  motor_c_speed(MAX_SPEED);

  /* slow down motor gradually */
  for(k=MAX_SPEED; k>=0; --k) {
    lcd_int(k);
    motor_a_speed(k);
    msleep(20);
  }

  motor_a_dir(off);
  motor_c_dir(off);
  return 0;
}
