MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Sức mạnh ở trong ĐÁ TRỜI…\p"
	.string "Bằng cách khuếch đại sức mạnh của nó\n"
    .string "bằng cỗ máy này, hoạt động phun trào\l"
    .string "của NÚI LỬA sẽ ngay lập tức gia tăng…\p"
    .string "Năng lượng của nó sẽ dâng trào sâu\n"
    .string "bên trong miệng núi lửa và…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MÃ: Hm?\n"
	.string "Ngươi là ai?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ta nghe MUỘI than phiền về một\n"
    .string "đứa con nít can thiệp vô chuyện của\l"
    .string "ĐỘI AQUA.\p"
    .string "Chắc là hắn đang nói về ngươi.\p"
    .string "Hừ! Vậy là ngươi đang nghĩ tới chuyện\n"
	.string "can thiệp tụi ta, ĐỘI MAGMA sao?\p"
    .string "Giờ thì nghe đây.\n"
    .string "Từ lâu lắm rồi, các sinh vật đã sử dụng\l"
    .string "đất để sinh sống và phát triển.\p"
    .string "Bởi vậy nên đất liền rất quan trọng!\n"
    .string "Đó là cái nôi của vạn vật!\p"
	.string "Đó là lý do tại sao ĐỘI MAGMA cống hiến\n"
    .string "cho chuyện mở rộng diện tích đất liền.\p"
    .string "Đó là để thúc đẩy sự tiến hoá của\n"
    .string "loài người và POKéMON!\p"
    .string "Và bởi lẽ đó, tụi ta cần sức mạnh của\n"
	.string "thứ đang ngủ sâu bên trong ngọn núi này…\p"
    .string "Ụa! Biết nhiều cũng để\n"
    .string "làm chi đâu.\p"
    .string "Nhưng mà thôi kệ đi!\n"
    .string "Ta sẽ cho ngươi biết hậu quả của chuyện\l"
    .string "can thiệp vô kế hoạch vĩ đại của tụi ta!$"

MtChimney_Text_MaxieDefeat:
	.string "Hả?!\p"
	.string "Một kẻ như ta lại bị bắt bài?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MÃ: Thôi đủ rồi.\n"
	.string "Lần này ta sẽ lui lại.\p"
	.string "Nhưng đừng có nghĩ đây là lần cuối\n"
	.string "ngươi được thấy ĐỘI MAGMA.\p"
	.string "Fufufu…\p"
	.string "Cho dù không có ĐÁ TRỜI, nếu tụi ta\n"
	.string "lấy được cái NGỌC đó… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Vậy là ngươi đã mò được tới tận đây!\p"
	.string "Nhưng đã quá trễ!\n"
	.string "Ta đã giao ĐÁ TRỜI ở THÁC SAO BĂNG\l"
	.string "cho ÔNG TRÙM rồi!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Kể cả có thua, nếu thủ lĩnh\n"
	.string "tụi ta đánh thức thứ đó…$"

MtChimney_Text_TabithaPostBattle:
	.string "ÔNG TRÙM, nhanh lên!\n"
	.string "Đưa cho nó năng lượng ĐÁ TRỜI!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Tụi ta, ĐỘI MAGMA, đang làm hết sức\n"
	.string "vì mọi người.\p"
	.string "Nếu thứ sức mạnh đó mở rộng thêm đất,\n"
	.string "thì sẽ có nhiều chỗ để sống hơn.\p"
	.string "Người ta sẽ vui mừng!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hửng?\n"
	.string "Là sao, ta thua rồi hả?$"

MtChimney_Text_Grunt2PostBattle:
	.string "ÔNG TRÙM nói, “Nó sẽ làm cho\n"
	.string "mọi người vui mừng.”\p"
	.string "Nhưng mà tại sao\n"
	.string "cứ cản đường tụi ta?$"

MtChimney_Text_Grunt1Intro:
	.string "Nếu có nhiều đất trống hơn, ta sẽ\n"
	.string "thưởng cho mình căn nhà thiệt bự!\p"
	.string "Ta sẽ xây trên lớp dung nham đông cứng!$"

