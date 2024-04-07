#include <iostream>
#include "cities.h"


void Cities::free()
{
	delete[] name;
	delete[] country;
}

char* Cities::copy(const char* copyFrom)
{

	int copyFromLen = std::strlen(copyFrom);

	char* copyTo = new char[copyFromLen + 1] {}; //пренасочваме пойнтъра към нов заделен масив
	std::strcpy(copyTo, copyFrom); //записваме данните в него

	return copyTo;
}

void Cities::copyFrom(const Cities& other)
{
	//не са ни нужни валидации, тъй като щом other е от тип Cities,
	//то това гарантира, че се е създал и данните в него са валидни
	copy(other.name);
	
	this->population = other.population;

	copy(other.country);

}

//използваме обоснованите практики в cities.h 
//за създаването на getter-и и setter-и
void Cities::setName(const char* name)
{
	if (!name) //nullptr проверка [!]
	{
		std::strcpy(this->name, "Unknown");
	}

	else
	{
		this->name = copy(name);//тъй като може да се счупи при два поредни setter-a,
		                         //при които при втория подаваме по-голям масив, е необходимо
		                         //да заделим паметта наново
	}

}

void Cities::setCountry(const char* country)
{
	if (!country) //nullptr проверка [!]
	{
		std::strcpy(this->country, "Unknown");
	}

	else
	{
		this->country = copy(country); //тъй като може да се счупи при два поредни setter-a,
									   //при които при втория подаваме по-голям масив, е необходимо
									   //да заделим паметта наново
	}	

}

void Cities::setPopulation(int population)
{
	if (population < 0) //няма как да имаме отрицателно население (освен ако не става сума за Перник)
	{
		this->population = 0;
	}

	else
	{
		this->population = population;
	}
}

const char* Cities::getName() const
{
	return this->name;

}

int Cities::getPopulation() const
{
	return this->population;
}

const char* Cities::getCountry() const
{
	return this->country;

}


Cities::Cities(const char* name, int population, const char* country)
{
	setName(name);
	setPopulation(population);
	setCountry(country);
}

Cities::Cities(const Cities& other)
{
	copyFrom(other);
}

Cities& Cities::operator=(const Cities& other)
{
	if (this != &other) //ЗАДЪЛЖИТЕЛНА проверка дали не присвояваме
						//на обекта самия себе си
	{
		free(); //трием старите данни (поради това, че имаме динамични член-данни
		        //и сме длъжни да освободим паметта, която няма да използваме повече)

		copyFrom(other);
	}

	return *this;
}

Cities::~Cities()
{
	delete[] name; //освобождаваме динамично заделената памет
	delete[] country;

	name = nullptr;
	country = nullptr;
}
