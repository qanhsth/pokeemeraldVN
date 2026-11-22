Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} viết mã mật lên\n"
	.string "trên cửa.\p"
	.string "“THẦY ĐÁNH ĐỐ ngầu lòi.”\n"
	.string "… … … … … … … …\p"
	.string "Khoá kêu cái “cạch“ rồi mở ra!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Nghĩ hoài không ra.\n"
	.string "Tui chỉ muốn thách đấu thôi!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Mặc dầu thua, tui vẫn\n"
	.string "thích thách đấu nhất!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Bạn có nghĩ là đi đâu cũng được\n"
	.string "nếu chỗ đó có NHL không?.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Đá cỡ này, tui chỉ cần xài\n"
	.string "1 ngón là dời qua chỗ khác được!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Tui có thể đẩy được tảng đá,\n"
	.string "mà bí ẩn thì bó tay…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Chỉ có cơ bắp thôi thì chưa đủ…\n"
    .string "Bạn phải biết dùng đầu óc. Khôn lên!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "NHÀ ĐÁNH ĐỐ càng ngày càng đánh đố hơn,\n"
	.string "thì phải?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Ặcccc!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Có ai giải mã được chưa?$"

