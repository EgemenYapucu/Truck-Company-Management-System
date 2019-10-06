/*Egemen YAPUCU
*18120205027
*Visual Studiomda sıkıntı olduğu için herşeyi tek bir dosyada attım hocam ayrı ayrı dosyalara ayırdığımda diğer dosyalara ulaşamıyorum ne yazık ki
*/
#define TIXML_USE_TICPP
#include <ostream>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <list>
using namespace std;
int strcount(char* Sayi) {
	int i = 0;
	while (Sayi[++i] != '\0');
	return i;
}
typedef enum{
	B,
	C,
	D,
	E,
}Ehliyettype;


class Driver{
	friend ostream operator<<(ostream& out, Driver& driver){
		out << "Driver: " << driver.getter_Ad() << "Driver Age: " << driver.getter_Yas() << "Driver License: ";
		if (driver.getter_Ehliyet() == 0)
			out << "B";
		else if (driver.getter_Ehliyet() == 1)
			out << "C";
		else if (driver.getter_Ehliyet() == 2)
			out << "D";
		else if (driver.getter_Ehliyet() == 3)
			out << "E";
		return out;
	}
	public:
		Driver(){
			Ad = nullptr;
		}
		Driver(char* surucu, unsigned yas, Ehliyettype ehliyet){
			setter_Ad(surucu);
			setter_Yas(yas);
			setter_Ehliyet(ehliyet);
		}
		Driver(const Driver& other){
			setter_Ad(other.Ad);
			setter_Yas(other.Yas);
			setter_Ehliyet(other.Ehliyet);
		}
		Driver& operator=(const Driver& other){
			setter_Ad(other.Ad);
			setter_Yas(other.Yas);
			setter_Ehliyet(other.Ehliyet);
		}
		~Driver(){
			if (Ad != nullptr)
				delete[] Ad;
		}
		char* getter_Ad(){
			return Ad;
		}
		unsigned getter_Yas(){
			return Yas+30;
		}
		Ehliyettype getter_Ehliyet(){
			return Ehliyet;
		}
		void setter_Ad(char* Ad){
			if (this->Ad != nullptr)
				delete[] Ad;
			try{
				this->Ad = new char(strcount(Ad));
			}
			catch (const bad_alloc &e){
				cerr << e.what() << '\n';
			}
			for (int i = 0; i < strcount(Ad); ++i)
				this->Ad[i] = Ad[i];
		}
		void setter_Yas(unsigned Yas){
			this->Yas = Yas-30;
		}
		void setter_Ehliyet(Ehliyettype Ehliyet){
			this->Ehliyet = Ehliyet;
		}
	private:
		char* Ad;
		unsigned Yas : 5;
		Ehliyettype Ehliyet;
};
class Passenger{
	friend ostream operator<<(ostream& out, Passenger& passenger){
		out << "Passenger : " << passenger.getter_Name() << "Pick up point : " << passenger.getter_Pickup()
			<< "Destination : " << passenger.getter_Destin();
		return out;
	}
	public:
		Passenger(){
			Name = nullptr;
			PickupPoint = nullptr;
		}
		Passenger(const Passenger& other){
			setter_Name(other.Name);
			setter_Pickup(other.PickupPoint);
			setter_Destin(other.Destination);
		}
		~Passenger(){
			if (Name != nullptr)
				delete[] Name;
			if (PickupPoint != nullptr)
				delete[] PickupPoint;
		}
		Passenger& operator=(const Passenger& other){
			setter_Name(other.Name);
			setter_Pickup(other.PickupPoint);
			setter_Destin(other.Destination);
		}
		char* getter_Name(){
			return Name;
		}
		char* getter_Pickup(){
			return PickupPoint;
		}
		string getter_Destin(){
			return Destination;
		}
		void setter_Name(char* Name){
			if (this->Name != nullptr)
				delete[] Name;
			try {
				this->Name = new char(strcount(Name));
			}
			catch (const bad_alloc & e) {
				cerr << e.what() << '\n';
			}
			for (int i = 0; i < strcount(Name); ++i)
				this->Name[i] = Name[i];
		}
		void setter_Pickup(char* PickupPoint){
			if (this->PickupPoint != nullptr)
				delete[] PickupPoint;
			try{
				this->PickupPoint = new char(strcount(PickupPoint));
			}
			catch (const bad_alloc & e) {
				cerr << e.what() << '\n';
			}
			for (int i = 0; i < strcount(PickupPoint); ++i)
				this->PickupPoint[i] = PickupPoint[i];
		}
		void setter_Destin(string Destination){
			this->Destination = Destination;
		}
	private:
		char* Name;
		char* PickupPoint;
		string Destination;
};
class Package{
	friend ostream operator<<(ostream& out, Package& package){
		out << "Load : " << package.Load << "Weight : " << package.Weight << "Volume : " << package.Volume
			<< "Customer : " << package.Customer << "Pick up point : " << package.PickupPoint << "Destination : " << package.Destination;
	}
	public:
		Package(){
			Load = nullptr;
			Weight = 0;
			Volume = 0;
		}
		Package(char* load, double weight, double volume, string customer, string pickup, string destination){
			setter_Load(load);
			setter_Weight(weight);
			setter_Volume(volume);
			setter_Customer(customer);
			setter_Pickup(pickup);
			setter_Destination(destination);
		}
		Package(const Package& other){
			setter_Load(other.Load);
			setter_Weight(other.Weight);
			setter_Volume(other.Volume);
			setter_Customer(other.Customer);
			setter_Pickup(other.PickupPoint);
			setter_Destination(other.Destination);
		}
		~Package(){
			if (Load != nullptr)
				delete[] Load;
		}
		Package& operator=(const Package& other){
			setter_Load(other.Load);
			setter_Weight(other.Weight);
			setter_Volume(other.Volume);
			setter_Customer(other.Customer);
			setter_Pickup(other.PickupPoint);
			setter_Destination(other.Destination);
		}
		void setter_Load(char* Load){
			if (this->Load != nullptr)
				delete[] Load;
			try {
				this->Load = new char(strcount(Load));
			}
			catch (const bad_alloc & e) {
				cerr << e.what() << '\n';
			}
			for (int i = 0; i < strcount(Load); ++i)
				this->Load[i] = Load[i];
		}
		void setter_Weight(double Weight){
				this->Weight = Weight;
		}
		void setter_Volume(double Volume){
			this->Volume = Volume;
		}
		void setter_Customer(string Customer){
			this->Customer = Customer;
		}
		void setter_Pickup(string PickupPoint){
			this->PickupPoint = PickupPoint;
		}
		void setter_Destination(string Destination){
			this->Destination = Destination;
		}
		char* getter_Load()const{
			return Load;
		}
		double getter_Weight()const{
			return Weight;
		}
		double getter_Volume()const{
			return Volume;
		}
		string getter_Customer()const{
			return Customer;
		}
		string getter_Pickup()const{
			return PickupPoint;
		}
		string getter_Destination()const{
			return Destination;
		}

