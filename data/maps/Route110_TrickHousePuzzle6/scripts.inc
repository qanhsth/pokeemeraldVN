Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} viết mã mật lên\n"
	.string "trên cửa.\p"
	.string "“THẦY ĐÁNH ĐỐ là đời tôi.”\n"
	.string "… … … … … … … …\p"
	.string "Khoá kêu cái ”cạch” rồi mở ra!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Khi mà tui nghe thấy cái gì đó\n"
	.string "lạ lạ, tui phải đi coi thử.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Tui phát hiện ra đối thủ mạnh!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Chắc tui phải nghiên cứu\n"
	.string "kỹ chỗ này mới được.\p"
	.string "Quá khó để kiếm được\n"
	.string "cái gì đó xứng đáng!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Có lẽ tui nên cho POKéMON CHIM\n"
	.string "bay qua tường…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Vụt mất cơ hội rồi!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Thua chắc tại vì\n"
	.string "tui tính ăn gian.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Mấy cái cửa xoay vòng vòng\n"
	.string "làm tui chóng mặt quá…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Mọi thứ cứ quay vòng vòng.\n"
	.string "Tui hết chịu nổi rồi…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Bạn không bị gì hết luôn.\n"
	.string "Hay là bạn chỉ đang giả đò?$"

