//===================================================
//
//授業その7[warrior.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "character.h"

//********************************
//戦士クラスの定義
//********************************
class CWarrior : public CCharacter
{/* CCharacterの派生クラス */
public: /* コンストラクタ・デストラクタ */
	CWarrior();
	~CWarrior()override;

public: /* オーバーライド関数 */
	void Init()override;						//初期化
	void Output()override;						//出力
	void Uninit()override;						//終了
	void Attack(CCharacter* pTarget)override;	//攻撃する
	void BeAttacked(const int nDamage)override;	//攻撃を受ける

private: /* メンバ変数 */
	int m_nWpnDurability;	//武器耐久力
};

#endif