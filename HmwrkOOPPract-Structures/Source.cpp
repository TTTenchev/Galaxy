#include<iostream>
#include<cstring>
#include"Planet.cpp"
#include"Jedi.cpp"
#include"Stormtrooper.cpp"
using namespace std;

int main() {
	/*Planet Payner("Zemq", "Sluncheva", "Bulgaria");
	Payner.print();
	Jedi guy("Obiwan", 6.50, &Payner, Youngling, "Human", "Jesus");
	guy.print();
	Jedi someone("Tisho", 1.90, &Payner, Padawan, "4ovek", "GospoT");
	guy = someone;
	Stormtrooper Ogi("Azazel", Cadet, "tip nqkuv", &Payner);
	Ogi.print();
	guy.print();
	Payner.Del_Planet();*/

	Planet Payner; 

	Payner.set_name("Rishi");
	Payner.set_planetSystem("Rishi system");
	//Payner.set_type(Carbon);
	Payner.set_republic("Republic Navy");
	Payner.print();

	Jedi Yoda;
	Yoda.set_name("Yoda");
	Yoda.set_rank(Grand_Master);
	Yoda.set_midichlorian(17700);
	Yoda.set_planet(&Payner);
	Yoda.set_spicies("Yoda's species");
	Yoda.set_militaryRank("General");
	Yoda.print();

	Stormtrooper Someone;
	Someone.set_id("LS-005");
	Someone.set_rank(Sergeant);
	Someone.set_type("magma trooper");
	Someone.set_planet(&Payner);
	Someone.print();


	cout << "This is someone: " << endl;
	cout << Someone << endl;
	cout << "This is planet: " << endl;
	cout << Payner << endl;
	cout << "This is Yoda: " << endl;
	cout << Yoda << endl;
	return 0;
}