Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} viết mã mật lên\n"
	.string "trên cửa.\p"
	.string "“THẦY ĐÁNH ĐỐ tôi yêu”\n"
	.string "… … … … … … … …\p"
	.string "Khoá kêu cái ”cạch” rồi mở ra!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Không phải ai cũng\n"
	.string "tới được đây đâu.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Vậy có nghĩa là bạn rất mạnh…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Bạn đã đánh bại NHÀ VÔ ĐỊCH LIÊN ĐOÀN\n"
	.string "POKéMON? Gì ghê vậy!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Bạn cũng hên lắm mới được\n"
	.string "thách đấu với tui!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Sai quá sai!\n"
	.string "Tui sao mà thua được!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Thắng được tui là kỳ tích đó.\n"
	.string "Bạn có thể tự hào về điều đó.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Bạn cũng đang vật lộn với thử thách\n"
    .string "NHÀ ĐÁNH ĐỐ.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Hiểu rồi…\n"
	.string "Bạn có phong cách thật lạ thường.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Thấy được người như bạn, THẦY\n"
	.string "ĐÁNH ĐỐ sẽ rất hài lòng.$"

