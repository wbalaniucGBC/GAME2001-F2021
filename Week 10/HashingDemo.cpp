#include <iostream>
#include "SeparateChaining.h"

using namespace std;

class PlayerInfo
{
public:
	PlayerInfo() : name(""), score(0) { }
	PlayerInfo(string name, int score) : name(name), score(score) { }
	const string& GetHashString()
	{
		return name;
	}
	const string& GetName()
	{
		return name;
	}
	int GetScore()
	{
		return score;
	}
private:
	string name;
	int score;
};

int main()
{
	cout << "Separate Chaining Examples" << endl << endl;

	// Create and fill a hash table
	HashTable<PlayerInfo> hashTable(20);
	PlayerInfo p1("Joe", 11);
	PlayerInfo p2("Pete", 12);
	PlayerInfo p3("Neta", 2);
	PlayerInfo p4("Nate", 30);
	PlayerInfo p5("Jeff", 12);
	PlayerInfo p6("Samantha", 12);

	hashTable.Insert(p1);
	hashTable.Insert(p2);
	hashTable.Insert(p3);
	hashTable.Insert(p4);
	hashTable.Insert(p5);
	hashTable.Insert(p6);

	// hashTable.Delete(p4);

	PlayerInfo p7;

	// Search for the inserted item
	if (hashTable.Find("Neta", &p7))
	{
		cout << "Item: Neta has a score of " << p7.GetScore() << ". " << endl;
	}
	else
	{
		cout << "Item not found";
	}

	return 0;
}