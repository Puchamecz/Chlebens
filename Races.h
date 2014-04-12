#ifndef RACES_H_INCLUDED
#define RACES_H_INCLUDED
class Limb
{
public:
    int StrModif;
    int DexModif;
}
};
class Arm : public Limb
{
    Arms* Weapon;
};
class Race
{
public:
    float Blood;
protected:
    float MaxBlood;
};



#endif // RACES_H_INCLUDED
