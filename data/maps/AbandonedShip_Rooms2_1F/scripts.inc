AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "ĐAN: Trong lúc tìm kho báu,\n"
	.string "chúng ta phát hiện ra 1 NHL!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "ĐAN: Tụi tui không thắng được\n"
	.string "dù đã phối hợp mượt mà như vậy…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "ĐAN: Tụi tui không thấy kho báu…\n"
	.string "Không lẽ có người lấy rồi?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "ĐAN: Bạn còn không có nổi 2 POKéMON.\n"
	.string "Vậy cũng đòi thách đấu tụi tui.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIM: Ủa?\n"
	.string "Tụi tui đang tìm kho báu.\l"
	.string "Mà lại phát hiện ra NHL!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIM: Trời, mạnh quá!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIM: Kho báu ở chỗ nào ta?\p"
	.string "Tui đã quyết định được sẽ mua món gì\n"
	.string "khi tìm ra được kho báu!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIM: Ủa bạn không có 2 POKéMON?\n"
	.string "Vậy lần khác thách đấu nha!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIM: Trời, bạn làm tui bực quá!\n"
	.string "Tui sẽ lưu số bạn luôn!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "ĐAN: Tụi tui đi kiếm kho báu\n"
	.string "hổm rày rồi.\p"
	.string "POKéMON cũng mạnh lên rồi.\n"
	.string "Để tui cho bạn coi nha?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "ĐAN: Bạn vẫn mạnh như mọi khi!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "ĐAN: Không kiếm được kho báu,\n"
	.string "thua POKéMON luôn…\p"
	.string "Muốn đi về quá… Nếu mà tui nói vậy,\n"
	.string "chắc cổ giận tui cho coi…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "ĐAN: Bạn còn không có nổi 2 POKéMON.\n"
	.string "Vậy cũng đòi thách đấu tụi tui.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIM: Ủa? Gặp lại rồi!\p"
	.string "Bạn vẫn đang kiếm kho báu,\n"
	.string "giống tụi tui đúng không?\p"
	.string "Giờ ai mà thua thì\n"
	.string "bỏ đi nha, chịu không?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIM: Trời, thua nữa…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIM: Tụi tui sẽ không rời đi\n"
	.string "cho tới khi POKéMON mạnh lên và\l"
	.string "tìm thấy được kho báu!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIM: Ủa bạn không có 2 POKéMON?\n"
	.string "Vậy lần khác thách đấu nha!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Tui không giỏi bơi,\n"
	.string "nhưng thách đấu thì khác!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ụa.\n"
	.string "Vậy là không ổn rồi.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Đi chưn không trên tàu này,\n"
	.string "cảm giác hơi dơ.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
    .string "Sức mạnh và lòng trắc ẩn…\n"
    .string "Là báu vật của một NHL!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
    .string "À, có điều gì đó ở cậu\n"
	.string "khiến cậu tỏa sáng.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
    .string "Trong một cabin nào đó trên tàu,\n"
    .string "tôi đã thấy thứ gì đó lấp lánh.$"