	private:
		char* Load;
		double Weight=0;
		double Volume=0;
		string Customer;
		string PickupPoint;
		string Destination;
};
class Vehicle{
	 friend Vehicle& operator<<(ostream& out,const Vehicle& vehicle){
		 return vehicle.printer(out);
	 }
	public:
		
		Vehicle(){
			Plate = nullptr;
			Drivers.clear();
		}
		Vehicle(char* Plate, list<Driver>Drivers){
			setter_Plate(Plate);
			setter_Drivers(Drivers);
		}
		Vehicle(const Vehicle& other){
			setter_Plate(other.Plate);
			setter_Drivers(other.Drivers);
		}
		Vehicle& operator=(const Vehicle& other){
			setter_Plate(other.Plate);
		}
		~Vehicle(){
			if (Plate != nullptr)
				delete[] Plate;
		}
		virtual ostream& printer(ostream& out)const = 0;
		void setter_Plate(char* Plate){
			if (this->Plate != nullptr)
				delete[] this->Plate;
			try{
				this->Plate = new char(strcount(Plate));
			}
			catch (const bad_alloc& e){
				cerr << e.what() << '\n';
			}
			for (int i = 0; i < strcount(Plate); ++i)
				this->Plate[i] = Plate[i];
		}
		char* getter_Plate()const{
			return Plate;
		}
		void setter_Drivers(list<Driver>Drivers){
			this->Drivers = Drivers;
		}
		list<Driver> getter_Drivers()const{
			return Drivers;
		}

