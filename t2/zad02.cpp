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
    std::cout << "\nJazda rowerem trójkołowym, szybkość wynosi " << speed << " km/h.\n";
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
    Tricycle rower1;
    rower1.setSpeed(0);
    rower1.pedal();
    rower1.pedal();
    rower1.brake();
    rower1.brake();
    rower1.brake();
    rower1.brake();
    rower1.brake();

    Tricycle rower2;
    rower2.setSpeed(5);
    rower2.pedal();
    rower2.pedal();
    rower2.brake();
    rower2.brake();
    rower2.brake();
    rower2.brake();
    rower2.brake();
    return 0;
}
