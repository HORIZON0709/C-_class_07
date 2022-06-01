//===================================================
//
//���Ƃ���7[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "main.h"
#include "character.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�񋓌^�̒�`
//********************************
namespace
{
enum class PROCESS
{/* �����̎�� */
	NONE = 0,
	CREATE,		//����
	BATTLE,		//�퓬
	FINISH,		//�I��
	MAX
};
}// namespace�͂����܂�

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{
void Process();
PROCESS SelectProcess();
void Battle(CCharacter* pWarrior,CCharacter* pWizard);
void Release(CCharacter* pWarrior, CCharacter* pWizard);
}// namespace�͂����܂�

//===================================================
//���C���֐�
//===================================================
void main(void)
{
	//����
	srand((unsigned)time(NULL));

	//���������s����
	Process();

	//�I�����b�Z�[�W & Enter���͑҂�
	printf("\n\n �v���O�������I�����܂��B�����l�ł����B");
	PressEnter();
}

//===================================================
//Enter���͑҂�
//===================================================
void PressEnter()
{
	//Enter���͑҂�
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//���������s����
//---------------------------------------------------
void Process()
{
	bool bFinish = false;	//�I���t���O
	int nWarrior = 0;		//��m
	int nWizard = 1;		//���@�g��
	CCharacter* apCharacter[CCharacter::MAX_CHARACTER] = {};	//�|�C���^

	while (!bFinish)
	{
		//���s���鏈����I��
		PROCESS process = SelectProcess();
	
		switch (process)
		{
		case PROCESS::CREATE: /* ���� */
			apCharacter[nWarrior] = CCharacter::Create(CCharacter::JOB::WARRIOR);	//��m
			apCharacter[nWizard] = CCharacter::Create(CCharacter::JOB::WIZARD);		//���@�g��
			break;
	
		case PROCESS::BATTLE: /* �퓬 */
			if ((apCharacter[nWarrior] == nullptr) || ((apCharacter[nWizard] == nullptr)))
			{//NULL�`�F�b�N
				printf("\n ***** [Error] nullptr�ł��B *****");
				break;
			}

			/* nullptr�ł͂Ȃ��ꍇ */

			Battle(apCharacter[nWarrior], apCharacter[nWizard]);	//�퓬
			Release(apCharacter[nWarrior], apCharacter[nWizard]);	//���
			break;
	
		case PROCESS::FINISH: /* �I�� */
			bFinish = true;	//�I���t���O�𗧂Ă�
			break;
	
		case PROCESS::NONE: /* ���̑� */
		case PROCESS::MAX:
		default:
			assert(false);
			break;
		}
	
		if (bFinish)
		{//�I����
			break;
		}

		/* �I�����Ȃ��ꍇ */

		//Enter���͑҂�
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}
}

//---------------------------------------------------
//���s���鏈����I��
//---------------------------------------------------
PROCESS SelectProcess()
{
	PROCESS process = PROCESS::NONE;	//�����I��p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �s �s����I�� �t");
		printf("\n [%d] �L�����N�^�[����", PROCESS::CREATE);
		printf("\n [%d] �퓬�J�n", PROCESS::BATTLE);
		printf("\n [%d] �I��", PROCESS::FINISH);
		printf("\n �ԍ������ > ");
		scanf("%d", &process);

		if ((process > PROCESS::NONE) && (process < PROCESS::MAX))
		{//�͈͓�
			break;
		}

		/* �͈͊O */

		//���b�Z�[�W & Enter���͑҂�
		printf("\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	//��ʂ��N���A
	system("cls");

	return process;	//�I������������Ԃ�
}

//---------------------------------------------------
//�퓬
//---------------------------------------------------
void Battle(CCharacter* pWarrior, CCharacter* pWizard)
{
	while (1)
	{
		if (pWarrior->GetHp() <= 0)
		{//��m��HP��0�ɂȂ����Ƃ�
			printf("\n Win! [ ���@�g�� ]");
			break;	//�퓬�I��
		}

		/* HP���܂�����ꍇ */

		pWarrior->Attack(pWizard);	//��m�̍U��

		//Enter���͑҂�
		PressEnter();

		//��ʂ��N���A
		system("cls");

		if (pWizard->GetHp() <= 0)
		{//���@�g����HP��0�ɂȂ����Ƃ�
			printf("\n Win! [ ��m ]");
			break;	//�퓬�I��
		}

		/* HP���܂�����ꍇ */

		pWizard->Attack(pWarrior);	//���@�g���̍U��

		//Enter���͑҂�
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}
}

//---------------------------------------------------
//���
//---------------------------------------------------
void Release(CCharacter* pWarrior, CCharacter* pWizard)
{
	pWarrior->Uninit();	//��m
	pWizard->Uninit();	//���@�g��

	if (pWarrior != nullptr)
	{//NULL�`�F�b�N
		//�������̉��
		delete pWarrior;
		pWarrior = nullptr;
	}

	if (pWizard != nullptr)
	{//NULL�`�F�b�N
		//�������̉��
		delete pWizard;
		pWizard = nullptr;
	}
}
}