	protected:
		char* Plate;
		list<Driver>Drivers;
		
};
class Bus:public Vehicle{
		Bus(){
			Plate = nullptr;
			Drivers.clear();
			Passengers.clear();
		}
		Bus(char* Plate, list<Driver>Drivers, vector<Passenger> Passengers){
			setter_Plate(Plate);
			setter_Drivers(Drivers);
			setter_Passengers(Passengers);
		}
		Bus(const Bus& other){
			setter_Plate(other.Plate);
			setter_Drivers(other.Drivers);
			setter_Passengers(other.Passengers);
		}
		~Bus(){
			if (Plate != nullptr)
				delete[] Plate;
		}
		Bus& operator=(const Bus& other){
			setter_Plate(other.Plate);
			setter_Drivers(other.Drivers);
			setter_Passengers(other.Passengers);
		}
		void setter_Passengers(vector<Passenger> Passengers) {
			this->Passengers.clear();
			this->Passengers = Passengers;
		}
		virtual ostream& printer(ostream& out)const{
			out << "Plate : " << getter_Plate() << endl << "Passengers : ";
			for (auto i = Passengers.begin(); i < Passengers.end(); ++i)
				out << *i << " ";
			out << endl;
			for (auto i = Drivers.begin(); i < Drivers.end(); ++i)
				out << *i << " ";
			return out;
		}
		vector<Passenger> getter_Passengers(){
			return Passengers;
		}
	private:
		vector<Passenger> Passengers;
};
class Lorry :public Vehicle{
	public:
	Lorry(){
		Plate = nullptr;
		Aphorism = nullptr;
		Drivers.clear();
	}
	Lorry(char* Plate, list<Driver>Drivers, vector<Package> Packages,char* Aphorism){
		setter_Plate(Plate);
		setter_Drivers(Drivers);
		setter_Packages(Packages);
		setter_Aphorism(Aphorism);
	}
	Lorry(const Lorry& other){
		setter_Plate(other.Plate);
		setter_Drivers(other.Drivers);
		setter_Packages(other.Packages);
		setter_Aphorism(other.Aphorism);
	}
	~Lorry(){
		if (Plate != nullptr)
			delete[] Plate;
		if (Aphorism != nullptr)
			delete[] Aphorism;
	}
	Lorry &operator=(const Lorry& other){
		setter_Plate(other.Plate);
		setter_Drivers(other.Drivers);
		setter_Packages(other.Packages);
		setter_Aphorism(other.Aphorism);
	}
	virtual ostream& printer(ostream& out)const {
		out << "Plate : " << getter_Plate() << endl << "Aphorism : " << getter_Aphorism() << endl << "Packages : ";
		for (auto i = Packages.begin(); i < Packages.end(); ++i)
			out << *i << " ";
		out << "Drivers : ";
		for (auto i = Drivers.begin(); i < Drivers.end(); ++i)
			out << *i << " ";
		return out;
	}
	void setter_Packages(vector<Package>Packages){
		this->Packages = Packages;
	}
	vector<Package> getter_Packages()const{
		return Packages;
	}
	void setter_Aphorism(char* Aphorism){
		if (this->Aphorism != nullptr)
			delete[] this->Aphorism;
		try {
			this->Aphorism = new char(strcount(Aphorism));
		}
		catch (const bad_alloc& e) {
			cerr << e.what() << '\n';
		}
		for (int i = 0; i < strcount(Aphorism); ++i)
			this->Aphorism[i] = Aphorism[i];
	}
	char* getter_Aphorism()const{
		return Aphorism;
	}
	private:
		char* Aphorism;
		vector<Package> Packages;
};
unsigned int Read(const string& File, list<Vehicle*> Vehicles){

}


int main(){
	list<Vehicle*> Vehicles;


	return 0;
}