MtChimney_Text_Grunt1Defeat:
	.string "Giấc mơ nhà bự của ta…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Một đứa con nít như ngươi, lẽ ra\n"
    .string "phải đang vui đùa trong sóng biển!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Cái ĐỘI AQUA phiền phức đó…\n"
	.string "Cứ phá kế hoạch của tụi ta!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "ĐÁ TRỜI sở hữu sức mạnh kinh ngạc!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Đừng có giỡn mặt!\p"
	.string "Tụi ta đánh thức thứ đó là vì\n"
	.string "lợi ích nhân loại thôi!$"

MtChimney_Text_AquasNameSimilar:
	.string "Tụi ta là ĐỘI MAGMA!\p"
	.string "Tụi nó là ĐỘI AQUA!\p"
	.string "Tụi nó cứ xài tên giống bên\n"
	.string "này, khó chịu ghê!$"

MtChimney_Text_DouseThemInFire:
	.string "Ừưư!\n"
    .string "Thiêu rụi tụi nó đi!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Tụi ta sẽ mở rộng thêm đất!$"

MtChimney_Text_Bufoh:
	.string "Ừgốấuuu!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "MUỘI: Gừư, {PLAYER}!\n"
	.string "Ta phải đoán trước ngươi sẽ xuất hiện!\p"
	.string "Tự mà coi những kẻ cuồng tín\n"
    .string "ĐỘI MAGMA đang âm mưu gì kìa!\p"
    .string "Tụi nó đang ráng truyền sức mạnh của\n"
    .string "viên ĐÁ TRỜI bị đánh cắp vô núi lửa!\p"
	.string "Làm vậy sẽ gây ra\n"
    .string "sự phun trào núi lửa đó!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "MUỘI: Gừư…\p"
	.string "Ta muốn cản cái người tên MÃ đó,\n"
	.string "nhưng mà không được!\p"
	.string "Ta đang bận đấu với\n"
	.string "3 đối thủ rồi!$"

MtChimney_Text_ArchieThankYou:
	.string "MUỘI: {PLAYER}!\n"
	.string "Cảm ơn ngươi!\p"
    .string "Nhờ có ngươi giúp đỡ, ta đã ngăn được\n"
    .string "kế hoạch hủy diệt của ĐỘI MAGMA!\p"
    .string "Nhưng mà… Nhà ngươi…\n"
	.string "Ngươi đứng về phe nào?\p"
    .string "À, mà sao cũng được.\p"
    .string "Tụi ta sẽ tiếp tục cảnh giác và\n"
    .string "truy đuổi ĐỘI MAGMA.\p"
    .string "{PLAYER}, ta sẽ sớm gặp lại nhau!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Chết tiệt… ĐỘI MAGMA đông hơn ta!\n"
    .string "Không theo kịp tụi nó được!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Nếu mở rộng đất, thì sẽ có ít\n"
    .string "môi trường sống hơn cho POKÉMON NƯỚC!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Tụi ta là ĐỘI AQUA!\p"
	.string "Tụi nó là ĐỘI MAGMA!\p"
	.string "Tụi nó cứ bắt chước tên làm\n"
	.string "ta khó chịu quá!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "BÁNH NÚI LỬA là đặc sản\n"
	.string "địa phương ở NÚI LỬA.\p"
	.string "Thử đi. Có ¥200 thôi.$"

MtChimney_Text_ThankYouDear:
	.string "Trời, cảm ơn nha!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Trời ơi. Bạn không đem tiền\n"
	.string "rồi sao mua cái gì được.$"

MtChimney_Text_OhFineThen:
	.string "À, vậy thôi.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "ĐÁ TRỜI được để vô cái\n"
	.string "máy kỳ lạ…\p"
	.string "Hình như cái máy đang trữ\n"
	.string "năng lượng bên trong ĐÁ TRỜI.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "ĐÁ TRỜI được để vô cái\n"
	.string "máy kỳ lạ…\p"
	.string "Bạn có muốn lấy ĐÁ TRỜI ra không?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} lấy ĐÁ TRỜI\n"
	.string "ra khỏi cái máy kỳ lạ.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} để ĐÁ TRỜI\n"
	.string "lại chỗ cũ.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cái máy kỳ lạ này…\n"
	.string "Nó không có phản ứng gì hết.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} ĐƯỜNG NHẤP NHÔ\n"
	.string "THỊ TRẤN NÚI LỬA PHÍA TRƯỚC$"

