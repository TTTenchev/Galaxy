#pragma once
#include<iostream>
#include"Jedi_Header.h"
#include<cstring>
#include"Planet.cpp"
using namespace std;

Jedi::Jedi() {
	name = nullptr;
	planet = NULL;
	rank = Basic_Being;
	midichlorian = 0;
	spicies = nullptr;
	militaryRank = nullptr;
}

Jedi& Jedi::operator=(Jedi& other) {
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

bool Jedi::operator==(Jedi& other) {
	return strcmp(this->name, other.name) && this->midichlorian == other.midichlorian && (this->rank == other.rank) && strcmp(this->spicies, other.spicies) && strcmp(this->militaryRank, other.militaryRank);
}

ostream& operator<<(ostream& out, Jedi& other) {
	out << other.get_name() << endl;
	out << other.get_rank() << endl;
	out << other.get_planet() << endl;
	out << other.get_midichlorian() << endl;
	out << other.get_spicies() << endl;
	out << other.get_militaryRank() << endl;
	return out;
}

Jedi::Jedi(const char* name_, double midichlorian_, Planet* planet_, const Jedi_Rank rank_, const char* spicies_, const char* militaryRank_) {

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

Jedi::~Jedi() {
	delete[] name;
	planet = NULL;
	delete[] spicies;
	delete[] militaryRank;
}

void Jedi::set_name(const char* _name) {
	name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Jedi::set_rank(const Jedi_Rank _rank) {
	rank = _rank;
}

void Jedi::set_planet(Planet* _other_planet) {
	this->planet = _other_planet;
}
void Jedi::set_midichlorian(const double _midichlorian) {
	this->midichlorian = _midichlorian;
}
void Jedi::set_spicies(const char* _spicies) {
	spicies = new char[strlen(_spicies) + 1];
	strcpy_s(this->spicies, strlen(_spicies) + 1, _spicies);
}
void Jedi::set_militaryRank(const char* _militaryRank) {
	militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(_militaryRank) + 1, _militaryRank);
}


const char* Jedi::get_name() {
	return name;
}
const Jedi_Rank Jedi::get_rank() {
	return rank;
}
const double Jedi::get_midichlorian() {
	return midichlorian;
}
const char* Jedi::get_planet() {
	return planet->get_name();
}
const char* Jedi::get_spicies() {
	return spicies;
}
const char* Jedi::get_militaryRank() {
	return militaryRank;
}

void Jedi::print() {
	cout << *this << endl;
}