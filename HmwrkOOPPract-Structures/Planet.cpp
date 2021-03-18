#pragma once
#include<iostream>
#include<cstring>
#include"Planet_Header.h"
using namespace std;



Planet::Planet() {
	name = nullptr;
	planetSystem = nullptr;
	//type = Basic;
	republic = nullptr;
}
Planet::Planet(const char* name_, const char* planetSystem_, /*Planet_Type type_,*/ const char* republic_) {
	name = new char[strlen(name_) + 1];
	strcpy_s(name, strlen(name_) + 1, name_);
	//type = type_;
	planetSystem = new char[strlen(planetSystem_) + 1];
	strcpy_s(planetSystem, strlen(planetSystem_) + 1, planetSystem_);
	republic = new char[strlen(republic_) + 1];
	strcpy_s(republic, strlen(republic_) + 1, republic_);
}
/*char* Planet::PlanetType(Planet_Type kekw) {
	char typeOfPlanet[32];
	switch (kekw) {
	case Chtrorian: strcpy_s(typeOfPlanet, strlen("Chtronian") + 1, "Chtronian"); break;
	case Carbon: strcpy_s(typeOfPlanet, strlen("Carbon") + 1, "Carbon"); break;
	case Coreless: strcpy_s(typeOfPlanet, strlen("Coreless") + 1, "Coreless"); break;
	case Desert: strcpy_s(typeOfPlanet, strlen("Desert") + 1, "Desert"); break;
	}
	return typeOfPlanet;
}*/
void Planet::Del_Planet() {
	delete[] name;
	delete[] planetSystem;
	//type = Basic;
	delete[] republic;
}
void Planet::set_name(const char* name_) {
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(name_) + 1];
	strcpy_s(this->name, strlen(name_) + 1, name_);
}
void Planet::set_planetSystem(const char* planetSystem_){
	if (planetSystem != nullptr) {
		delete[] planetSystem;
	}
	planetSystem = new char[strlen(planetSystem_) + 1];
	strcpy_s(this->planetSystem, strlen(planetSystem_)+ 1,planetSystem_);
}
/*void Planet::set_type(const Planet_Type type_) {
	type = type_;
}*/
void Planet::set_republic(const char* republic_){
	if (republic != nullptr) {
		delete[] republic;
	}
	republic = new char[strlen(republic_) + 1];
	strcpy_s(this->republic, strlen(republic_) + 1, republic_);
}
char* Planet::get_name(){
	return name;
}
char* Planet::get_planetSystem(){
	return planetSystem;
}
/*Planet_Type Planet::get_type() {
	return type;
}*/
char* Planet::get_republic(){
	return republic;
}
bool Planet::operator==(Planet& other){
	return strcmp(this->name, other.name) && strcmp(this->planetSystem, other.planetSystem) && strcmp(this->republic, other.republic);
}
Planet& Planet::operator=(Planet& other) {
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
ostream& operator<<(ostream& out, Planet& other) {
	out << other.get_name() << endl;
	out << other.get_planetSystem() << endl;
	//out << Planet::PlanetType(other.get_type()) << endl;
	out << other.get_republic() << endl;
	return out;
}
void Planet::print() {
	cout << *this << endl;
}