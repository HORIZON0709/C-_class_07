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
}// namespace�͂����܂�

//===================================================
//���C���֐�
//===================================================
void main(void)
{
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

			if (apCharacter[nWarrior] != nullptr)
			{//NULL�`�F�b�N
				//�������̉��
				delete apCharacter[nWarrior];
				apCharacter[nWarrior] = nullptr;
			}

			if (apCharacter[nWizard] != nullptr)
			{//NULL�`�F�b�N
				//�������̉��
				delete apCharacter[nWizard];
				apCharacter[nWizard] = nullptr;
			}

			//����(���̎��ɃX�e�[�^�X�������_���Őݒ�)
			apCharacter[nWarrior] = CCharacter::Create(CCharacter::JOB::WARRIOR);	//��m
			apCharacter[nWizard] = CCharacter::Create(CCharacter::JOB::WIZARD);		//���@�g��
			break;
	
		case PROCESS::BATTLE: /* �퓬 */
			Battle(apCharacter[nWarrior], apCharacter[nWizard]);
			break;
	
		case PROCESS::FINISH: /* �I�� */
			apCharacter[nWarrior]->Uninit();	//��m
			apCharacter[nWizard]->Uninit();		//���@�g��

			//�I���t���O�𗧂Ă�
			bFinish = true;
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
}