Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} viết mã mật lên\n"
	.string "trên cửa.\p"
	.string "“THẦY ĐÁNH ĐỐ là huyền thoại.”\n"
	.string "… … … … … … … …\p"
	.string "Khoá kêu cái “cạch“ rồi mở ra!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Tui sẽ chém và cắt để giành chiến thắng\n"
    .string "bằng chiêu CẮT mới vừa học!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Sao nghiêm túc vậy?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Tui không bao giờ chán cái chuyện\n"
	.string "cắt và chém này đâu!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Tui vô tình bị lạc vô\n"
	.string "cái nhà quái quỷ này…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Xong cái thua luôn…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Tui bị lạc, thua trận, rồi giờ\n"
	.string "thua thêm trận nữa… Chắc khỏi ra luôn…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "THẦY ĐÁNH ĐỐ là cha nội nào vậy?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Thua trong tưởng tượng lẫn hiện thực!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Bạn mạnh vậy!\n"
	.string "Bạn là ai vậy hả?$"

