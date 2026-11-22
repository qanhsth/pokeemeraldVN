VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "QUÝ: Chào! {PLAYER}!\p"
	.string "Chắc bạn cũng ngạc nhiên lắm ha!\p"
	.string "Tui tới được đây, tất cả, là\n"
	.string "nhờ có bạn đó!\p"
	.string "{PLAYER} ơi, lần đó tui thua bạn xong\n"
	.string "làm giờ tui mạnh hơn nhiều!\p"
	.string "Nhưng mà tui sẽ không thua nữa đâu!\p"
	.string "Tui sẽ chiến thắng! Vì con POKéMON,\n"
	.string "đã cho tui dũng khí và sức mạnh!\p"
	.string "Được rồi… Tui tới đây!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Trời ơi!\n"
	.string "{PLAYER}, sau cùng thì, bạn vẫn mạnh!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "QUÝ: Bữa nay tui không thắng được,\n"
	.string "{PLAYER}, nhưng mà ngày kia, tui\l"
	.string "sẽ đuổi kịp bạn mà thôi!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "QUÝ: Chào! {PLAYER}!\p"
	.string "Tui giờ đã mạnh hơn lần trước rồi!\n"
	.string "Tui muốn cho bạn thấy, {PLAYER} ơi!\p"
	.string "Được rồi… Tui tới đây!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Trời ơi!\n"
	.string "{PLAYER}, sau cùng thì, bạn vẫn mạnh!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "QUÝ: Bữa nay tui cũng… không thắng\n"
	.string "được luôn. Nhưng mà sẽ có một ngày,\l"
	.string "tui sẽ thắng được thôi, {PLAYER} ơi…\p"
	.string "Rồi sẽ qua LIÊN ĐOÀN POKéMON đấu luôn!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Tui tới đây nhiều lần rồi, mà\n"
	.string "chặng đường cuối dài quá…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Giấc mơ của tui lại tan biến…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Bạn đã tới được đây rồi. Cứ tiếp tục\n"
	.string "giữ cái đà này và phấn đấu thành NHÀ\l"
	.string "VÔ ĐỊCH! Chỉ có bạn mới làm được thôi!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Tui không có tới tận đây để thua.\n"
	.string "Cái chuyện đó không thể nào xảy ra được!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Không đời nào…\n"
	.string "Tui thua rồi sao?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Tui ở đây…\p"
	.string "Tức là thiếu tư cách để làm\n"
	.string "NHÀ VÔ ĐỊCH rồi sao…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Con đường vô tận và khắc nghiệt này\n"
    .string "rất xứng đáng với cái tên VINH QUANG.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Phong cách chiến đấu quá đẳng cấp…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Có vẻ bạn có tiềm năng trở thành\n"
	.string "NHÀ VÔ ĐỊCH á.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "CON ĐƯỜNG VINH QUANG là gì?\n"
	.string "Thắng đi rồi tui nói cho nghe!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Được rồi!\n"
	.string "Hay rồi!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Ra khỏi đây an toàn--đó là bài kiểm\n"
	.string "tra cuối dành cho NHL hướng tới\l"
	.string "trở thành NHÀ VÔ ĐỊCH POKéMON.\p"
	.string "Bởi vậy nên người ta mới kêu là\n"
	.string "CON ĐƯỜNG VINH QUANG.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Tui không còn gì để nói với\n"
	.string "những người tới được đây. Vô đi!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Đây là một nỗi ô nhục…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Hừ, đi qua đi.\n"
	.string "Tui có nói gì nữa đâu.$"
