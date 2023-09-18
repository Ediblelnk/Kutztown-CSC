#ifndef DIE_H
#define DIE_H

class Die {
 public:
  Die(int s = 6, bool p = false);
  Die(const Die&);

  void rollDie();
  int viewRoll();
  void changeSides(int num);

  bool operator>(Die &d);
  bool operator>=(Die &d);
  bool operator==(Die &d);

 private:
  int sides;
  int roll;
  bool print;
};

#endif
