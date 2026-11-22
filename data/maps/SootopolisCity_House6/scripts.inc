SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Xin chào! Bạn là vị khách đầu tiên\n"
	.string "sau một thời gian dài.\p"
	.string "Bạn làm tui vui mừng quá, nên tui sẽ cho\n"
	.string "bạn một con CÚP BẾ WAILMER thiệt bự.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Chăm sóc nó cho kỹ nha!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Ụa, muốn lấy, mà giờ chưa được hả?\n"
	.string "Vậy, để tui giữ giùm cho.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Bạn chắc chưa?\n"
	.string "Bạn hổng thích con CÚP BẾ này hả?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Tui rất thích THÚ NHỒI BÔNG!$"

