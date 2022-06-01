//===================================================
//
//���Ƃ���7[warrior.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "warrior.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{

}// namespace�͂����܂�

//===================================================
//�R���X�g���N�^
//===================================================
CWarrior::CWarrior()
{
	//�����o�ϐ����N���A
	m_nWpnDurability = 0;
}

//===================================================
//�f�X�g���N�^
//===================================================
CWarrior::~CWarrior()
{
	/* �������� */
}

//===================================================
//������
//===================================================
void CWarrior::Init()
{
	//����
	srand((unsigned)time(NULL));
	
	//�X�e�[�^�X�̐ݒ�
	SetHp(rand() % 50 + 50);
	SetAttack(rand() % 5 + 5);

	//�����o�ϐ���������
	m_nWpnDurability = rand() % 4 + 1;
}

//===================================================
//�o��
//===================================================
void CWarrior::Output()
{
	printf("\n ��m �c HP : [%d] /",GetHp());
	printf(" �U���� : [%d] /", GetAttack());
	printf(" ����ϋv�� : [%d]", m_nWpnDurability);
}

//===================================================
//�I��
//===================================================
void CWarrior::Uninit()
{
	int nWarrior = 0;	//��m

	if (m_apCharacter[nWarrior] == nullptr)
	{//NULL�`�F�b�N
		return;
	}

	/* nullptr�ł͂Ȃ� */

	//�������̉��
	delete m_apCharacter[nWarrior];
	m_apCharacter[nWarrior] = nullptr;
}

//===================================================
//�U������
//===================================================
void CWarrior::Attack(CCharacter* pTarget)
{
	//���b�Z�[�W
	printf("\n ��m�̍U���I�����[ %d ]�̃_���[�W�I", GetAttack());

	pTarget->BeAttacked(GetAttack());	//����Ƀ_���[�W��^����

	if (m_nWpnDurability > 0)
	{//0�����ɂ͂Ȃ�Ȃ�
		m_nWpnDurability--;	//����ϋv�͂�����
	}

	//���b�Z�[�W
	printf("\n �c��̕���ϋv�� : [ %d ]", m_nWpnDurability);

	if (m_nWpnDurability <= 0)
	{//����ϋv�͂�0�ȉ��ɂȂ����Ƃ�
		int nAtkHalf = (GetAttack() / 2);	//�U���͔���
		SetAttack(nAtkHalf);	//�U���͂̐ݒ�
	}
}

//===================================================
//�U�����󂯂�
//===================================================
void CWarrior::BeAttacked(const int nDamage)
{
	int nHp = GetHp();	//���݂�HP���擾

	nHp -= nDamage;	//�󂯂��_���[�W�����炷

	SetAttack(nHp);	//�c���HP��ݒ肷��

	//�\��
	printf("\n �c��HP : [%d]", GetHp());
}