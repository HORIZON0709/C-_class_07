//===================================================
//
//授業その7[wizard.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _WIZARD_H_
#define _WIZARD_H_

#include "character.h"

//********************************
//魔法使いクラスの定義
//********************************
class CWizard : public CCharacter
{/* CCharacterの派生クラス */
public: /* コンストラクタ・デストラクタ */
	CWizard();
	~CWizard()override;

public: /* オーバーライド関数 */
	void Init()override;						//初期化
	void Output()override;						//出力
	void Uninit()override;						//終了
	void Attack(CCharacter* pTarget)override;	//攻撃する
	void BeAttacked(const int nDamage)override;	//攻撃を受ける

private: /* メンバ変数 */
	int m_nMp;		//MP
	int m_nAtkHalf;	//攻撃力(半減)
};

#endif