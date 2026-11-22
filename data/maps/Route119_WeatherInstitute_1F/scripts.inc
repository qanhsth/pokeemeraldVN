Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "ÔNG TRÙM hứng thú với\n"
	.string "nghiên cứu mà họ đang làm ở đây,\l"
	.string "nên ổng cho tụi ta tới đây gác.\p"
	.string "Bớt kiếm chuyện đi!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
    .string "Chết tiệt…\n"
    .string "Bị một đứa nhóc đánh bại…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
    .string "ÔNG TRÙM tụi ta biết hết đó.\p"
    .string "Mà ta chỉ là thằng CULI thôi. Sao\n"
    .string "mà ta biết ổng đang nghĩ gì?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hả?\n"
	.string "Con nít vô đây làm gì?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hả?\n"
	.string "Ta thua rồi?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Rồi luôn…\n"
	.string "Kiểu gì cũng bị rầy tại thua đứa nhóc…\p"
    .string "Thôi lên giường ngủ cho rồi…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Trong lúc tui đang ngủ,\n"
	.string "người ta chạy lên lầu hết trơn!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, bạn mạnh thiệt!\p"
	.string "Ước gì được làm NHL POKéMON\n"
	.string "giống bạn!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
    .string "TIẾN SĨ rất thích mưa.\n"
    .string "Đó là sự thật.\p"
    .string "Mà nếu cứ mưa hoài, thì cũng phiền\n"
    .string "cho người dân. Đó cũng là một sự thật.\p"
    .string "Bởi vậy, TIẾN SĨ đang nghiên cứu coi\n"
    .string "có tận dụng được mưa hay không.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
    .string "Trên tầng 2 của VIỆN,\n"
	.string "tụi tui nghiên cứu các kiểu\l"
    .string "thời tiết ở vùng HOENN.\p"
    .string "Gần đây, tụi tui đã nhận thấy\n"
    .string "có những cơn mưa lớn kéo dài\l"
    .string "hay là hạn hán thất thường…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Xin chào!\n"
	.string "Hành động của bạn đã cứu tụi tui!\p"
	.string "Tui đang không hiểu là tụi AQUA\n"
	.string "đang âm mưu cái gì.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Có giường nè…\n"
	.string "Nằm nghỉ xíu đi.$"

