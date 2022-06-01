//===================================================
//
//���Ƃ���7[warrior.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "character.h"

//********************************
//��m�N���X�̒�`
//********************************
class CWarrior : public CCharacter
{/* CCharacter�̔h���N���X */
public: /* �R���X�g���N�^�E�f�X�g���N�^ */
	CWarrior();
	~CWarrior()override;

public: /* �I�[�o�[���C�h�֐� */
	void Init()override;						//������
	void Output()override;						//�o��
	void Uninit()override;						//�I��
	void Attack(CCharacter* pTarget)override;	//�U������
	void BeAttacked(const int nDamage)override;	//�U�����󂯂�

private: /* �����o�ϐ� */
	int m_nWpnDurability;	//����ϋv��
};

#endif