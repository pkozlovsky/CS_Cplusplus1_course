#include <iostream>

class Tricycle
{
public:
     Tricycle(int initialSpeed = 0); // konstruktor z predkoscia poczatkowa (domsylna)
     ~Tricycle(); // destruktor klasy

     int getSpeed();
     void setSpeed(int speed);
     void pedal();
     void brake();

private:
    int speed;
};

// Implementacja konstruktora
Tricycle::Tricycle(int initialSpeed) 
{
    if (initialSpeed >= 0) 
    {
        speed = initialSpeed;
    } 
    else 
    {
        speed = 0;
        std::cout << "Ustawiono początkową prędkość na 0, ponieważ podano wartość ujemną.\n";
    }
}

// Implementacja destruktora
Tricycle::~Tricycle() 
{
    std::cout << "Obiekt Tricycle został zniszczony.\n";
}

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
    Tricycle wichita(10); 
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();
    return 0;
}
