CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "À, vậy bạn là {PLAYER} hả?\n"
	.string "Tui có nghe kể về chiến công của bạn.\p"
    .string "Tên tui là HẢI LY.\p"
    .string "Tui từng là CHỦ GYM của LƯU NIẾT,\n"
    .string "nhưng mà do có việc đột xuất.\p"
	.string "Nên là, tui mới nhờ cho người thầy của\n"
    .string "mình, CHUẨN, quản lý NHÀ THI ĐẤU.\p"
    .string "… … … … … …\n"
    .string "… … … … … …\p"
    .string "GROUDON và KYOGRE, hai con POKéMON\n"
	.string "đang gây hỗn loạn ở đây, được coi là\l"
    .string "những con POKéMON siêu cổ.\p"
    .string "Nhưng mà không chỉ có hai con POKéMON\n"
    .string "siêu cổ thôi đâu.\p"
    .string "Còn một con nữa ở đâu đó.\p"
    .string "Đâu đó, có một POKéMON siêu cổ\n"
	.string "tên là RAYQUAZA.\p"
    .string "Người ta nói là chính RAYQUAZA mới\n"
    .string "làm dịu cơn giận của hai vị chiến binh\l"
    .string "từ rất lâu đời kể về trước.\p"
	.string "Mà kể cả tui cũng không biết gì về\n"
    .string "nơi ở của RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "HẢI LY: {PLAYER}, có lẽ bạn sẽ biết\n"
	.string "nơi ở của RAYQUAZA mà đúng không?\p"
	.string "Nếu có, thì làm ơn cho tui biết.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "HẢI LY: HANG CỘI NGUỒN hả?\p"
	.string "Là ở đây mà!\n"
	.string "Tui cần bạn phải nỗ lực hơn nữa!\p"
	.string "Làm ơn đi, tui cần bạn nghĩ về cái\n"
	.string "nơi mà RAYQUAZA ở ngay bây giờ.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "HẢI LY: NÚI TIỄN ĐƯA?\p"
	.string "Mà hồi nãy tui có gặp một bà\n"
	.string "ở đó, bả đâu có nói gì đâu.\p"
	.string "Mà tui cũng ngờ ngợ là bả tính\n"
	.string "giấu cái gì đó với tui rồi…\p"
	.string "{PLAYER} ơi, bạn có thể nào suy\n"
	.string "nghĩ kỹ hơn giùm tui không?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "HẢI LY: Hả? Không nhớ hả?\n"
	.string "Hừm… Khó nha…\p"
	.string "Không nhớ ra được gì luôn hả?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "HẢI LY: CỘT TRỜI hả?\p"
	.string "Đúng rồi đó!\n"
	.string "Chắc chắn phải là CỘT TRỜI rồi!\p"
	.string "{PLAYER}, không cần phải chần chừ!\n"
	.string "Tụi tui hướng tới CỘT TRỜI thôi!$"

