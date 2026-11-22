MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Ê, dạo này sao rồi, ứng cử viên VÔ ĐỊCH\n"
	.string "{PLAYER}?\p"
	.string "QUÁCH, CHỦ GYM TP.HOA TÍM,\n"
	.string "xài POKéMON hệ ĐIỆN.\p"
	.string "Nếu mà bạn xài POKéMON hệ NƯỚC,\n"
	.string "thì sẽ bị giựt banh xác! Xẹt xẹt!\p"
	.string "Với lại, ổng có làm cửa điều khiển\n"
	.string "bằng công tắc ở đây! Kỳ quặc ha!\p"
	.string "Rồi, chơi hết mình đi!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, bạn thật hại điện!\n"
	.string "Bạn làm cửa mở luôn!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Tâm hồn điện từ, sẽ làm tan nát\n"
	.string "mơ ước của ngươi, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Cắm điện, tăng âm ly,\n"
	.string "chơi tiếp đi, bạn hỡi!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON và đá, tất cả về con tim,\n"
	.string "whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Tui được QUÁCH huấn luyện cho rồi!\n"
	.string "Sao mà thua dễ được!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Rút dây, tắt điện…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "QUÁCH, CHỦ GYM tụi tui, đã\n"
	.string "ở đây rất, rất lâu rồi.\p"
	.string "Ổng đã thách đấu từ lúc ba bạn\n"
	.string "chưa ra đời luôn, lão chiến lắm.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "GYM này đánh đố quá!\n"
	.string "Mà cũng vui phải không?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Thua sao vui được…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "QUÁCH nói là ổng có làm bẫy\n"
	.string "ở mấy chỗ công tắc.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Với sức hút của tui và chuyển động\n"
	.string "của POKéMON, bạn sẽ rất sốc cho coi!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Sức mạnh của bạn làm tui sốc quá!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Tui nghe nói HOA TÍM được ông\n"
	.string "QUÁCH thành lập.\p"
	.string "Ổng là NHL rất là lâu đời\n"
	.string "trước lúc tụi tui là NHL luôn.\l"
	.string "Ổng biết nhiều cái lắm!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Tui thích mấy cái sáng chói!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Trời ơi…\n"
	.string "Có gì trong mắt tui…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "NHÀ THI ĐẤU HOA TÍM của QUÁCH có\n"
	.string "sân đấu rất sáng. Tui rất hài lòng!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Ta đã từ bỏ kế hoạch cải tạo\n"
    .string "thành phố này rồi.\p"
    .string "Vì vậy, ta dành thời gian để chế tạo\n"
    .string "bẫy cửa trong NHÀ THI ĐẤU của mình.\p"
    .string "Ủa? Vậy rồi, con làm gì ở đây vậy?\p"
    .string "Con nói sao? Con nói con đã vượt qua\n"
    .string "được hết bẫy cửa của ta sao?\p"
    .string "Wahahahah!\n"
    .string "Chà, chuyện này thật thú vị!\p"
    .string "Vậy thì, ta, QUÁCH, CHỦ của NHÀ THI ĐẤU\n"
    .string "HOA TÍM, sẽ cho con một cú sốc điện!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah!\n"
	.string "Thôi, ta nhận thua!\p"
	.string "Con đã cho ta màn thi đấu đầy ấn tượng!\n"
	.string "Cầm lấy HUY HIỆU đi!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} nhận HUY HIỆU ĐIỆN\n"
	.string "từ QUÁCH.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Với HUY HIỆU ĐIỆN trong tay, POKéMON\n"
	.string "có thể thi triển ĐẬP ĐÁ ngoài ván đấu.\p"
	.string "Với lại, nó cũng cho POKéMON 1 xíu\n"
	.string "tốc độ nữa.\p"
	.string "Hmm…\n"
	.string "Con cũng nên cầm cái này đi!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Cái TM34 đó có chứa PHÓNG ĐIỆN.\p"
	.string "Đó là một chiêu thức không bao giờ\n"
	.string "hụt! Con cứ tin tưởng mà xài đi!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Lưu số CHỦ GYM QUÁCH\n"
	.string "vô BẢN ĐỒ.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Ta đã lạc quan hơn khi thấy một\n"
    .string "tài năng trẻ, đầy triển vọng như con!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Tiến xa hơn nữa đi, nhóc con!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "NHÀ THI ĐẤU TP.HOA TÍM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU TP.HOA TÍM\p"
	.string "QUÁCH CÔNG NHẬN NHL:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "QUÁCH: À ha! Cuối cùng thì!\n"
	.string "Ta biết con muốn gì rồi.\l"
	.string "Con muốn thách đấu POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Ta sẽ công kích điện vô người con!\n"
	.string "Ta cảnh báo trước rồi đó!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ủa…\n"
	.string "Hết pin rồi…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "QUÁCH: Tụi ta sẽ sạc lại\n"
	.string "pin sau.\p"
	.string "Khi mà sạc đầy rồi, ta sẽ\n"
	.string "chấp nhận lời thách đấu của con.\p"
	.string "Nên là, nhớ lâu lâu quay lại,\n"
	.string "nha?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "QUÁCH: À ha! Cuối cùng thì!\n"
	.string "Ta biết con muốn gì rồi.\l"
	.string "Con muốn thách đấu POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Ủa! Khoan!\n"
	.string "Con đem có 1 con POKéMON vậy!\p"
	.string "Đi lấy thêm mấy con\n"
	.string "POKéMON nữa rồi quay lại nha!$"
