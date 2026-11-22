SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Hú! Chao xìn, ứng cử viên\n"
	.string "VÔ ĐỊCH {PLAYER}!\p"
	.string "CHỦ GYM LƯU NIẾT, CHUẨN, là\n"
	.string "bậc thầy sử dụng POKéMON hệ NƯỚC.\p"
	.string "Và, để tới được chỗ CHUẨN, cái sàn\n"
	.string "đóng băng sẽ cản bạn lại…\p"
	.string "Nói nghe, xin lỗi, nhưng mà đó là\n"
	.string "tất cả những gì tui có thể khuyên.\p"
	.string "Phần còn lại, bạn phải tự mình\n"
	.string "khám phá ra thôi!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Chời! Bạn còn hạ được CHUẨN, người\n"
	.string "mà gần như là mạnh nhất HOENN luôn!\p"
	.string "Rồi! Kiểm tra lại THẺ HUẤN LUYỆN đi.\p"
	.string "Nếu mà có được hết HUY HIỆU rồi, thì\n"
	.string "bạn có thể tham gia LIÊN ĐOÀN POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Ta hỏi ngươi.\n"
    .string "Ngươi có biết?\l"
    .string "À, không giấu diếm gì nữa.\p"
    .string "Chính ta là người đã dạy HẢI LY tất\n"
    .string "cả những gì cần biết về POKéMON.\p"
	.string "Có một lần, ta đã từ bỏ vị trí\n"
    .string "CHỦ GYM.\p"
    .string "Thay vào đó, ta đã giao phó cho HẢI LY\n"
    .string "quản lý NHÀ THI ĐẤU.\p"
    .string "Tuy nhiên, có một lý do đã thuyết phục\n"
    .string "ta phải quay trở lại.\p"
	.string "À, mà thôi không cần nhiều lời.\n"
    .string "Bắt đầu trận đấu thôi chứ hả?\p"
    .string "Hãy chứng kiến\n"
    .string "tài nghệ của ta.\p"
    .string "Một bức hoạ về làn nước được\n"
    .string "khắc hoạ bởi chính ta và POKéMON!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, xuất sắc!\n"
	.string "Rất giỏi, ngươi là kẻ thắng cuộc.\p"
	.string "Ta cảm nhận được ánh sáng rực rỡ\n"
    .string "của kỹ năng vượt trội từ ngươi.\p"
    .string "Mà, so với ta hay thậm chí là HẢI LY,\n"
    .string "ngươi vẫn còn thiếu sự thanh lịch.\p"
    .string "Có lẽ ta nên cho ngươi mượn\n"
    .string "bộ trang phục của ta?\p"
	.string "… … … … … …\n"
    .string "… … … … … …\p"
    .string "Hahaha, ta giỡn thôi!\p"
    .string "Thay vì trang phục, ta sẽ thưởng\n"
    .string "cho ngươi cái này, HUY HIỆU MƯA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} nhận HUY HIỆU MƯA\n"
	.string "từ CHUẨN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Có HUY HIỆU MƯA trong tay, sẽ làm\n"
	.string "dịu lại sự bướng bỉnh của tất cả\l"
	.string "POKéMON mà ngươi sở hữu.\p"
	.string "HUY HIỆU MƯA cũng sẽ cho phép ngươi\n"
	.string "sử dụng chiêu HM LEO THÁC để leo\l"
	.string "lên bức tường nước đổ xuống xối xả.\p"
	.string "Và, để ngươi không quên trận đấu\n"
	.string "ngày hôm nay, hãy nhận lấy…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "Cái MÁY HỌC CHIÊU ẨN ta đưa cho\n"
	.string "có chứa SÓNG NƯỚC.\p"
	.string "Khi sử dụng, nó sẽ gây rối mục tiêu\n"
	.string "bằng loạt sóng siêu âm.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Lưu số CHỦ GYM CHUẨN\n"
	.string "vô BẢN ĐỒ.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "NHL đã thu tập đủ HUY HIỆU ở các\n"
	.string "NHÀ THI ĐẤU HOENN nên hướng tới\l"
	.string "đích đến cuối cùng.\p"
	.string "LIÊN ĐOÀN POKéMON.\p"
	.string "Tiến tới vùng cực đông của HOENN,\n"
	.string "hòn đảo SẮC MÀU.\p"
	.string "Tại đó, ngươi sẽ tìm được\n"
	.string "LIÊN ĐOÀN POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Vẫn còn thiếu một HUY HIỆU\n"
	.string "có thể lấy được ở HOENN.\p"
	.string "Nếu muốn được tham gia LIÊN ĐOÀN\n"
	.string "POKéMON, ngươi phải lấy được HUY HIỆU\l"
	.string "cuối ở NHÀ THI ĐẤU TP.CÂY.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "NHÀ THI ĐẤU TP.LƯU NIẾT$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU TP.LƯU NIẾT\p"
	.string "CHUẨN CÔNG NHẬN CHO NHL:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "CHUẨN: Aaa, cái NHÀ THI ĐẤU này mới\n"
	.string "trở lại trạng thái bình yên…\p"
	.string "Nhưng một cơn bão mới đã quay trở lại\n"
    .string "để thử thách chúng ta một lần nữa!\p"
    .string "Trời, chắc chắn là vậy rồi!\p"
    .string "Ta sẵn lòng đón tiếp\n"
    .string "ngươi bao nhiều lần cũng được!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, ngươi là kẻ thắng cuộc!\n"
	.string "Lại bị ngươi đánh bại rồi!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "CHUẨN: Nếu ta kêu ngươi làm\n"
	.string "đệ tử, ngươi sẽ từ chối, chắc luôn.\p"
	.string "Ta sẽ làm cho ngươi một món\n"
	.string "từ cái áo choàng của ta.\p"
	.string "Nhưng mà, ngươi sẽ lại từ chối.\n"
	.string "Ta chỉ tưởng tượng thôi.\p"
	.string "Và đây, nhà ngươi, kẻ tượng trưng\n"
	.string "cho tầng lớp cao quý!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "CHUẨN: Aaa, cái NHÀ THI ĐẤU này mới\n"
	.string "trở lại trạng thái bình yên…\p"
	.string "Nhưng một cơn bão mới đã quay trở lại\n"
    .string "để thử thách chúng ta một lần nữa!\p"
    .string "Trời, chắc chắn là vậy rồi!\n"
	.string "Ta rất vui lòng được đón tiếp…\p"
	.string "À, không, không, không, không.\n"
	.string "Ngươi chỉ có 1 con POKéMON.\p"
	.string "Mong rằng ngươi sẽ quay lại với\n"
	.string "2, có thể hơn, số POKéMON trong đội.$"

