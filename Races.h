#ifndef RACES_H_INCLUDED
#define RACES_H_INCLUDED
#include <cmath>
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
        int iSize;
        float fRaceBlood;
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
        int iStr;
        int iDex;
        int iCon;
        int iInt;
        int iCha;
    protected:
        int iBaseStrPoints;
        int iBaseDexPoints;
        int iBaseConPoints;
        int iBaseIntPoints;
        int iBaseChaPoints;
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
        Creature (std::string,cRace*,int,int,int,int,int);
};

Creature::Creature(std::string sGivedName,cRace* pGivedRace,int iGivedStr,int iGivedDex,int iGivedCon, int iGivedInt, int iGivedCha)
{
    sName = sGivedName;
    pRace = pGivedRace;

    vLimbs.resize(pRace->uLimbsNumber[Limbs]);
    vArms.resize(pRace->uLimbsNumber[Arms]);
    vLegs.resize(pRace->uLimbsNumber[Legs]);
    vWings.resize(pRace->uLimbsNumber[Wings]);

    fBaseBlood = pRace->fRaceBlood;

    iBaseStrPoints = iGivedStr;
    iBaseConPoints = iGivedCon;
    iBaseDexPoints = iGivedDex;
    iBaseIntPoints = iGivedInt;
    iBaseChaPoints = iGivedCha;



}


#endif // RACES_H_INCLUDED
