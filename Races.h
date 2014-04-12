#ifndef RACES_H_INCLUDED
#define RACES_H_INCLUDED
#include "Equipment.h"

enum LIMBS {Limbs,Arms,Legs,Wings};

class cLevel
{


};
class cSkill
{

};

class cLimb
{
    public:
        std::string sNazwa;
        int iEfficiency
        int iStrModif;
        int iDexModif;
        int iNatPenetration;
        int iNatDmg;
};
class cArm : public cLimb
{
    public:
        cWeapon* Arms;
};
class cLeg : public cLimb
{
    public:
        int iSpeed;
};
class cWing : public cLimb
{
    public:
        int iFlySpeed;
};

class cRace
{
    public:
        std::string sRaceName;
        unsigned uLimbsNumber[4];
        int iSize;
//--------------------------
        std::vector <cSkill*> vRaceSkills;


};
class Creature
{
    public:
        std::string sName;
        cRace* Race;
        std::vector <cLevel*> Levels
//--------------------------
        int iStr;
        int iDex;
        int iCon;
        int iInt;
        int iCha;
//--------------------------
        float fBlood;
        float fMaxBlood;
        float fEnergy;
        float fMaxEnergy;
//--------------------------
        std::vector <cLimb> Limbs;
        std::vector <cArm> Arms;
        std::vector <cLeg> Legs;
        std::vector <cWing> Wings;
//---------------------------
        Creature (std::string,cRace*);
        Creature (std::string,cRace*,int,int,int,int);
};

#endif // RACES_H_INCLUDED
