#pragma once
#include<iostream>
#include<cstring>
using namespace std;
enum Planet_Type {
	Basic,
	Chtrorian,
	Carbon,
	Coreless,
	Desert,
	Gas_dwarf,
	Gas_giant,
	Helium,
	Ice_giant,
	Ice,
	Iron,
	Lava,
	Ocean,
	Protoplanet,
	Puffy,
	Silicate,
	Terrestial
};




class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
	//Planet_Type type;
public:
	Planet();
	Planet(const char* name_, const char* planetSystem_, /*Planet_Type type ,*/ const char* republic_);
	//char* PlanetType(Planet_Type kekw);
	void Del_Planet();
	void set_name(const char* name_);
	void set_planetSystem(const char* planetSystem_);
	//void set_type(const Planet_Type type_);
	void set_republic(const char* republic_);
	char* get_name();
	char* get_planetSystem();
	//Planet_Type get_type();
	char* get_republic();
	bool operator==(Planet& other);
	Planet& operator=(Planet& other);
	friend ostream& operator<<(ostream& out, Planet& other);
	void print();
};