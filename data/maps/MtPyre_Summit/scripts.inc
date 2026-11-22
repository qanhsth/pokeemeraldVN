MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Chết rồi! Tụi MAGMA\n"
	.string "tới trước rồi!\p"
	.string "Không chần chừ được nữa!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Tưởng ngươi là tụi MAGMA\n"
	.string "chạy lại đây…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ừa, ngươi mạnh…\n"
	.string "Mà vẫn còn đông người lắm!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Quá xui cho nhà ngươi!\p"
	.string "Nếu tới sớm hơn, người chỉ cần\n"
	.string "thách đấu với tụi MAGMA thôi.\p"
	.string "Nhưng mà đã lỡ tới đây rồi,\n"
	.string "ngươi phải bước qua xác tụi ta!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… Lẽ ra ta nên để\n"
	.string "ngươi xử lý tụi MAGMA trước…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Ngươi có biết cái gì đâu!\n"
	.string "Vậy sao lại cản đường tụi ta?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Nhà ngươi…\n"
	.string "Ta thấy ngươi ở NÚI LỬA.\p"
	.string "Ngươi không thuộc ĐỘI nào,\n"
	.string "vậy tới đây làm chi?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Nếu muốn phá, thì sao\n"
	.string "không phá tụi MAGMA đi…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, kệ đi!\n"
	.string "Cũng mua được chút thời gian rồi!\p"
	.string "Kiểu gì ÔNG TRÙM cũng lấy được\n"
	.string "thứ mình muốn mà thôi!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "À, biết rồi!\n"
	.string "Ngươi tính gia nhập MAGMA,\l"
	.string "mà tụi nó không cho!\p"
	.string "Mà, đừng có nghĩ là tụi ta\n"
	.string "cho phép ngươi vô AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Nếu ngươi muốn vô AQUA tới vậy,\n"
	.string "tụi ta sẽ cân nhắc…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Ta sẽ có sự phối hợp hoàn hảo\n"
	.string "giữa thành viên và thủ lĩnh.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "MUỘI: MÃ, ĐỘI MAGMA, đã tới trước,\n"
	.string "nhưng mà chúng ta đã có thứ mình muốn.\p"
	.string "Viên NGỌC ĐỎ ở NÚI TIỄN ĐƯA…\n"
	.string "Giờ đã thuộc về ta!\p"
	.string "Fufufu… Giờ thì ta đã có thể biến mục\n"
    .string "tiêu cao thượng thành hiện thực!\p"
    .string "Được rồi, ĐỘI mình ơi!\n"
    .string "Rút lui đi!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Không…\n"
	.string "Không thể nào…\p"
	.string "Không chỉ NGỌC XANH, mà\n"
	.string "NGỌC ĐỎ cũng bị lấy đi…\p"
	.string "NGỌC XANH và NGỌC ĐỎ không được\n"
	.string "tách rời đi. Phải để chung một chỗ.\p"
	.string "Mấy con người này tính làm gì với\n"
	.string "2 viên NGỌC đó?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "À, phải rồi. ĐỘI MAGMA đã tới\n"
	.string "và lấy NGỌC XANH trước rồi thì phải?\p"
	.string "À, tụi nó gấp quá, nên để quên\n"
    .string "cái này.\p"
    .string "Bà không có hình dung được đây\n"
    .string "là cái gì.\p"
    .string "Bà muốn gởi lại cho con.\n"
    .string "Có thể sẽ hữu ích bằng cách nào đó.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "NGỌC XANH và NGỌC ĐỎ đã bị\n"
    .string "những kẻ đáng sợ đó lấy đi…\p"
    .string "2 viên ngọc không được tách rời nhau…\n"
    .string "Ta lo sợ điều gì đó khủng khiếp sẽ xảy ra…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Trời, đất…\p"
	.string "Bạn nói là cả 2 GROUDON và KYOGRE\n"
	.string "đều thức tỉnh?\p"
	.string "Người ta nói NGỌC XANH và\n"
    .string "NGỌC ĐỎ đã làm dịu 2 con\l"
    .string "POKÉMON lại…\p"
    .string "Cũng có người nói là chủ nhân thực sự\n"
    .string "của mấy viên NGỌC vẫn còn tồn tại.\p"
	.string "Tuy nhiên, không ai biết chính xác\n"
    .string "mấy viên NGỌC là gì, hay thuộc về ai.\p"
    .string "Có thể là một người, hoặc là một con\n"
    .string "POKéMON, mà chưa ai biết tới.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Hai con người lấy viên NGỌC đã\n"
	.string "tự mình đem trả lại rồi.\p"
	.string "Mấy người đó…\n"
	.string "Có lẽ cũng không tàn ác tới vậy…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Hiện thân của đất, biển,\n"
    .string "và bầu trời…\p"
    .string "Đó được cho là bản chất của\n"
    .string "những con POKéMON siêu cổ…\p"
	.string "Cũng giống như con người và POKéMON\n"
    .string "đều có sự sống, thế giới của chúng ta,\l"
    .string "cũng đang tồn tại…\p"
    .string "Những con POKéMON siêu cổ đã\n"
    .string "dạy cho chúng ta điều đó…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "NÚI TIỄN ĐƯA là nơi để xoa dịu\n"
    .string "linh hồn của POKéMON đã khuất…\p"
    .string "Đây là một nơi rất cao, nơi người ta\n"
    .string "có thể nhìn bao quát toàn bộ HOENN…\p"
    .string "Những linh hồn không còn thể xác đó\n"
	.string "sẽ được xoa dịu tại nơi đây…\p"
    .string "Con có mặt ở đây có phải là tình cờ…\p"
    .string "Con có sẵn lòng nghe câu chuyện đã\n"
    .string "được truyền tụng từ lâu ở vùng HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Đã từ rất lâu…\p"
	.string "Thế giới đã bị tàn phá bởi cuộc\n"
    .string "đụng độ khốc liệt giữa POKéMON trên\l"
    .string "đất liền và POKéMON dưới biển…\p"
	.string "POKéMON trên đất liền đã nâng cao\n"
    .string "những ngọn núi và tạo ra các lục địa…\p"
    .string "POKéMON dưới biển đã dâng lên những con\n"
    .string "sóng khổng lồ và tạo ra các đại dương…\p"
	.string "Cuộc chiến khốc liệt đã kéo dài vô tận.\p"
    .string "Thế giới chìm trong màn lửa to lớn\n"
    .string "và những cơn bão dữ dội.\p"
    .string "NGỌC XANH và NGỌC ĐỎ đã\n"
    .string "chấm dứt thảm hoạ.\p"
	.string "Ánh sáng tuôn trào từ 2 viên NGỌC,\n"
    .string "làm dịu cơn thịnh nộ của 2 bên.\p"
    .string "Cả hai, giờ đã trở nên hiền lành,\n"
    .string "lặn sâu xuống biển cả, nơi cuối cùng\l"
    .string "được thấy tụi nó…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Vậy ha…\n"
	.string "Ừ, thì, thôi vậy…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MÃ: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Nghĩa vụ của tôi là truyền lại cho\n"
    .string "con cháu về truyền thuyết của HOENN.\p"
	.string "Và cuộc khủng hoảng vừa kết thúc tại\n"
    .string "LƯU NIẾT đã viết lại truyền thuyết…\p"
    .string "Bạn có muốn dành chút thời gian để nghe\n"
    .string "truyền thuyết mới của HOENN không?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Đã từ rất lâu…\p"
	.string "Thế giới đã bị tàn phá bởi cuộc\n"
    .string "đụng độ khốc liệt giữa POKéMON trên\l"
    .string "đất liền và POKéMON dưới biển…\p"
	.string "POKéMON trên đất liền đã nâng cao\n"
    .string "những ngọn núi và tạo ra các lục địa…\p"
    .string "POKéMON dưới biển đã dâng lên những con\n"
    .string "sóng khổng lồ và tạo ra các đại dương…\p"
	.string "Cuộc chiến khốc liệt đã kéo dài vô tận.\p"
    .string "Thế giới chìm trong màn lửa to lớn\n"
    .string "và những cơn bão dữ dội.\p"
    .string "Chính lúc đó, POKéMON trên\n"
    .string "bầu trời đã hạ xuống từ cơn bão.\p"
    .string "POKéMON đó, toả sáng xanh lục rực rỡ,\n"
	.string "làm dịu đi cơn giận của 2 con POKéMON.\p"
    .string "Sau đó, khi hoàn thành nghĩa vụ, POKéMON\n"
    .string "xanh lục đã bay vào bầu trời xanh thẳm…$"

