#pragma once
#include<iostream>
#include<cstring>
#include"Planet.cpp"
using namespace std;
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

class Stormtrooper {
private:
	char* id;
	Stormtrooper_Rank rank;
	char* type;
	Planet* planet;
public:
	Stormtrooper();
	Stormtrooper(const char* id_, const Stormtrooper_Rank rank_, const char* type_, Planet* planet_);
	~Stormtrooper();
	bool operator==(Stormtrooper& other);
	Stormtrooper& operator=(Stormtrooper& other);
	friend ostream& operator<<(ostream& out, Stormtrooper& other);
	void set_id(const char* id_);
	void set_rank(Stormtrooper_Rank rank_);
	void set_type(const char* type_);
	void set_planet(Planet* planet_);
	const char* get_id();
	const Stormtrooper_Rank get_rank();
	const char* get_type();
	const char* get_planet();
	void print();
};