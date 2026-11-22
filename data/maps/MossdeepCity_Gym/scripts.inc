MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Hú, ứng cử viên\n"
	.string "VÔ ĐỊCH, {PLAYER}!\p"
	.string "Hai vị CHỦ GYM ở đây xài\n"
	.string "POKéMON hệ MA QUÁI.\p"
	.string "Nếu bạn xài POKéMON hệ\n"
	.string "VÕ SĨ hoặc là hệ ĐỘC để đối phó,\l"
	.string "thì sẽ càng bị ăn đấm mạnh hơn!\p"
	.string "Hơn nữa, đòn phối hợp của họ\n"
	.string "gây ra ST không tưởng đó.\p"
	.string "Nếu muốn thắng, POKéMON của bạn\n"
	.string "cần phải ngang sức với họ mới được.\l"
	.string "Rồi chiến đi!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Trời, cũng dữ dằn á chớ!\n"
	.string "Bạn đúng là NHL tài ba!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Thắng bại phụ thuộc sức mạnh tinh thần!\n"
    .string "Tinh thần mà yếu, không thắng được đâu!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Ta thua rồi!\n"
	.string "Ta cần phải luyện tâm trí thêm!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Lưỡng lự là thua.\n"
	.string "Ta cảnh báo ngươi vậy thôi.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Hãy cho ta thấy tài nghệ của ngươi!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Ta đã thấy tài nghệ của ngươi!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Nếu thế giới này có thần đồng,\n"
	.string "thì CHỦ GYM tụi ta là một trong số đó!\p"
	.string "Tuy nhiên, ngươi còn có thể bứt phá\n"
	.string "hơn họ nữa…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Hãy nhìn ta điều khiển\n"
	.string "QUẢ CẦU POKéMON bằng siêu năng lực!\p"
	.string "Gàoooooooooo!\n"
	.string "… … … … … … …\p"
	.string "Lâu lâu, ta bị trật nhịp…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Kỹ năng chiến đấu của POKéMON cũng\n"
	.string "trật nhịp luôn!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Quả CẦU POKéMON nặng quá, không\n"
    .string "nâng lên được. Nhưng cục bụi này thì…\p"
    .string "Phùuuuuuuuuuuuu!\n"
    .string "… … … … … …\p"
    .string "Không có, tui không có ăn gian!\n"
	.string "Tui đâu có thổi vô đâu! Thiệt mà!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Nếu mà thua ta, thì\n"
	.string "đừng có hà khắc bản thân quá.\p"
	.string "Không phải vì ngươi yếu--tại\n"
	.string "ta quá mạnh mà thôi!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Ngươi chỉ là, quá mạnh mà thôi!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Ta không buồn chỉ vì thua cuộ.\n"
	.string "Ta chỉ cần tập luyện nhiều hơn thôi.\p"
	.string "Suy nghĩ tích cực--đó mới là\n"
	.string "điểm mạnh của ta!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ta đã thấy…\n"
	.string "Ta đã thấy tương lai của ngươi…\p"
	.string "Nếu hạ được ta, ta sẽ\n"
	.string "nói cho ngươi biết!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Ta đầu hàng!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Ngươi sẽ có một trận chiến vô cùng khốc\n"
    .string "liệt với hai vị CHỦ GYM của tụi ta…\p"
	.string "Kết cục thì…\n"
	.string "Ngươi sẽ không biết được đâu!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Con đường ngươi đã đi qua…\n"
	.string "Những gì ngươi đã trải qua…\p"
	.string "Đem hết những thứ mà ngươi\n"
	.string "có, ra đây!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Ngươi đã đi đúng đường rồi đó!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Tương lai tươi sáng đang chờ cho\n"
    .string "những người làm việc chăm chỉ.\p"
    .string "Còn những kẻ lười biếng, cuối cùng\n"
    .string "chỉ còn lại sự tuyệt vọng.\p"
    .string "Gieo nhân nào gặt quả nấy…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Ta sẽ thắng trận này,\n"
	.string "kể cả có liều mạng đi nữa!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Ngươi đã làm…\n"
	.string "Ta phải khiếp sợ…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Sao ngươi dám hạ gục ta…\p"
	.string "Nếu có chuyện kinh khủng xảy ra với\n"
	.string "ngươi, thì đó không phải lỗi của ta…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hô hô hô.\p"
	.string "Ngươi có cần ta phải dạy cho ngươi\n"
	.string "biết hệ MA QUÁI dai cỡ nào không?$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Ủa! Trời, trời!\n"
	.string "Phong cách chiến đấu quá hay!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Ta… ta không để cái thua làm mình\n"
    .string "h-hoảng, dù có t-tệ tới đâu.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Để ta cho ngươi giây phút\n"
	.string "kinh hoàng, sợ hãi nhất!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "Tr-trờiiiii!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Đừng có lây sức sống tràn đầy đó cho ta!\n"
	.string "Né ra giùm cái!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Ta có thể hết thời, nhưng mà\n"
	.string "đừng có khi dễ ta.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "À thì, ngươi có cái\n"
	.string "sức mạnh tuổi trẻ!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Có lẽ ta đã không thể\n"
	.string "vượt qua sức trẻ được rồi.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Ngươi sẽ không thể tới đích!\n"
	.string "Nếu không có ta!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Sao có thể mạnh một cách\n"
	.string "ba trợn như vậy được?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hừ! Ngươi có thể mạnh, nhưng mà\n"
	.string "không hợp với hệ MA QUÁI đâu!\p"
	.string "Cách mà ngươi chiến đấu quá bạo lực!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Gàooo! Hãy nếm mùi của\n"
	.string "POKéMON siêu khó nuốt của ta!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Trời!\n"
	.string "Xong luôn!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Thôi được! Ta nghĩ mình cần nâng\n"
	.string "cấp sức mạnh vô hình cho POKéMON.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "PHÙ: Hehehe… Ngạc nhiên chưa?\p"
	.string "LAN: Fufufu… Bất ngờ chưa?\p"
	.string "PHÙ: Khi mà có tới hai vị CHỦ GYM?\n"
	.string "LAN: Khi mà có tới hai vị CHỦ GYM?\p"
	.string "PHÙ: Tụi tui sinh đôi!\n"
	.string "LAN: Tụi tui sinh đôi!\p"
	.string "PHÙ: Không cần phải nói bởi…\n"
	.string "LAN: Hai đứa đều biết được…\p"
	.string "PHÙ: Suy nghĩ của đứa kia…\n"
	.string "LAN: Cả hai có cùng suy nghĩ!\p"
	.string "PHÙ: Sự phối hợp của tụi tui…\n"
	.string "LAN: Liệu bạn có phá được không?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "PHÙ: Hả?! Sự phối hợp của tụi tui…\n"
	.string "LAN: Bị phá tan tành!\p"
	.string "PHÙ: Thôi bó tay. Bạn thắng rồi…\n"
	.string "LAN: Thôi, để ghi nhận, hãy cầm.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} nhận HUY HIỆU TỊNH\n"
	.string "từ PHÙ và LAN.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "PHÙ: HUY HIỆU TỊNH giúp tăng cường\n"
	.string "ST.PHÉP với G.PHÉP cho POKéMON.\p"
	.string "LAN: Nó cũng cho phép bạn xài\n"
	.string "chiêu HM LẶN ngoài ván đấu.\p"
	.string "PHÙ: Bạn cũng lấy cái này đi.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "PHÙ: Cái TM04 đó có…\n"
	.string "LAN: TỊNH TÂM!\p"
	.string "PHÙ: Giúp tăng ST.PHÉP và…\n"
	.string "LAN: Giúp tăng G.PHÉP!\p"
	.string "PHÙ: Là một chiêu thức hoàn toàn…\n"
	.string "LAN: Phù hợp cho POKéMON hệ MA QUÁI!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Lưu số CHỦ GYM PHÙ & LAN\n"
	.string "vô BẢN ĐỒ.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "PHÙ: Có vẻ như sợi dây gắn kết\n"
	.string "giữa bạn và POKéMON còn chắc hơn\l"
	.string "là hai đứa sinh đôi tụi tui.\p"
	.string "LAN: Bạn sẽ còn trở nên mạnh hơn!\n"
	.string "Tụi tui đấu rồi nên mới biết.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "PHÙ: Hehehe… Bạn có ngạc nhiên?\p"
	.string "LAN: Khi có tới hai vị CHỦ GYM?\p"
	.string "PHÙ: Ủa, mà bạn chỉ có…\n"
	.string "LAN: 1 POKéMON để chiến đấu.\p"
	.string "PHÙ: Tụi tui không có đấu như vậy được!\p"
	.string "LAN: Nếu bạn muốn thách đấu,\n"
	.string "thì hãy đem nhiều POKéMON hơn.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "NHÀ THI ĐẤU TP.XANH RÊU$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU TP.XANH RÊU\p"
	.string "PHÙ VÀ LAN CÔNG NHẬN CHO NHL:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "PHÙ: POKéMON…\n"
	.string "LAN: POKéMON…\p"
	.string "PHÙ: Nếu đổi thứ tự trong đội…\n"
	.string "LAN: Phong cách chiến đấu sẽ thay đổi.\p"
	.string "PHÙ: Nhưng mà tui…\n"
	.string "LAN: Nhưng mà tui…\p"
	.string "PHÙ: Vẫn sẽ ở bên LAN!\n"
	.string "LAN: Vẫn sẽ ở bên PHÙ!\p"
	.string "PHÙ: Sự phối hợp của tụi tui…\n"
	.string "LAN: Tụi tui sẽ cho bạn thấy nữa!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "PHÙ: Bạn và POKéMON…\n"
	.string "LAN: Cứ như là anh chị em vậy!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "PHÙ: Bạn có hạ được tụi tui đi nữa,\n"
	.string "thì tụi tui vẫn sẽ đứng dậy!\p"
	.string "LAN: Bởi vì hai đứa tụi tui,\n"
	.string "lúc nào cũng hỗ trợ cho nhau!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "PHÙ: Bạn quay lại rồi…\n"
	.string "LAN: Bạn quay lại rồi…\p"
	.string "PHÙ: Để cho tụi tui trận tái đấu.\n"
	.string "LAN: Để cho tụi tui trận tái đấu.\p"
	.string "PHÙ: Nhưng mà…\n"
	.string "LAN: Với trận đấu này…\p"
	.string "PHÙ: Bạn chỉ đem có 1 POKéMON!\n"
	.string "LAN: Bạn chỉ đem có 1 POKéMON!\p"
	.string "PHÙ: Tụi tui cần bạn phải đem…\n"
	.string "LAN: Ít nhất là 2 POKéMON khi quay lại.$"
