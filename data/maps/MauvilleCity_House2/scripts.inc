MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Nếu mà tui có XE ĐẠP, tui sẽ\n"
	.string "ghé TP.CẢNG mua sắm nhiều hơn.\p"
	.string "Tui sẽ có thể mua HARBOR MAIL\n"
	.string "tại SIÊU THỊ ở TP.CẢNG…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Ủa! Bạn có HARBOR MAIL hả?\n"
	.string "Bạn có muốn đổi lấy HỘP XU không?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Trời ơi, mừng quá!\n"
	.string "Rồi, tui sẽ đưa HỘP XU cho bạn!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "HỘP XU đó có thể xài\n"
	.string "ở HỘI GAME á.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Trời, buồn ghê.\p"
	.string "HỘP XU là bắt buộc phải có\n"
	.string "ở HỘI GAME á trời.$"

