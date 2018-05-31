#ifndef _10_3_H
#define _10_3_H

class cGolf{
private:
	std::string m_name;
	int m_hac;
public:
	//cGolf();
	cGolf(const std::string name="no name",const int hac=0);
	~cGolf();
	void show()const;
	cGolf setGolf(std::string na="no name",const int ha=0);
};
#endif

	
