#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Character
{
    string name;
    public:

    string getName()
    {
        return name;
    }

    Character(string name)
    {
        this->name=name;
    }

    virtual ~Character()=0;
    virtual void attack(){};
    virtual int getAbility(){};
};

Character::~Character()
{

}

class Warrior: public Character
{
    int strength;
    public:

    Warrior(string name, int strength):Character(name)
    {
        this->strength=strength;
    }

    int getAbility()
    {
        return strength;
    }

    void attack()
    {
        cout<<"attacks with strength ";
    }
};

class Mage: public Character
{
    int intelligence;
    
    public:

    Mage(string name, int intelligence):Character(name)
    {
        this->intelligence=intelligence;
    }

    int getAbility()
    {
        return intelligence;
    }

    void attack()
    {
        cout<<"attacks with fireballs";
    }
};

class Thief: public Character
{
    int agility;
    public:

    Thief(string name, int agility):Character(name)
    {
        this->agility=agility;
    }
    int getAbility()
    {
        return agility;
    }
    void attack()
    {
        cout<<"attacks with daggers";
    }
};

void polymorphism(Character *main[3]);

int main()
{
    Character *main[3];
    string     name;
    int        power;

    cout<<"Enter the Warrior Name: ";
    getline(cin,name);
    cout<<"Enter the Warrior strength: ";
    cin>>power;
    main[0]=new Warrior(name,power);
    
    cin.ignore(1,'\n');
    cout<<"\n\nEnter the Mage Name: ";
    getline(cin,name);
    cout<<"Enter the Mage intelligence: ";
    cin>>power;
    main[1]=new Mage(name,power);

    cin.ignore(1,'\n');
    cout<<"\n\nEnter the Thief Name: ";
    getline(cin,name);
    cout<<"Enter the theif agility: ";
    cin>>power;
    main[2]=new Thief(name,power);
    
    polymorphism(main);

    for (int i = 0; i < 3; i++)
    {
        delete main[i];
        main[i]=0;
    }
    
    return 0;
}

void polymorphism(Character *main[3])
{
    cout<<"\n\n";
    for (int i = 0; i < 3; i++)
    {
        if (i==0)
        {
            cout<< main[i]->getName()<<" ";
            main[i]->attack();
            cout<<" "<<main[i]->getAbility()<<endl;
        }
        else if (i==1)
        {
            cout<< main[i]->getName()<<" ";
            main[i]->attack();
            cout<<" using intelligence "<<main[i]->getAbility()<<endl;
        }
        else 
        {
            cout<< main[i]->getName()<<" ";
            main[i]->attack();
            cout<<" using agility "<<main[i]->getAbility()<<endl;
        }
        
        
    }
    cout<<"\n\n------------------------------------------------------";
}