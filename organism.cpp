#include <iostream>
#include <vector>
#include <map>
#include "organism.h"
#include <cassert>
#include <string>

std::string Organism::getName(){
		std::map<std::string,std::vector<std::string> >::iterator ite = facts_.find("name:");
		if (ite != facts_.end()){
			assert(ite->second.size() == 1);
			return ite->second[0];
}
}

bool organism_sorter(Organism* ptr1, Organism* ptr2){
	return (ptr1->getName() < ptr2->getName());
}

bool Organism::isCarnivore(){return false;}
bool Organism::isHerbivore(){return false;}
bool Organism::isOmnivore(){return false;}
bool Organism::livesInAir(){return false;}
bool Organism::livesOnLand(){return false;}
bool Organism::livesInWater(){return false;}

bool IsOrganism(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}

//even for fewer facts, "has" is a good feather to find animal
bool IsAnimal(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("has:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "fur" || ite->second[i] == "feathers" 
			|| ite->second[i] == "scales"|| ite->second[i] == "teeth"
			|| ite->second[i] == "wings" || ite->second[i] == "bill" ||
			ite->second[i] == "bill")
			return true;
	}
	return false;
}
//plant must have root or leave
bool IsPlant(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("has:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "leaves" || ite->second[i] == "roots")
			return true;}
	return false;
}
//is Endothermic when is warm blooded or has feather or fur to keep warm
bool IsEndothermic(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("warm_blooded:");
	if (ite != facts.end()){	
	if (ite->second[0] == "true")
		return true;}
	std::map<std::string,std::vector<std::string> >::const_iterator itr = facts.find("has:");
	for (int i = 0; i < itr->second.size(); i++){
		if (itr->second[i] == "wings" || itr->second[i] == "feathers" || itr->second[i] == "fur")
			return true;}
	return false;
}
//bird fish lay eggs if not labled " lays egg "
bool IsLaysEggs(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("lays_eggs:");
		if(ite != facts.end()){
		if (ite->second[0] == "true")
			return true;}
	std::map<std::string,std::vector<std::string> >::const_iterator itr = facts.find("has:");
		for (int i = 0; i < itr->second.size(); i++){
		if (itr->second[i] == "wings" || itr->second[i] == "feathers")
			return true;}
		return false;
}
//labeld false for warm blooded or is fish
bool IsEctothermic(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("warm_blooded:");
		if (ite != facts.end()){
		if (ite->second[0] == "false")
			return true;}
	std::map<std::string,std::vector<std::string> >::const_iterator itr = facts.find("lives_in:");
	for (int i = 0; i < itr->second.size(); i++){
		if (itr->second.size() == 1 && itr->second[i] == "water")
			return true;}
	return false;
}
//do not lay eggs and is out of endothermic
bool IsMammal(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("lays_eggs:");
		if (ite != facts.end()){
		if (ite->second[0] == "false")
			return true;}
	std::map<std::string,std::vector<std::string> >::const_iterator itr = facts.find("has:");
		for (int i = 0; i < itr->second.size(); i++){	
		if (itr->second[i] == "fur")
			return true;}
		return false;
}
//has wings and is out of endorthermic
bool IsBird(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("has:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "wings" || ite->second[i] == "feathers")
			return true;}
	/*
	std::map<std::string,std::vector<std::string> >::const_iterator itr = facts.find("lives_in:");
	if (itr != facts.end()){
	for (int j = 0; j < itr->second.size(); j++){
	if (itr->second[j] == "air")
		return true;
	}
	}*/
	return false;
}
//only live in water
bool IsFish(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("lives_in:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second.size() == 1 && ite->second[i] == "water")
			return true;}

	return false;
}
//if is ecthermic and not others, must be reptile
bool IsReptile(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//rhinoceros--only mammal which eat grass
bool IsRhinoceros(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("eats:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second.size() == 1 && ite->second[i] == "grass")
			return true;}
	return false;
}
//not other mammal, must be tiger
bool IsTiger(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//has wings and out of mammal
bool IsBat(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("has:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "wings")
			return true;}
	return false;
}
//only mammal which eat fish
bool IsBear(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("eats:");
	if (ite == facts.end())
		return false;
	for (int i = 0; i < ite->second.size(); i++){
	if (ite->second[i] == "fish")
		return true;
	}
	return false;
}

//mamaal and cold blooded, must be platypus
bool IsPlatypus(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//bird but not catherine, must be penguin
bool IsPenguin(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//lives in air
bool IsCardinal(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("lives_in:");
	if (ite == facts.end())
		return false;
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "air")
			return true;}
	return false;
}
//only fish
bool IsTrout(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//only reptile
bool IsTortoise(const std::map<std::string,std::vector<std::string> > &facts){
	return true;
}
//plant which has branched
bool IsRedwood(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("has:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "branches")
			return true;}
	return false;
}
//plant which eats bugs
bool IsVenusFlyTrap(const std::map<std::string,std::vector<std::string> > &facts){
	std::map<std::string,std::vector<std::string> >::const_iterator ite = facts.find("eats:");
	for (int i = 0; i < ite->second.size(); i++){
		if (ite->second[i] == "bugs")
			return true;}
	return false;
}
