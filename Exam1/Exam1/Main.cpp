#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};

	// STEP 1: Complete the implementation of the Vehicle base class 
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:
		Vehicle(string color) {
			_color = color;
		}
		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle{
	public:
		RaceCar(string color):Vehicle(color)
		{
			_color = color;
			_topspeed = 250;
			for (int i = 0; i < wheels.size(); i++)
				wheels[i] = Wheel(305);
		}

		void Description()
		{
			cout << "I am a " << _color << " race car that can race " << _topspeed << "mph. Vroom!" << endl;
		}
		//Top speed: 250mph
		//Wheel radius: 305mm

	};

	class Sedan : public Vehicle {
	private:
		int number_of_seats;
	public:
		Sedan(string color, int seats):Vehicle(color)
		{
			_color = color;
			number_of_seats = seats;
			_topspeed = 95;
			for (int i = 0; i < wheels.size(); i++)
				wheels[i] = Wheel(381);
		}
		void Description()
		{
			cout << "I am a " << _color << " sedan that can carry " << number_of_seats <<
				" people at " << _topspeed << "mph. Yea!" << endl;
		}
		//Top speed: 95mph
		//Wheel radius: 381mm

	};

	class Pickup : public Vehicle {
	private:
		int hauling_capacity;
	public:
		Pickup(string color, int capacity):Vehicle(color)
		{
			_color = color;
			hauling_capacity = capacity;
			_topspeed = 85;
			for (int i = 0; i < wheels.size(); i++)
			{
				wheels[i] = Wheel(432);
			}
		}

		void Description()
		{
			cout << "I am a " << _color << " pickup that can haul " << hauling_capacity <<
				"sq. feet at " << _topspeed << "mph." << endl;
		}
		//Top speed: 85mph
		//Wheel radius: 432mm

	};
}


int main()
{
	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = new Exam1::RaceCar("red");
	Garage[1] = new Exam1::Sedan("beige", 13);
	Garage[2] = new Exam1::Pickup("mahagony", 90);

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}
	return 0;
}
