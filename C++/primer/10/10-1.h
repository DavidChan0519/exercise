#ifndef _10_1_H
#define _10_1_H

class cBankAccount
{
private:
	static const int Len=40;
	char mName[Len];
	char mAccount[Len];
	double mSave;
public:
	cBankAccount(char *name="no name",char *Account="000000",double Save=0.0);
	~cBankAccount();
	void show()const;
	bool Save(double sa);
	bool Get(double sa);
};
#endif
