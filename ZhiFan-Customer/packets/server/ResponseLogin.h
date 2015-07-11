#ifndef ResponseLogin_H__
#define ResponseLogin_H__

/*!
 * \file ResponseLogin.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * For����½��Login��ResponseLogin
 */

#include "Packet.h"
/*
identification��bool��1��֤��0δ��֤
IDCardSubstring��string������+��4λ���֤���룬�����
zfb��int����������
userid��int���û�id

*/
PACKET_DEFINITION_BEGIN(ResponseLogin)
Q_OBJECT
PACKET_STRUCTION(ResponseLogin)
//identification��bool��1��֤��0δ��֤
QT_MOC_MINE_DEFINITION(bool, identification, Identification);
//IDCardSubstring��string������+��4λ���֤���룬�����
QT_MOC_MINE_DEFINITION(QString, IDCardSubstring, IDCardSubstring);
//zfb��int����������
QT_MOC_MINE_DEFINITION(int, zfb, Zfb);
//userid��int���û�id
QT_MOC_MINE_DEFINITION(int, userid, Userid);
//userid��QString���û���
QT_MOC_MINE_DEFINITION(QString, username, Username);
PACKET_DEFINITION_END
#endif // ResponseLogin_H__
