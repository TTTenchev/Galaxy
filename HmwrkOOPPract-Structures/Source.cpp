#include<iostream>
#include<cstring>

using namespace std;


enum Jedi_Rank {
	Basic_Being,
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

enum Stormtrooper_Rank {
	Basic_Fighter,
	Cadet,
	Private,
	Lance_Corporal,
	Corporal,
	Sergeant,
	Staff_Sergeant,
	Master_Sergeant
};

class Planet {
public:
	char* name;
	char* planetSystem;
	char* republic;
	Planet() {
		name = nullptr;
		planetSystem = nullptr;
		republic = nullptr;
	}
	Planet(const char* name_, const char* planetSystem_, const char* republic_) {
		name = new char[strlen(name_) + 1];
		strcpy_s(name, strlen(name_) + 1, name_);
		planetSystem = new char[strlen(planetSystem_) + 1];
		strcpy_s(planetSystem, strlen(planetSystem_) + 1, planetSystem_);
		republic = new char[strlen(republic_) + 1];
		strcpy_s(republic, strlen(republic_) + 1, republic_);
	}
	void Del_Planet() {
		delete[] name;
		delete[] planetSystem;
		delete[] republic;
	}
	void set_name(char* name_) {
		this->name = name_;
	}
	void set_planetSystem(char* planetSystem_) {
		this->planetSystem = planetSystem_;
	}
	void set_republic(char* republic_) {
		this->republic = republic_;
	}
	char* get_name() {
		return name;
	}
	char* get_planetSystem() {
		return planetSystem;
	}
	char* get_republic() {
		return republic;
	}
	bool operator==(Planet& other) {
		return strcmp(this->name, other.name) && strcmp(this->planetSystem, other.planetSystem) && strcmp(this->republic, other.republic);
	}
	Planet& operator=(Planet& other) {
		if (this != &other) {
			delete[] name;
			delete[] planetSystem;
			delete[] republic;
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);

			planetSystem = new char[strlen(other.planetSystem) + 1];
			strcpy_s(planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);

			republic = new char[strlen(other.republic) + 1];
			strcpy_s(republic, strlen(other.republic) + 1, other.republic);
		}
		return *this;
	}
	void print() {
		cout << "The name of the planet is: " << name << endl;
		cout << "The name of the planet system is: " << planetSystem << endl;
		cout << "The name of the republic is: " << republic << endl;
	}
};
class Jedi {
private:
	char* name;
	double midichlorian;
	Planet* planet;
	Jedi_Rank rank;
	char* spicies;
	char* militaryRank;
public:
	Jedi() {
		name = nullptr;
		planet = NULL;
		rank = Basic_Being;
		midichlorian = 0;
		spicies = nullptr;
		militaryRank = nullptr;
	}

	Jedi& operator=(Jedi& other) {
		if (this != &other) {
			delete[] name;
			planet = NULL;
			delete[] spicies;
			delete[] militaryRank;

				this->name = new char[strlen(other.name) + 1];
				strcpy_s(this->name, strlen(other.name) + 1, other.name);

				this->rank = other.rank;

				this->planet = other.planet;

				this->midichlorian = other.midichlorian;

				this->spicies = new char[strlen(other.spicies) + 1];

				strcpy_s(this->spicies, strlen(other.spicies) + 1, other.spicies);
				this->militaryRank = new char[strlen(other.militaryRank) + 1];

				strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
		}
		return *this;
	}
	bool operator==(Jedi& other) {
		return strcmp(this->name, other.name) && this->midichlorian == other.midichlorian &&(this->rank == other.rank) && strcmp(this->spicies, other.spicies) && strcmp(this->militaryRank, other.militaryRank);
	}

	Jedi(const char* name_, double midichlorian_ , Planet* planet_, const Jedi_Rank rank_, const char* spicies_ ,const char* militaryRank_) {

		name = new char[strlen(name_) + 1];
		strcpy_s(this->name, strlen(name_) + 1, name_);

		rank = rank_;

		midichlorian = midichlorian_;

		planet = planet_;


		spicies = new char[strlen(spicies_) + 1];
		strcpy_s(spicies, strlen(spicies_) + 1, spicies_);

		militaryRank = new char[strlen(militaryRank_) + 1];
		strcpy_s(militaryRank, strlen(militaryRank_) + 1, militaryRank_);
	}


	~Jedi() {
		delete[] name;
		planet = NULL;
		delete[] spicies;
		delete[] militaryRank;
	}

	void set_name(char* _name) {
		this->name = _name;
	}
	void set_planet(Planet* _planet_name) {
		this->planet = _planet_name;
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
	const Jedi_Rank get_rank() {
		return rank;
	}
	const double get_midichlorian() {
		return midichlorian;
	}
	const Planet* get_planet() {
		return planet;
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
		planet->print();
		cout << "His rank level is: " << rank << endl;
		cout << "The Jedi is a: " << spicies << endl;
		cout << "His military rank is: " << militaryRank << endl;
	}

};
class Stormtrooper {
private:
	char* id;
	Stormtrooper_Rank rank;
	char* type;
	Planet* planet;
public:
	Stormtrooper() {
		id = nullptr;
		rank = Basic_Fighter;
		type = nullptr;
		planet = NULL;
	}
	Stormtrooper(const char* id_, const Stormtrooper_Rank rank_, const char* type_, Planet* planet_) {
		id = new char[strlen(id_) + 1];
		strcpy_s(id, strlen(id_) + 1, id_);
		
		rank = rank_;

		type = new char[strlen(type_) + 1];
		strcpy_s(type, strlen(type_) + 1, type_);

		planet = planet_;
	}

	~Stormtrooper() {
		delete[] id;
		delete[] type;
		planet = NULL;
	}

	bool operator==(Stormtrooper& other) {
		return strcmp(this->id, other.id) && (this->rank == other.rank) && strcmp(this->type, other.type) && planet == other.planet;
	}
	Stormtrooper& operator=(Stormtrooper& other) {
		if (this != &other) {
			delete[] id;
			delete[] type;
			planet = NULL;
				id = new char[strlen(other.id) + 1];
				strcpy_s(id, strlen(other.id) + 1, other.id);
				
				this->rank = other.rank;

				type = new char[strlen(other.type) + 1];
				strcpy_s(type, strlen(other.type) + 1, other.type);

				planet = other.planet;
		}
		return *this;
	}

	void set_id(char* id_) {
		this->id = id_;
	}
	void set_rank(Stormtrooper_Rank rank_) {
		this->rank = rank_;
	}
	void set_type(char* type_) {
		this->type = type_;
	}
	void set_planet(Planet* planet_) {
		this->planet = planet_;
	}
	const char* get_id() {
		return id;
	}
	const Stormtrooper_Rank get_rank() {
		return rank;
	}
	const char* get_type() {
		return type;
	}
	const Planet* get_planet() {
		return planet;
	}
	void print() {
		cout << "Stormtrooper's id is: " << id << endl;
		cout << "Stormtrooper's rank is: " << rank << endl;
		cout << "Stormtrooper's type is: " << type << endl;
		planet->print();
	}
};









int main() {
	Planet Payner("Zemq", "Sluncheva", "Bulgaria");
	Payner.print();
	Jedi guy("Obiwan", 6.50 , &Payner, Youngling, "Human", "Jesus");
	guy.print();
	Jedi someone("Tisho", 1.90 , &Payner ,Padawan, "4ovek", "GospoT");
	guy = someone;
	Stormtrooper Ogi("Azazel", Cadet, "tip nqkuv", &Payner);
	Ogi.print();
	guy.print();
	Payner.Del_Planet();
	return 0;
}