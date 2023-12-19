// kod źródłowy programu Tricycle.cpp
#include <iostream>

class Tricycle
{
public:
     int getSpeed();
     void setSpeed(int speed);
     void pedal();
     void brake();
private:
int speed;
};

// Pobranie szybkości, z jaką porusza się rower.
int Tricycle::getSpeed()
{
return speed;
}

// Zdefiniowanie szybkości, z jaką porusza się rower. 
void Tricycle::setSpeed(int newSpeed)
{
    if (newSpeed >= 0)
    {
         speed = newSpeed;
    }
}

// Jazda rowerem trójkołowym. 
void Tricycle::pedal()
{
     setSpeed(speed + 1);
std::cout << "\nJazda rowerem trójkołowym, szybkość wynosi" << speed << " km/h.\n";
}

// Użycie hamulców w rowerze trójkołowym. 
void Tricycle::brake()
{
    setSpeed(speed - 1);
    std::cout << "\nHamowanie rowerem trójkołowym, szybkość wynosi " << speed <<" km/h.\n";
    
}

// Utworzenie egzemplarza roweru i jego wypróbowanie. 
int main()
{
    Tricycle wichita;
    wichita.setSpeed(0);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();
return 0;
}
