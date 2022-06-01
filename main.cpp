//===================================================
//
//授業その7[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "main.h"
#include "character.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//列挙型の定義
//********************************
namespace
{
enum class PROCESS
{/* 処理の種類 */
	NONE = 0,
	CREATE,		//生成
	BATTLE,		//戦闘
	FINISH,		//終了
	MAX
};
}// namespaceはここまで

//********************************
//プロトタイプ宣言
//********************************
namespace
{
void Process();
PROCESS SelectProcess();
void Battle(CCharacter* pWarrior,CCharacter* pWizard);
void Release(CCharacter* pWarrior, CCharacter* pWizard);
}// namespaceはここまで

//===================================================
//メイン関数
//===================================================
void main(void)
{
	//乱数
	srand((unsigned)time(NULL));

	//処理を実行する
	Process();

	//終了メッセージ & Enter入力待ち
	printf("\n\n プログラムを終了します。お疲れ様でした。");
	PressEnter();
}

//===================================================
//Enter入力待ち
//===================================================
void PressEnter()
{
	//Enter入力待ち
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//処理を実行する
//---------------------------------------------------
void Process()
{
	bool bFinish = false;	//終了フラグ
	int nWarrior = 0;		//戦士
	int nWizard = 1;		//魔法使い
	CCharacter* apCharacter[CCharacter::MAX_CHARACTER] = {};	//ポインタ

	while (!bFinish)
	{
		//実行する処理を選択
		PROCESS process = SelectProcess();
	
		switch (process)
		{
		case PROCESS::CREATE: /* 生成 */
			apCharacter[nWarrior] = CCharacter::Create(CCharacter::JOB::WARRIOR);	//戦士
			apCharacter[nWizard] = CCharacter::Create(CCharacter::JOB::WIZARD);		//魔法使い
			break;
	
		case PROCESS::BATTLE: /* 戦闘 */
			if ((apCharacter[nWarrior] == nullptr) || ((apCharacter[nWizard] == nullptr)))
			{//NULLチェック
				printf("\n ***** [Error] nullptrです。 *****");
				break;
			}

			/* nullptrではない場合 */

			Battle(apCharacter[nWarrior], apCharacter[nWizard]);	//戦闘
			Release(apCharacter[nWarrior], apCharacter[nWizard]);	//解放
			break;
	
		case PROCESS::FINISH: /* 終了 */
			bFinish = true;	//終了フラグを立てる
			break;
	
		case PROCESS::NONE: /* その他 */
		case PROCESS::MAX:
		default:
			assert(false);
			break;
		}
	
		if (bFinish)
		{//終了時
			break;
		}

		/* 終了しない場合 */

		//Enter入力待ち
		PressEnter();

		//画面をクリア
		system("cls");
	}
}

//---------------------------------------------------
//実行する処理を選択
//---------------------------------------------------
PROCESS SelectProcess()
{
	PROCESS process = PROCESS::NONE;	//処理選択用

	while (1)
	{
		//メッセージ
		printf("\n 《 行動を選択 》");
		printf("\n [%d] キャラクター生成", PROCESS::CREATE);
		printf("\n [%d] 戦闘開始", PROCESS::BATTLE);
		printf("\n [%d] 終了", PROCESS::FINISH);
		printf("\n 番号を入力 > ");
		scanf("%d", &process);

		if ((process > PROCESS::NONE) && (process < PROCESS::MAX))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	//画面をクリア
	system("cls");

	return process;	//選択した処理を返す
}

//---------------------------------------------------
//戦闘
//---------------------------------------------------
void Battle(CCharacter* pWarrior, CCharacter* pWizard)
{
	while (1)
	{
		if (pWarrior->GetHp() <= 0)
		{//戦士のHPが0になったとき
			printf("\n Win! [ 魔法使い ]");
			break;	//戦闘終了
		}

		/* HPがまだある場合 */

		pWarrior->Attack(pWizard);	//戦士の攻撃

		//Enter入力待ち
		PressEnter();

		//画面をクリア
		system("cls");

		if (pWizard->GetHp() <= 0)
		{//魔法使いのHPが0になったとき
			printf("\n Win! [ 戦士 ]");
			break;	//戦闘終了
		}

		/* HPがまだある場合 */

		pWizard->Attack(pWarrior);	//魔法使いの攻撃

		//Enter入力待ち
		PressEnter();

		//画面をクリア
		system("cls");
	}
}

//---------------------------------------------------
//解放
//---------------------------------------------------
void Release(CCharacter* pWarrior, CCharacter* pWizard)
{
	pWarrior->Uninit();	//戦士
	pWizard->Uninit();	//魔法使い

	if (pWarrior != nullptr)
	{//NULLチェック
		//メモリの解放
		delete pWarrior;
		pWarrior = nullptr;
	}

	if (pWizard != nullptr)
	{//NULLチェック
		//メモリの解放
		delete pWizard;
		pWizard = nullptr;
	}
}
}