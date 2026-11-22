AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Tới được đây rồi sao?\n"
	.string "Đúng là hơi hạ thấp ngươi rồi!\p"
	.string "Nhưng mà cũng xui cho ngươi!\p"
	.string "Ta là kẻ nổi trội hơn mấy thằng\n"
	.string "LÍNH khác mà ngươi đã gặp.\p"
	.string "Không cần phải câu giờ đâu.\n"
    .string "Ta sẽ nghiền nát ngươi!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "Vậy, ta cũng thua, rồi sao…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "Trong lúc chơi đùa với ngươi,\n"
	.string "ÔNG TRÙM đã chuẩn bị xong hết rồi!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "ÔNG TRÙM có lẽ đang ở mấy cái\n"
	.string "hang sâu dưới biển rồi!\p"
	.string "Nếu tính đuổi theo, ngươi phải\n"
	.string "vùng biển rộng lớn, qua khỏi\l"
	.string "TP.BIỂN mới được.\p"
	.string "Mà liệu ngươi có kiếm được không?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, chờ tới chán rồi!\n"
	.string "Ngươi nợ ta một trận đấu!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Chờ mệt quá…\n"
	.string "Thua xong đuối luôn…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "ÔNG TRÙM…\n"
	.string "Như vậy có đủ chưa?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Cổng dịch chuyển, là\n"
	.string "niềm tự hào của ĐỘI!\p"
	.string "Ngươi còn không biết,\n"
	.string "mình đang ở đâu, phải không?\p"
	.string "Làm cho kẻ thù hoảng loạn và kiệt sức,\n"
    .string "rồi tấn công! Đó là kế hoạch của tụi ta!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Ngươi bị cái gì vậy?\n"
	.string "Ngươi không thấy mệt hả!?$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Làm ta nhớ tới… cái hồi mà ta\n"
	.string "không biết mình để SƯ CẦU ở đâu.\p"
	.string "Nếu mà không giữ được, chắc\n"
	.string "ÔNG TRÙM nhai đầu ta quá…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Lúc mà ta vô ĐỘI AQUA, điều đầu\n"
	.string "tiên mà ta học được là cách mà\l"
	.string "cổng dịch chuyển thông với nhau.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Ta đã quá lo nghĩ về\n"
	.string "mấy cái cổng dịch chuyển…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Ta phải học thêm cách\n"
	.string "chiến đấu cho hiệu quả mới được…$"