MtChimney_Text_ShelbyIntro:
	.string "Ta đã tới suối nước nóng để\n" 
	.string "thư giãn cho cơ thể mỏi mệt của mình.\l"
	.string "Cảm giác tràn đầy sức mạnh!$"

MtChimney_Text_ShelbyDefeat:
	.string "Trời đất ơi.\n"
	.string "Con là thứ gì đó rồi!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Ừ thì ta thua rồi. Ta không thể gọi\n"
	.string "mình là CAO THỦ được nữa đúng không?$"

MtChimney_Text_ShelbyRegister:
	.string "Cảm ơn con. Sẽ rất vui nếu được\n"
	.string "thách đấu với đứa cháu của ta.\p"
	.string "Làm ơn, nhớ quay lại đây\n"
	.string "tái đấu với ta nha.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Nếu con có thể hoà hợp trái tim với\n"
    .string "POKéMON, thì chắc chắn con sẽ\l"
    .string "đạt được thành tựu vĩ đại.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Trời đất ơi.\n"
	.string "Con là thứ gì đó rồi!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Có lẽ trái tim con đã hợp\n"
	.string "thành một với POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Ngọn lửa trong người mình.\n"
	.string "Không chịu được! Phải đấu thôi!$"

MtChimney_Text_MelissaDefeat:
	.string "Trời, đúng là trận đấu nảy lửa!$"

MtChimney_Text_MelissaPostBattle:
	.string "Cơn nóng của NÚI LỬA\n"
	.string "làm ấm cơ thể mình!$"

MtChimney_Text_SheilaIntro:
	.string "Cuối cùng cũng tới được NÚI LỬA.\n"
	.string "Tui muốn làm 1 trận đấu POKéMON!$"

MtChimney_Text_SheilaDefeat:
	.string "Cách bạn chiến đấu…\n"
	.string "Cứ như NÚI LỬA phun trào vậy!$"

MtChimney_Text_SheilaPostBattle:
	.string "Như đã nói, tui đã tới được\n"
	.string "NÚI LỬA rồi. Nếu mà chỉ đi ngắm cảnh\l"
	.string "thôi thì uổng lắm…\p"
	.string "Tui muốn làm mấy trận rồi đi mua\n"
	.string "BÁNH về làm quà.$"

MtChimney_Text_ShirleyIntro:
	.string "Bởi vì tui đã ngâm mình trong nước,\n"
	.string "tui cảm thấy sảng khoái hơn!\l"
	.string "Tui chắc chắc sẽ thắng!$"

MtChimney_Text_ShirleyDefeat:
	.string "Yowch!\n"
	.string "Nước tạt vô người, đỡ nóng hơn rồi.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Tui sẽ ngâm mình trong nước\n"
	.string "một lần nữa. Muốn đi chung hong?\p"
	.string "Giỡn thôi!$"

MtChimney_Text_SawyerIntro:
    .string "Đây là một ngọn núi tuyệt vời! Có\n"
    .string "nhiều người hấp dẫn để kết thân!$"

MtChimney_Text_SawyerDefeat:
    .string "Trời, cũng nhiệt huyết đó chớ!$"

MtChimney_Text_SawyerPostBattle:
    .string "Tui nghĩ mình cần ngâm mình trong\n"
    .string "suối nước nóng với dân bản địa NÚI LỬA!$"

MtChimney_Text_SawyerRegister:
    .string "Tui thích những người năng nổ như bạn.\n"
	.string "Cho tui lưu số vô BẢN ĐỒ nha.$"

MtChimney_Text_SawyerRematchIntro:
    .string "Rất vui khi được bao quanh bởi những\n"
    .string "người hấp dẫn. Tui sẽ không thua đâu!$"

MtChimney_Text_SawyerRematchDefeat:
    .string "Trời ơi, bạn vẫn là\n"
    .string "một kẻ nóng nảy như trước!$"

MtChimney_Text_SawyerPostRematch:
    .string "Thực ra, ở đây rất là nóng.\n"
    .string "Tui bận nhiều lớp đồ quá rồi.$"

