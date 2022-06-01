//===================================================
//
//���Ƃ���7[character.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//********************************
//�L�����N�^�[�N���X�̒�`
//********************************
class CCharacter
{/* ��{�N���X */
public: /* �񋓌^�̒�` */
	enum class JOB
	{//�E��
		NONE = 0,
		WARRIOR,	//��m
		WIZARD,		//���@�g��
		MAX
	};

public: /* �萔�̒�` */
	static const int MAX_CHARACTER = 2;	//�ő�l��

public: /* �ÓI�����o�֐� */
	static CCharacter* Create(JOB job);	//����

public: /* �R���X�g���N�^�E�f�X�g���N�^ */
	CCharacter();
	virtual ~CCharacter();

public: /* �������z�֐� */
	virtual void Init() = 0;						//������
	virtual void Output() = 0;						//�o��
	virtual void Uninit() = 0;						//�I��
	virtual void Attack(CCharacter* pTarget) = 0;	//�U������
	virtual void BeAttacked(const int nDamage) = 0;	//�U�����󂯂�

public: /* �����o�֐� */
	int GetHp();					//HP�̎擾
	int GetAttack();				//�U���͂̎擾
	void SetHp(const int nHp);			//HP��ݒ�
	void SetAttack(const int nAttack);	//�U���͂�ݒ�

protected: /* �����o�ϐ� */
	int m_nHp;		//HP
	int m_nAttack;	//�U����
};

#endif