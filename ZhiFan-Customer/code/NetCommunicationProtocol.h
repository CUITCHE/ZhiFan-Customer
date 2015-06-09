#ifndef NetCommunicationProtocol_H__
#define NetCommunicationProtocol_H__

/********************************************************************
	created:	2015/02/21
	created:	21:2:2015   15:29
	file base:	NetCommunicationProtocol
	author:		CHE

	purpose:	����ͨ��Э��
	��Ҫ��pakcet��Э��Ķ���
	*********************************************************************/

namespace net{
	enum NetCommunicationProtocol :unsigned int{
		Empty,
		Test,
		//�ͻ���Э��
		//ע��
		Register,
		//��¼
		Login,
		//ʵ����֤
		Identity,
		//����֪��
		PublishZhiFan,
		//�ش�һ��֪��
		ResponseZhiFan,
		//ƽ·һ���ش�
		CommentResponse,
		//���֪��
		CompleteZhiFan,
		//��ͬ�򷴶�֪����һ���ش�
		ApplaudZhiFan,
		//��ȡ֪���������ݣ���Ҫ��
		GetZhiFanPublishPageOfRange,
		//��ȡһ��֪�����ݵģ���ϸ��
		GetOneZhiFanPublish,
		//����֪��
		SearchZhiFan,
		//��ȡ�û���������
		PullUserCenter,

		//�����Э��

		//����ȷ�Ϸ���
		ServerBack,
		//For����½��Login��ResponseLogin
		ResponseLogin,
		//For��������ȡ�û��������ͣ�PullUserCenter��ResponsePullUserCenter
		ResponsePullUserCenter,
		//For����ȡ֪���������ݣ�GetZhiFanPublishPageOfRange��ResponseGetZhiFanPublishPageOfRange
		ResponseGetZhiFanPublishPageOfRange,
		//For������֪����SearchZhiFan��ResponseSearchZhiFan
		ResponseSearchZhiFan,
		//For����ȡ֪������ϸ���ݣ���ϸ����GetOneZhiFanPublish��ResponseGetOneZhiFanPublish
		ResponseGetOneZhiFanPublish,
		//֪�����ݰ�����Ҫ����ZhiFanPublishBriefOne
		ZhiFanPublishBriefOne,
		//֪�����ݰ�
		ZhiFanPublishOne,

		//max
		MAX = ZhiFanPublishOne

	};
#define Case(V) case V: return #V
	static const char *ProtocolToString(unsigned int val){
		switch (val)
		{
			Case(Empty);
			Case(Test);
			Case(Register);
			Case(Login);
			Case(Identity);
			Case(PublishZhiFan);
			Case(ResponseZhiFan);
			Case(CommentResponse);
			Case(CompleteZhiFan);
			Case(ApplaudZhiFan);
			Case(GetZhiFanPublishPageOfRange);
			Case(GetOneZhiFanPublish);
			Case(SearchZhiFan);
			Case(PullUserCenter);
			Case(ServerBack);
			Case(ResponseLogin);
			Case(ResponsePullUserCenter);
			Case(ResponseGetZhiFanPublishPageOfRange);
			Case(ResponseSearchZhiFan);
			Case(ZhiFanPublishOne);
		default:
			break;
		}
		return "Not exists";
	}
#undef Case

#define Case(V) case V:return V
	static NetCommunicationProtocol protocol_cast(unsigned int val){
		switch (val)
		{
			Case(Empty);
			Case(Test);
			Case(Register);
			Case(Login);
			Case(Identity);
			Case(PublishZhiFan);
			Case(ResponseZhiFan);
			Case(CommentResponse);
			Case(CompleteZhiFan);
			Case(ApplaudZhiFan);
			Case(GetZhiFanPublishPageOfRange);
			Case(GetOneZhiFanPublish);
			Case(SearchZhiFan);
			Case(PullUserCenter);
			Case(ServerBack);
			Case(ResponseLogin);
			Case(ResponsePullUserCenter);
			Case(ResponseGetZhiFanPublishPageOfRange);
			Case(ResponseSearchZhiFan);
			Case(ZhiFanPublishOne);
		default:
			break;
		}
		return Empty;
	}
#undef Case
	const int MAX_PROTOCOL = MAX;
}

#endif // NetCommunicationProtocol_H__
