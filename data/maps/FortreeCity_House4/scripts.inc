FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Ở chung với POKéMON,\n"
	.string "người ta kết thân với nhau nhiều hơn.\p"
	.string "Điều đó làm cho thế giới gắn kết lại.\n"
	.string "Tui nghĩ điều đó thật tuyệt vời!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Bay đi!\n"
	.string "Hỡi POKéMON CHIM của ta!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Heheh, tui kêu con WINGULL\n"
	.string "phụ tui làm việc.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Tốt!\n"
	.string "Quay lại đây, WINGULL!\p"
	.string "Hở? Cái gì vậy cà?\n"
	.string "Nó đang cầm cái gì?\p"
	.string "THẢO DƯỢC hả?\n"
	.string "Chắc nó lụm ở đâu đó.\p"
	.string "Mà tui hổng phải NHL,\n"
	.string "bạn cầm lấy đi.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Nhờ WINGULL mà tui kết thân\n"
	.string "được với người ở phương xa.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pi hoo!$"

