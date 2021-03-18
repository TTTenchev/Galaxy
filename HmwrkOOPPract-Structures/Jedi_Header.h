#pragma once
#include<iostream>
#include<cstring>
#include"Planet.cpp"
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

class Jedi {
private:
	char* name;
	double midichlorian;
	Planet* planet;
	Jedi_Rank rank;
	char* spicies;
	char* militaryRank;
public:
	Jedi();

	Jedi& operator=(Jedi& other);
	bool operator==(Jedi& other);
	friend ostream& operator<<(ostream& out, Jedi& other);

	Jedi(const char* name_, double midichlorian_, Planet* planet_, const Jedi_Rank rank_, const char* spicies_, const char* militaryRank_);
	~Jedi();

	void set_name(const char* _name);
	void set_rank(const Jedi_Rank _rank);
	void set_planet(Planet* _planet_name);
	void set_midichlorian(const double _midichlorian);
	void set_spicies(const char* _spicies);
	void set_militaryRank(const char* _militaryRank);

	const char* get_name();
	const Jedi_Rank get_rank();
	const double get_midichlorian();
	const char* get_planet();
	const char* get_spicies();
	const char* get_militaryRank();

	void print();
};