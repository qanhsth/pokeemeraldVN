Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Mức cược tối thiểu tại bàn này\n"
    .string "là {STR_VAR_1}. Bạn có muốn chơi không?$"

Roulette_Text_NotEnoughCoins::
	.string "Bạn không đủ XU.$"

Roulette_Text_SpecialRateTable::
	.string "Special rate table right now!$"

Roulette_Text_ControlsInstruction::
	.string "Đặt cược bằng nút Tay Cầm,\n"
	.string "rồi nhấn Nút A.$"

Roulette_Text_ItsAHit::
	.string "Trúng!$"

Roulette_Text_Jackpot::
	.string "Độc đắc!$"

Roulette_Text_NothingDoing::
	.string "Hụt!$"

Roulette_Text_YouveWonXCoins::
	.string "Bạn thắng {STR_VAR_1} XU!$"

Roulette_Text_NoCoinsLeft::
	.string "Hết XU…$"

Roulette_Text_KeepPlaying::
	.string "Chơi tiếp?$"

Roulette_Text_BoardWillBeCleared::
	.string "Bàn CÒ QUAY sẽ được dọn lại.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Bạn không có HỘP XU.$"

Roulette_Text_CoinCaseIsFull::
	.string "HỘP XU đầy!\n"
	.string "Xu có thể đổi được quà.$"
