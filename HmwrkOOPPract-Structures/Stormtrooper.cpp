#pragma once
#include<iostream>
#include"Stormtrooper_Header.h"
#include<cstring>
#include"Planet.cpp"
using namespace std;

Stormtrooper::Stormtrooper() {
	id = nullptr;
	rank = Basic_Fighter;
	type = nullptr;
	planet = NULL;
}

Stormtrooper::Stormtrooper(const char* id_, const Stormtrooper_Rank rank_, const char* type_, Planet* planet_) {
	id = new char[strlen(id_) + 1];
	strcpy_s(id, strlen(id_) + 1, id_);

	rank = rank_;

	type = new char[strlen(type_) + 1];
	strcpy_s(type, strlen(type_) + 1, type_);

	planet = planet_;
}

Stormtrooper::~Stormtrooper() {
	delete[] id;
	delete[] type;
	planet = NULL;
}

bool Stormtrooper::operator==(Stormtrooper& other) {
	return strcmp(this->id, other.id) && (this->rank == other.rank) && strcmp(this->type, other.type) && planet == other.planet;
}

Stormtrooper& Stormtrooper::operator=(Stormtrooper& other) {
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

void Stormtrooper::set_id(const char* id_) {
	if (id != nullptr) {
		delete[] id;
	}
	id = new char[strlen(id_) + 1];
	strcpy_s(id, strlen(id_) + 1, id_);
}

void Stormtrooper::set_rank(Stormtrooper_Rank rank_) {
	this->rank = rank_;
}

void Stormtrooper::set_type(const char* type_) {
	if (type != nullptr) {
		delete[] type;
	}
	type = new char[strlen(type_) + 1];
	strcpy_s(type, strlen(type_) + 1, type_);
}

void Stormtrooper::set_planet(Planet* planet_) {
	this->planet = planet_;
}

ostream& operator<<(ostream& out, Stormtrooper& other) {
	out << other.get_id() << endl;
	out << other.get_planet() << endl;
	out << other.get_rank() << endl;
	out << other.get_type() << endl;
	return out;
}

const char* Stormtrooper::get_id() {
	return this->id;
}

const Stormtrooper_Rank Stormtrooper::get_rank() {
	return this->rank;
}

const char* Stormtrooper::get_type() {
	return this->type;
}

const char* Stormtrooper::get_planet() {
	return this->planet->get_name();
}

void Stormtrooper::print() {
	cout << *this << endl;
}
