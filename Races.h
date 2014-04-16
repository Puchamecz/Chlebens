#ifndef RACES_H_INCLUDED
#define RACES_H_INCLUDED
#include <cmath>
#include "Equipment.h"

enum LIMBS {Limbs,Arms,Legs,Wings};
enum SIZE {Small=1,Medium=2,Big=3};

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
        int iEfficiency;
        int iStrModif;
        int iDexModif;
        int iNatPenetration;
        int iNatDmg;
};
class cArm : public cLimb
{
    public:
        cWeapon* pArms;
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
        SIZE sSize;
        float fRaceBlood;

        unsigned uStrModif;
        unsigned uDexModif;
        unsigned uConModif;
        unsigned uIntModif;
        unsigned uChaModif;
//--------------------------
        std::vector <cSkill*> vRaceSkills;


};
class Creature
{
    public:
        std::string sName;
        cRace* pRace;
        std::vector <cLevel*> Levels;
//--------------------------
        unsigned uStr;
        unsigned uDex;
        unsigned uCon;
        unsigned uInt;
        unsigned uCha;
    protected:
        unsigned uBaseStrPoints;
        unsigned uBaseDexPoints;
        unsigned uBaseConPoints;
        unsigned uBaseIntPoints;
        unsigned uBaseChaPoints;
//--------------------------
    public:
        float fBlood;
        float fMaxBlood;
        float fEnergy;
        float fMaxEnergy;
    protected:
        float fBaseBlood;
        float fBaseEnergy;
//--------------------------
    public:
        std::vector <cLimb> vLimbs;
        std::vector <cArm> vArms;
        std::vector <cLeg> vLegs;
        std::vector <cWing> vWings;
//---------------------------
        Creature (std::string,cRace*,unsigned,unsigned,unsigned,unsigned,unsigned);
};

Creature::Creature(std::string sGivedName,cRace* pGivedRace,unsigned uGivedStr,unsigned uGivedDex,unsigned uGivedCon, unsigned uGivedInt, unsigned uGivedCha)
{
    sName = sGivedName;
    pRace = pGivedRace;

    vLimbs.resize(pRace->uLimbsNumber[Limbs]);
    vArms.resize(pRace->uLimbsNumber[Arms]);
    vLegs.resize(pRace->uLimbsNumber[Legs]);
    vWings.resize(pRace->uLimbsNumber[Wings]);

    fBaseBlood = pRace->fRaceBlood;

    uBaseStrPoints = uGivedStr;
    uBaseConPoints = uGivedCon;
    uBaseDexPoints = uGivedDex;
    uBaseIntPoints = uGivedInt;
    uBaseChaPoints = uGivedCha;

    uStr = uBaseStrPoints * pRace->uStrModif;
    uDex = uBaseDexPoints * pRace->uDexModif;
    uCon = uBaseConPoints * pRace->uConModif;
    uInt = uBaseIntPoints * pRace->uIntModif;
    uCha = uBaseChaPoints * pRace->uChaModif;
}


#endif // RACES_H_INCLUDED
