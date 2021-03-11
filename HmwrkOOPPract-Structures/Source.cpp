#include<iostream>
#include<cstring>

using namespace std;


enum Jedi_Rank {
	Youngling,
	Padawan,
	Service_Corps,
	Knight,
	Consular,
	Guardian,
	Sentinel,
	Master,
	Council_Member,
	Master_Of_The_Order,
	Grand_Master
};

class Jedi {
private:
	char* name;
	//Rank rank;
	Planet planet;
	double midichlorian;
	char* spicies;
	char* militaryRank;
public:
	Jedi() {
		name = nullptr;
		planet.planet_name = nullptr;
		midichlorian = 0;
		spicies = nullptr;
		militaryRank = nullptr;
	}

	Jedi& operator=(Jedi& other) {
		if (this != &other) {
			delete[] name;
			delete[] planet.planet_name;
			delete[] spicies;
			delete[] militaryRank;
				this->name = new char[strlen(other.name) + 1];
				strcpy_s(this->name, strlen(other.name) + 1, other.name);

				this->planet.planet_name = new char[strlen(other.planet.planet_name) + 1];
				strcpy_s(this->planet.planet_name, strlen(other.planet.planet_name) + 1, other.planet.planet_name);

				this->midichlorian = other.midichlorian;

				this->spicies = new char[strlen(other.spicies) + 1];

				strcpy_s(this->spicies, strlen(other.spicies) + 1, other.spicies);
				this->militaryRank = new char[strlen(other.militaryRank) + 1];

				strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
		}
		return *this;
	}

	Jedi(const char* name_, double midichlorian_ , const char* planet_ ,const char* spicies_ ,const char* militaryRank_) {
		name = new char[strlen(name_) + 1];
		strcpy_s(this->name, strlen(name_) + 1, name_);

		midichlorian = midichlorian_;

		planet.planet_name = new char [strlen(planet_) + 1];
		strcpy_s(planet.planet_name, strlen(planet_) + 1, planet_);

		spicies = new char[strlen(spicies_) + 1];
		strcpy_s(spicies, strlen(spicies_) + 1, spicies_);

		militaryRank = new char[strlen(militaryRank_) + 1];
		strcpy_s(militaryRank, strlen(militaryRank_) + 1, militaryRank_);
	}


	~Jedi() {
		delete[] name;
		delete[] planet.planet_name;
		delete[] spicies;
		delete[] militaryRank;
	}

	void set_name(char* _name) {
		this->name = _name;
	}
	void set_planetname(Planet _planet_name) {
		this->planet.planet_name = _planet_name.planet_name;
	}
	void set_midichlorian(double _midichlorian) {
		this->midichlorian = _midichlorian;
	}
	void set_spicies(char* _spicies) {
		this->spicies = _spicies;
	}
	void set_militaryRank(char* _militaryRank) {
		this->militaryRank = _militaryRank;
	}


	const char* get_name() {
		return name;
	}
	const double get_midichlorian() {
		return midichlorian;
	}
	const char* get_planet() {
		return planet.planet_name;
	}
	const char* get_spicies() {
		return spicies;
	}
	const char* get_militaryRank() {
		return militaryRank;
	}

	void print() {
		cout << "The Jedi's name is: " << name << endl;
		cout << "Jedi's mid-ichlorian power is: " << midichlorian << endl;
		cout << "The planet he's from is: " << planet.planet_name << endl;
		cout << "The Jedi is a: " << spicies << endl;
		cout << "His military rank is: " << militaryRank << endl;
	}

};

class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
public:
	Planet() {
		name = nullptr;
		planetSystem = nullptr;
		republic = nullptr;
	}
	Planet(const char* name_, const char* planetSystem_, const char* republic_) {
		
	}
};










int main() {
	Jedi guy("Obiwan", 6.50 , "Earth" , "Human", "Jesus");
	guy.print();
	Jedi someone("Tisho", 1.80, "Zemq", "4ovek", "GospoT");
	guy = someone;
	guy.print();
	return 0;
}