#ifndef NOTHELPER_H_
#define NOTHELPER_H_

template<typename CONDITION>
class NOT__
{
public:
	bool operator()(){
		return not condition();
	}
private:
	CONDITION condition;
};

#endif
