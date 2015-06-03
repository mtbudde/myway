int pTerm, iTerm, dTerm;
int Kp = 4;  //Good level
int Ki = 0;
int Kd = 5;
int integrated_error = 0;
int last_error = 0;
int GUARD_GAIN = 20;
float K = .5;

int updatePid(int targetPosition, int currentPosition)   {
  int error = targetPosition - currentPosition;
  pTerm = Kp * error;
  integrated_error += error;
  iTerm = Ki * constrain(integrated_error, -GUARD_GAIN, GUARD_GAIN);
  dTerm = Kd * (error - last_error);
  last_error = error;
  return -constrain(K*(pTerm + iTerm + dTerm), -127, 127);
}
