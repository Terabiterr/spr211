#include <iostream>
#include <string>
using namespace std;

class Interests
{
public:
    Interests(); //constructor default
    Interests(string thing); // constructor with param
    ~Interests(); // destructor
    string getThing(); // getter
    void setThing(string thing); // setter
private:
    string thing;
};
class User
{
public:
    User() : User{ 0, "" } // Delegate constructors
    {
        //cout << "Constructor default: " << typeid(this).name() << endl;
    }
    User(int id, string name) : _id{ id }, _name{ name }
    {
        _interests = nullptr;
        _size = 0;
        //cout << "Constructor with params: " << typeid(this).name() << endl;
    }
    ~User()
    {
        //cout << "destructor: " << this << endl;
        delete[] _interests;
    }
    void setInterests(Interests interest)
    {
        Interests* tempInterests = new Interests[_size];
        for (size_t i = 0; i < _size; i++)
            tempInterests[i] = _interests[i];
        if(_interests != nullptr)
            delete[] _interests;
        _interests = new Interests[_size + 1];
        for (size_t i = 0; i < _size; i++)
            _interests[i] = tempInterests[i];
        _interests[_size] = interest;
        _size++;
        delete[] tempInterests;
    }
    void print()
    {
        cout << "id: " << _id << endl;
        cout << "name: " << _name << endl;
        for (size_t i = 0; i < _size; i++)
        {
            cout << "Interest: " << _interests[i].getThing() << endl;
        }
    }
private:
    int _id;
    string _name;
    Interests* _interests;
    int _size;
};

int main()
{
    User alex(1, "Alex");
    alex.setInterests(*new Interests("Football"));
    alex.setInterests(*new Interests("XBOX 360"));
    alex.setInterests(*new Interests("Developer C++"));
    alex.print();
    cout << "--------------------------" << endl;
    User bob(2, "Bob");
    bob.setInterests(*new Interests("Cards"));
    bob.setInterests(*new Interests("Tenis"));
    bob.print();
    cout << "--------------------------" << endl;
    User tom(3, "Tom");
    tom.setInterests(*new Interests("Football"));
    tom.setInterests(*new Interests("Sony Playstation 5"));
    tom.setInterests(*new Interests("Developer JS"));
    tom.setInterests(*new Interests("Films"));
    tom.print();
    cout << "--------------------------" << endl;
    return 0;
}

Interests::Interests()
{
    //cout << "constructor default: " << typeid(this).name() << endl;
}

Interests::Interests(string thing)
{
    this->thing = thing;
    //cout << "constructor with param: " << typeid(this).name() << endl;
}

Interests::~Interests()
{
    //cout << "destructor: " << typeid(this).name() << endl;
}

string Interests::getThing()
{
    return this->thing;
}

void Interests::setThing(string thing)
{
    this->thing = thing;
}


