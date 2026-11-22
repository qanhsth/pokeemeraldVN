FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Con người… POKéMON…\p"
	.string "Sức mạnh tiềm ẩn được khơi dậy nhờ\n"
    .string "sống trong môi trường tự nhiên…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Để bà lão này coi sức mạnh\n"
	.string "tiềm ẩn của con đã thức tỉnh chưa…\p"
	.string "Ta có đồng xu trong tay.\p"
	.string "Giờ, hãy nói cho ta biết, đồng xu\n"
	.string "ở bên tay phải? Hay bên tay trái?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Trời! Đúng rồi đó!\p"
	.string "Thử một lần nữa nha.\p"
	.string "Tay nào có xu?\n"
	.string "Phải hay trái?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Trời! Đúng rồi đó!\p"
	.string "Thử thêm một lần nữa nha.\p"
	.string "Tay nào có xu?\n"
	.string "Phải hay trái?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Trời đất! Quá hay!\n"
	.string "Sức mạnh tiềm ẩn của con đã thức tỉnh!\p"
	.string "Đây, cầm lấy rồi thức tỉnh\n"
	.string "sức mạnh của POKéMON đi.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "THỨC TỈNH là chiêu thức\n"
	.string "thay đổi tuỳ POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Dở quá con ơi.\n"
	.string "Sai nữa rồi.$"

