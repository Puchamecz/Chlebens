#ifndef RACES_H_INCLUDED
#define RACES_H_INCLUDED

#include <vector>
enum LIMBS {Limbs,Arms,Legs,Wings};

class cLimb
{
    public:
        int iStrModif;
        int iDexModif;

        int iNatPenetration;
}
};
class cArm : public Limb
{
    public:
        cWeapon* Arms;
};
class cLeg : public Limb
{
    public:
        int iSpeed;
};
class cWing : public Limb
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


};
class Creature
{
    public:
        std::string sName;
        cRace* Race;
//--------------------------
        int iStr;
        int iDex;
        int iInt;
        int iCha;
//--------------------------


        float fBlood;
        float fMaxBlood;
};

#endif // RACES_H_INCLUDED
