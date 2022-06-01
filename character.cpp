//===================================================
//
//���Ƃ���7[character.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "character.h"
#include "main.h"
#include "warrior.h"
#include "wizard.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{

}// namespace�͂����܂�

//===================================================
//����
//===================================================
CCharacter* CCharacter::Create(JOB job)
{
	CCharacter* pCharacter = nullptr;	//�|�C���^

	switch (job)
	{//�E�Ɩ��̏���
	case JOB::WARRIOR:	/* ��m */

		//�������̓��I�m��
		pCharacter = new CWarrior;
		break;

	case JOB::WIZARD:	/* ���@�g�� */

		//�������̓��I�m��
		pCharacter = new CWizard;
		break;

	case JOB::NONE:	/* �I��͈͊O */
	case JOB::MAX:
	default:
		assert(false);
		break;
	}

	if (pCharacter == nullptr)
	{//NULL�`�F�b�N
		assert(false);
	}

	/* nullptr�ł͂Ȃ� */

	//������
	pCharacter->Init();

	//�o��
	pCharacter->Output();

	return pCharacter;	//���I�m�ۂ������̂�Ԃ�
}

//===================================================
//�R���X�g���N�^
//===================================================
CCharacter::CCharacter()
{
	//�����o�ϐ��̃N���A
	m_nHp = 0;
	m_nAttack = 0;
}

//===================================================
//�f�X�g���N�^
//===================================================
CCharacter::~CCharacter()
{
	/* �������� */
}

//===================================================
//HP�̎擾
//===================================================
int CCharacter::GetHp()
{
	return m_nHp;
}

//===================================================
//�U���͂̎擾
//===================================================
int CCharacter::GetAttack()
{
	return m_nAttack;
}

//===================================================
//HP�̐ݒ�
//===================================================
void CCharacter::SetHp(const int nHp)
{
	m_nHp = nHp;
}

//===================================================
//�U���͂̐ݒ�
//===================================================
void CCharacter::SetAttack(const int nAttack)
{
	m_nAttack = nAttack;
}