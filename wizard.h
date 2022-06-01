//===================================================
//
//���Ƃ���7[wizard.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _WIZARD_H_
#define _WIZARD_H_

#include "character.h"

//********************************
//���@�g���N���X�̒�`
//********************************
class CWizard : public CCharacter
{/* CCharacter�̔h���N���X */
public: /* �R���X�g���N�^�E�f�X�g���N�^ */
	CWizard();
	~CWizard()override;

public: /* �I�[�o�[���C�h�֐� */
	void Init()override;						//������
	void Output()override;						//�o��
	void Uninit()override;						//�I��
	void Attack(CCharacter* pTarget)override;	//�U������
	void BeAttacked(const int nDamage)override;	//�U�����󂯂�

private: /* �����o�ϐ� */
	int m_nMp;		//MP
	int m_nAtkHalf;	//�U����(����)
};

#endif