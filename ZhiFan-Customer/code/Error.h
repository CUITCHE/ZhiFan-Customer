#ifndef Error_H__
#define Error_H__

/*!
 * \file Error.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �����࣬�����˷���˵����д���
 */
class Error
{
public:
	void operator=(int val);
	void setProtocol(unsigned int p);
	unsigned int getProtocol()const;
	operator int()const;
	Error();
	~Error(){}
private:
	int error;
	unsigned int operatorProtocol;
};
#endif // Error_H__
