#include "SelfEducation.h"

SelfEducation::SelfEducation(char* s1, char* s2, char* s3, char* s4, int a, int b, int c) :
	Participants(s1, s2, s3, s4, a, b)
{
	experience = c;
}
//-----------------------------------------------------------------------------------------
void SelfEducation::setExperience(const int a)
{
	experience = a;
}
//-----------------------------------------------------------------------------------------
int SelfEducation::getExperience() const
{
	return experience;
}
//-----------------------------------------------------------------------------------------
int SelfEducation::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
SelfEducation SelfEducation::fill(const char* str)
{
	SelfEducation obj;

	int j = obj.p_fill(str), ind;
	char temp[50];

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.experience = atoi(temp);

	return obj;
}
//-----------------------------------------------------------------------------------------
bool SelfEducation::edit()
{
	char choice = Participants::edit();

	yellow
	switch (choice)
	{
	case '5':
	{
		cout << "Enter the new training period: ";
		cin >> experience;
		break;
	}
	case '0': return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------
void SelfEducation::hat()
{
	Participants::hat(id);
	green cout << setw(11) << left << "|Experience" << "|" << endl;

	cout << "|-----------------------------------------------------------------------------|" << endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, SelfEducation& obj)
{
	out << dynamic_cast<Participants&> (obj);

	yellow out << setw(10) << left << obj.experience;
	green out << "|" << endl;

	out << "|-----------------------------------------------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator>>(istream& in, SelfEducation& obj)
{
	in >> dynamic_cast<Participants&> (obj);

	yellow cout << "\nEnter how many years had the participant studied: ";
	in >> obj.experience;

	return in;
}
//-----------------------------------------------------------------------------------------
void SelfEducation::save(SelfEducation& obj, ofstream& file) const
{
	file << obj.getFio() << "/" << obj.getInstrument() << "/" << obj.getCountry() << "/"
		<< obj.getAward() << "/" << obj.experience << endl;
}
//-----------------------------------------------------------------------------------------
SelfEducation& SelfEducation::operator=(SelfEducation& obj)
{
	if (this != &obj)
	{
		setFio(obj.getFio());
		setInstrument(obj.getInstrument());
		setCountry(obj.getCountry());
		setAward(obj.getAward());
		experience = obj.experience;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool SelfEducation::operator==(SelfEducation& obj)
{
	bool compare = Participants::operator==(obj);

	if (compare) return compare;
	else if ((*this).experience == obj.experience) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool SelfEducation::operator>(const SelfEducation& obj)
{	
	bool compare = Participants::operator>(obj);

	if (compare) return compare;
	else if (getSortOpt() == 4 && (*this).experience > obj.experience) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool SelfEducation::search(SelfEducation& obj)
{
	char choice;
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;

		choice = obj.p_search(id);

		yellow
		switch (choice)
		{
		case '5':
		{
			cout << "Enter how many years did the participant studied: ";
			cin >> obj.experience;
			break;
		}
		case '0': return false;
		}
		do
		{
			flag_2 = false;
			
			purple cout << "\nDo you want to add another field for search? (1 - Yes, 2 - No)" << endl;
			cin >> choice;

			if (choice == '1') flag_1 = true;
			else if (choice != '2')
			{
				red cout << "Wrong input! Try again!";
				flag_2 = true;
			}
		} while (flag_2);
	} while (flag_1);

	return true;
}