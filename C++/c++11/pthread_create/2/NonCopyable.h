#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

class noncopyable
{
public:
	noncopyable() {}
	~noncopyable(){}
private:
	noncopyable(const noncopyable &);
	noncopyable & operator=(const noncopyable &);
};












#endif
