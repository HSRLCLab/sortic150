#ifndef Placer_h
#define Placer_h

#include <Arduino.h>
#include <Actor.h>
#include <SoftwareSerial.h>

enum PlacerPosition
{
  PickUpLeft = 1,
  DropLeft = 4,
  Front = 5,
  DropRight = 6,
  PickUpRight = 9
};

class Placer : public Actor<PlacerPosition>
{
public:
  Placer(SoftwareSerial &bluetooth) : bluetooth{bluetooth}, motorIsOn{false} {}

protected:
  PlacerPosition loop();

private:
  // todo.. weshalb soll der motor hier und nicht beim greifarm selbst reguliert werden?
  bool motorIsOn;
  SoftwareSerial &bluetooth;
};

#endif