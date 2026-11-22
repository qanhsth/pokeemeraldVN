FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Chao xìn, NHÀ VÔ ĐỊCH\n"
	.string "của tương lai {PLAYER}!\p"
	.string "CHỦ GYM TP.CÂY, QUỲNH NHƯ,\n"
	.string "là bậc thầy về POKéMON hệ BAY.\p"
	.string "Cổ đang chờ ở sau NHÀ THI ĐẤU,\n"
	.string "phía sau cửa quay á.\p"
	.string "Cổ đang chờ người thách đấu\n"
	.string "tới để vặt lông!\p"
	.string "Được rồi, vô đi!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Bạn làm được rồi!\n"
	.string "Bạn đã cất cánh thành công!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Hãy chiêm ngưỡng phong thái\n"
	.string "lịch thiệp của POKéMON CHIM!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Bạn…\n"
	.string "Bạn cũng… mạnh$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Một NHL khôn khéo là phải biết\n"
	.string "cách xoay chuyển tình huống.\p"
	.string "Nhưng mà cái khôn khéo đó liệu\n"
	.string "có ăn được CHỦ GYM tụi tui?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Người yêu POKéMON CHIM khao\n"
	.string "khát được vô NHÀ THI ĐẤU này.\p"
	.string "Là 1 thành viên ở đây,\n"
	.string "tui không được phép thua!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Gánh nặng quá lớn,\n"
	.string "không gánh vác nỗi…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Thế giới rất rộng lớn, và\n"
	.string "có vô số NHL mạnh ngoài kia.\p"
	.string "Tui sẽ tiếp tục tập luyện bản\n"
	.string "thân để trở nên mạnh hơn nữa.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Không cần CHỦ GYM, QUỲNH NHƯ,\n"
	.string "phải ra tay!\p"
	.string "Chỉ cần tui là đủ!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "QUỲNH NHƯ ơi, tui…\n"
	.string "Thua rồi!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "QUỲNH NHƯ vừa xinh vừa mạnh.\n"
	.string "Cổ là người CHỦ GYM toàn năng!\p"
	.string "Ngại quá…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "QUỲNH NHƯ kèm riêng cho tui đó!\n"
	.string "Bạn không có thắng dễ được đâu!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Bị đánh bại rồi…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Nhờ QUỲNH NHƯ mà mọi người\n"
	.string "ở TP.CÂY có thể sống thoải mái.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Khi QUỲNH NHƯ thách đấu, mặt cổ\n"
	.string "sáng lên rạng ngời…\p"
	.string "Tui sẽ không cho bạn chiêm\n"
	.string "ngưỡng khung cảnh đó đâu!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Ực!\n"
	.string "Không cản được rồi.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Bạn coi chừng đó!\n"
	.string "Đừng có bị QUỲNH NHƯ làm xao nhãng\l"
	.string "không là bạn sẽ té xuống hố sâu đó!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Nhà ngươi nên biết là có\n"
	.string "rất nhiều loại POKéMON hệ BAY.\p"
	.string "Có biết không hả?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Cũng rành rọt đó chớ!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Ừ thì ngươi đã hạ được ta.\n"
	.string "Nhưng hãy coi chừng! POKéMON\l"
	.string "của QUỲNH NHƯ khó chơi lắm đó.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Tui là QUỲNH NHƯ. Tui là\n"
	.string "CHỦ GYM TP.CÂY.\p"
	.string "Tui đã hoà làm một với POKéMON\n"
    .string "CHIM và bay lượn trên bầu trời…\p"
	.string "Dù trận chiến có khắc nghiệt tới đâu,\n"
    .string "tụi tui cũng thắng 1 cách trang nhã…\p"
    .string "Hãy chiêm ngưỡng điệu múa uyển chuyển\n"
    .string "của tui và POKéMON CHIM!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Chưa bao giờ gặp được một NHL\n"
    .string "điều khiển POKÉMON duyên dáng\l"
    .string "hơn mình…\p"
    .string "Để ghi nhận tài năng của bạn,\n"
    .string "tui xin trao tặng bạn HUY HIỆU này.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} nhận HUY HIỆU LÔNG VŨ\n"
	.string "từ QUỲNH NHƯ.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Có HUY HIỆU LÔNG VŨ, tất cả POKéMON,\n"
	.string "kể cả những con nhận được khi trao\l"
	.string "đổi, sẽ nghe lời bạn cho tới Cấp 70.\p"
	.string "Bạn cũng sẽ có thể sử dụng chiêu\n"
	.string "HM BAY ngoài ván đấu.\p"
	.string "Và còn cái này…\n"
	.string "Là quà của tui dành cho bạn.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 có chứa PHẢN LỰC.\p"
	.string "Tốc độ của nó…\n"
	.string "Không POKéMON nào né được.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Lưu số CHỦ GYM QUỲNH NHƯ\n"
	.string "vô BẢN ĐỒ.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Dù đã phải lòng bạn, nhưng tui vẫn\n"
    .string "sẽ trung thành với POKéMON CHIM.$"

FortreeCity_Gym_Text_GymStatue:
	.string "NHÀ THI ĐẤU TP.CÂY$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU TP.CÂY\p"
	.string "QUỲNH NHƯ CÔNG NHẬN NHL:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "QUỲNH NHƯ: Con người chúng ta\n"
	.string "không bao giờ thoát được trọng lực.\p"
	.string "Nhưng bằng cách phấn đấu nỗ lực,\n"
    .string "chúng ta có sức mạnh để vươn cao!\p"
    .string "Bạn đã chinh phục đỉnh cao với\n"
    .string "tư cách là NHÀ VÔ ĐỊCH đương nhiệm.\p"
    .string "Xin hãy cho tui chiêm ngưỡng sức mạnh\n"
    .string "khi bạn đang bay với tốc độ tối đa!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Tui không chạm được độ cao đó…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "QUỲNH NHƯ: Cho dù đã thua,\n"
	.string "đôi cánh trong tim tui vẫn không gãy.\p"
	.string "Tui có thể vươn lên và bay cao\n"
    .string "một lần nữa, một lần nữa.\p"
    .string "Tui tin chắc là sẽ như vậy!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "QUỲNH NHƯ: Con người chúng ta\n"
	.string "không bao giờ thoát được trọng lực.\p"
	.string "Nhưng bằng cách phấn đấu nỗ lực,\n"
    .string "chúng ta có sức mạnh để vươn cao!\p"
    .string "Bạn đã chinh phục đỉnh cao với\n"
    .string "tư cách là NHÀ VÔ ĐỊCH đương nhiệm.\p"
    .string "Xin hãy cho tui chiêm ngưỡng sức mạnh\n"
    .string "khi bạn đang bay với tốc độ tối đa!\p"
	.string "Ủa, mà… Sao bạn đem có\n"
	.string "1 POKéMON vậy?\p"
	.string "Hãy đem ít nhất 2 con POKéMON\n"
	.string "khi trở lại đây.$"
