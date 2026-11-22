Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Ông anh tui là người MÊ HOÁ THẠCH…\n"
	.string "Ổng rất hiền, và MÊ HOÁ THẠCH…\p"
	.string "Ổng cũng thích đào lỗ nữa…\n"
	.string "Ổng tự tay đào cái lỗ này nè…\p"
	.string "Cho bạn cái này để bạn ĐÀO\n"
	.string "được cái lỗ giống anh tui…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Nếu bạn cho POKéMON ĐÀO trong hang,\n"
	.string "bạn sẽ quay lại lối vô hang…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Những tảng đá có hình dáng\n"
    .string "kỳ lạ lấp đầy tủ trưng bày…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "CẤU TẠO CỦA CÁC TẦNG ĐỊA CHẤT…\n"
    .string "CÁCH MƯA ĐỊNH HÌNH ĐẤT…\l"
    .string "ĐÁ, ĐẤT VÀ ĐÁ NÚI…\p"
    .string "Chỗ để toàn sách không à.$"

