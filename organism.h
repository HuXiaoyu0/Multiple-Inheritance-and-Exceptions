#include<iostream>

//Test functions
//To see whether series of facts fit one kind of animal
bool IsOrganism(const std::map<std::string,std::vector<std::string> > &facts);
bool IsAnimal(const std::map<std::string,std::vector<std::string> > &facts);
bool IsPlant(const std::map<std::string,std::vector<std::string> > &facts);
bool IsEndothermic(const std::map<std::string,std::vector<std::string> > &facts);
bool IsLaysEggs(const std::map<std::string,std::vector<std::string> > &facts);
bool IsEctothermic(const std::map<std::string,std::vector<std::string> > &facts);
bool IsMammal(const std::map<std::string,std::vector<std::string> > &facts);
bool IsBird(const std::map<std::string,std::vector<std::string> > &facts);
bool IsFish(const std::map<std::string,std::vector<std::string> > &facts);
bool IsReptile(const std::map<std::string,std::vector<std::string> > &facts);
bool IsRhinoceros(const std::map<std::string,std::vector<std::string> > &facts);
bool IsTiger(const std::map<std::string,std::vector<std::string> > &facts);
bool IsBat(const std::map<std::string,std::vector<std::string> > &facts);
bool IsBear(const std::map<std::string,std::vector<std::string> > &facts);
bool IsPlatypus(const std::map<std::string,std::vector<std::string> > &facts);
bool IsPenguin(const std::map<std::string,std::vector<std::string> > &facts);
bool IsCardinal(const std::map<std::string,std::vector<std::string> > &facts);
bool IsTrout(const std::map<std::string,std::vector<std::string> > &facts);
bool IsTortoise(const std::map<std::string,std::vector<std::string> > &facts);
bool IsRedwood(const std::map<std::string,std::vector<std::string> > &facts);
bool IsVenusFlyTrap(const std::map<std::string,std::vector<std::string> > &facts);



class Organism{
public:
	Organism(const std::map<std::string,std::vector<std::string> > &facts) throw (int){
	if (!IsOrganism(facts)) throw 1;
	facts_ = facts;
	}
	
	virtual ~Organism() {}

	virtual bool isCarnivore();
	virtual bool isHerbivore();
	virtual bool isOmnivore();
	virtual bool livesInAir();
	virtual bool livesOnLand();
	virtual bool livesInWater();
	
	//call this function to get the name of the organism
	std::string getName();
	
protected:
	std::map<std::string,std::vector<std::string> > facts_;
};

class Animal: public Organism{
public:
	Animal(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Organism(facts){
	if (!IsAnimal(facts)) throw 1;
	}
};

class Plant: public Organism{
public:
	Plant(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Organism(facts){
	if (!IsPlant(facts)) throw 1;
	}
};

class Endothermic: virtual public Animal{
public:
	Endothermic(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts){
	if (!IsEndothermic(facts)) throw 1;
	}
};

class LaysEggs: virtual public Animal{
public:
	LaysEggs(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts){
	if (!IsLaysEggs(facts)) throw 1;
	}
};

class Ectothermic: virtual public Animal{
public:
	Ectothermic(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts){
	if (!IsEctothermic(facts)) throw 1;
	}
};

class Mammal: public Endothermic{
public:
	Mammal(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Endothermic(facts){
	if (!IsMammal(facts)) throw 1;
	}
};

class Bird: public Endothermic, public LaysEggs{
public:
	Bird(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), LaysEggs(facts), Endothermic(facts){
	if (!IsBird(facts)) throw 1;
	}
};

class Fish: public LaysEggs, public Ectothermic{
public:
	Fish(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), LaysEggs(facts), Ectothermic(facts) {
	if (!IsFish(facts)) throw 1;
	}
	bool livesInWater(){return true;}
};

class Reptile: public LaysEggs, public Ectothermic{
public: Reptile(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal (facts), LaysEggs(facts), Ectothermic(facts){
		if (!IsReptile(facts)) throw 1;
		}
};

class Rhinoceros: public Mammal{
public:
	Rhinoceros(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Mammal(facts){
	if (!IsRhinoceros(facts)) throw 1;
	}
	bool isHerbivore(){return true;}
	bool livesOnLand(){return true;}

};

class Tiger: public Mammal{
public:
	Tiger(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Mammal(facts){
	if (!IsTiger(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesOnLand(){return true;}
};

class Bat: public Mammal{
public:
	Bat(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Mammal(facts){
	if (!IsBat(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesInAir(){return true;}
	bool livesOnLand(){return true;}
};

class Bear: public Mammal{
	public:
Bear(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Mammal(facts){
	if (!IsBear(facts)) throw 1;
	}
	bool isOmnivore(){return true;}
	bool livesOnLand(){return true;}
};

class Platypus: public LaysEggs, public Mammal{
public:
	Platypus(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), LaysEggs(facts), Mammal(facts){
	if (!IsPlatypus(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesOnLand(){return true;}
	bool livesInWater(){return true;}
};

class Penguin: public Bird{
public:
	Penguin(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Bird(facts){
	if (!IsPenguin(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesOnLand(){return true;}
	bool livesInWater(){return true;}
};

class Cardinal: public Bird{
public:
	Cardinal(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Bird(facts){
	if (!IsCardinal(facts)) throw 1;
	}
	bool isHerbivore(){return true;}
	bool livesInAir(){return true;}
};

class Trout: public Fish{
public:
	Trout(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Fish(facts){
	if (!IsTrout(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesInWater(){return true;}
};

class Tortoise: public Reptile{
public:
	Tortoise(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Animal(facts), Reptile(facts){
	if (!IsTortoise(facts)) throw 1;
	}
	bool isHerbivore(){return true;}
	bool livesOnLand(){return true;}
};

class Redwood: public Plant{
public:
	Redwood(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Plant(facts){
	if (!IsRedwood(facts)) throw 1;
	}
	bool livesOnLand(){return true;}
};

class VenusFlyTrap: public Plant{
public:
	VenusFlyTrap(const std::map<std::string,std::vector<std::string> > &facts) throw (int): Plant(facts){
	if (!IsVenusFlyTrap(facts)) throw 1;
	}
	bool isCarnivore(){return true;}
	bool livesOnLand(){return true;}
};

//in order to sort by name
bool organism_sorter(Organism* ptr1, Organism* ptr2); 
