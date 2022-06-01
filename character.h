//===================================================
//
//授業その7[character.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//********************************
//キャラクタークラスの定義
//********************************
class CCharacter
{/* 基本クラス */
public: /* 列挙型の定義 */
	enum class JOB
	{//職業
		NONE = 0,
		WARRIOR,	//戦士
		WIZARD,		//魔法使い
		MAX
	};

public: /* 定数の定義 */
	static const int MAX_CHARACTER = 2;	//最大人数

public: /* 静的メンバ関数 */
	static CCharacter* Create(JOB job);	//生成

public: /* コンストラクタ・デストラクタ */
	CCharacter();
	virtual ~CCharacter();

public: /* 純粋仮想関数 */
	virtual void Init() = 0;						//初期化
	virtual void Output() = 0;						//出力
	virtual void Uninit() = 0;						//終了
	virtual void Attack(CCharacter* pTarget) = 0;	//攻撃する
	virtual void BeAttacked(const int nDamage) = 0;	//攻撃を受ける

public: /* メンバ関数 */
	int GetHp();					//HPの取得
	int GetAttack();				//攻撃力の取得
	void SetHp(const int nHp);			//HPを設定
	void SetAttack(const int nAttack);	//攻撃力を設定

protected: /* メンバ変数 */
	int m_nHp;		//HP
	int m_nAttack;	//攻撃力
};

#endif